#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define CLOCK_FREQ 16000000U
#define PRESCALER 256
#define TICKS_PER_SEC (CLOCK_FREQ / PRESCALER)
#define MIN_PULSE_WIDTH 544
#define MAX_PULSE_WIDTH 2400

int servo1Pin = 11; // OC2A (PB3)
int servo2Pin = 3;  // OC2B (PD3)

int clip(int val, int min, int max)
{
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

int map(int val, int in_low, int in_high, int out_low, int out_high)
{
    val = clip(val, in_low, in_high);
    return out_low + (long)(out_high - out_low) * (val - in_low) / (in_high - in_low);
}

void servo_write_us(int pin, int micro_secs)
{
    // Map pulse width (us) to Timer2 OCRx value for given prescaler and clock
    int ticks = ((long)micro_secs * CLOCK_FREQ) / (1000000L * PRESCALER);

    if (pin == 11) { // D11 = OC2A = PB3
        OCR2A = clip(ticks, ((long)MIN_PULSE_WIDTH * CLOCK_FREQ) / (1000000L * PRESCALER), ((long)MAX_PULSE_WIDTH * CLOCK_FREQ) / (1000000L * PRESCALER));
    }
    else if (pin == 3) { // D3 = OC2B = PD3
        OCR2B = clip(ticks, ((long)MIN_PULSE_WIDTH * CLOCK_FREQ) / (1000000L * PRESCALER), ((long)MAX_PULSE_WIDTH * CLOCK_FREQ) / (1000000L * PRESCALER));
    }
}

void servo_write_angle(int pin, int angle)
{
    int pulse_us = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    servo_write_us(pin, pulse_us);
}

int main()
{
    // Set pins D11 (PB3/OC2A) and D3 (PD3/OC2B) as outputs
    DDRB |= (1 << PB3); // D11
    DDRD |= (1 << PD3); // D3

    // Set Phase Correct PWM mode: WGM20=1, WGM21=0, WGM22=0 for Timer2
    TCCR2A = (1 << COM2A1) | (1 << COM2B1) | (1 << WGM20);
    TCCR2B = (1 << CS22); // Prescaler 256 (CS22=1, CS21=0, CS20=0)

    while (1)
    {
        // Control using pulse width
        servo_write_us(servo1Pin, MIN_PULSE_WIDTH);
        servo_write_us(servo2Pin, MAX_PULSE_WIDTH);
        _delay_ms(1000);
        servo_write_us(servo1Pin, MAX_PULSE_WIDTH);
        servo_write_us(servo2Pin, MIN_PULSE_WIDTH);
        _delay_ms(1000);

        // Control using angle
        servo_write_angle(servo1Pin, 0);
        servo_write_angle(servo2Pin, 180);
        _delay_ms(1000);
        servo_write_angle(servo1Pin, 90);
        servo_write_angle(servo2Pin, 90);
        _delay_ms(1000);
        servo_write_angle(servo1Pin, 180);
        servo_write_angle(servo2Pin, 0);
        _delay_ms(1000);

        // Sweep
        for (int angle = 180; angle >= 0; angle--)
        {
            servo_write_angle(servo1Pin, angle);
            servo_write_angle(servo2Pin, 180 - angle);
            _delay_ms(10);
        }
        _delay_ms(500);
        for (int angle = 0; angle <= 180; angle++)
        {
            servo_write_angle(servo1Pin, angle);
            servo_write_angle(servo2Pin, 180 - angle);
            _delay_ms(10);
        }
        _delay_ms(500);
    }
}

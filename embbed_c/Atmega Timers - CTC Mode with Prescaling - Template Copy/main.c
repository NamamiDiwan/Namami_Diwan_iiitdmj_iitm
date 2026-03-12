// Arduino clock frequency is 16 MHz
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned int n_compare_matchs = 0;

ISR(TIMER2_COMPA_vect)
{
    // Toggle D12 on each interrupt (D12 is PB4)
    PORTB ^= (1 << PB4);

    // Every 125 interrupts (1 second), toggle D13 (PB5)
    n_compare_matchs++;
    if (n_compare_matchs >= 125) {
        PORTB ^= (1 << PB5);
        n_compare_matchs = 0;
    }
}

int main()
{
    // Set D12 (PB4) and D13 (PB5) as outputs
    DDRB |= (1 << PB4) | (1 << PB5);

    // Set Timer2 to CTC mode: WGM21 = 1, WGM20 = 0, WGM22 = 0
    TCCR2A |= (1 << WGM21);
    TCCR2A &= ~(1 << WGM20);
    TCCR2B &= ~(1 << WGM22);

    // Set compare value for ~1ms interrupt: OCR2A = 124
    OCR2A = 124;

    // Set prescaler to 1024: CS22=1, CS21=1, CS20=1
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

    // Enable Timer2 COMPA interrupt
    TIMSK2 |= (1 << OCIE2A);

    // Enable global interrupts
    sei();

    // Main loop does nothing, everything handled in ISR
    while (1) ;
}

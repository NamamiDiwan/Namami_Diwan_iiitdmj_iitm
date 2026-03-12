# Problem Statement: ATmega328P Timer - CTC with prescaling

## Objective

Use Timer2 on the ATmega328P microcontroller to toggle a LED connected to digital pin D13 at precise interval of 1 second. This is achieved by configuring Timer2 in **CTC (Clear Timer on Compare Match)** mode with a prescaler of 1024, allowing for LED toggling at precise intervals.

- **D12**: Toggle at each timer interrupt.
- **LED on D13**: Toggle every 1 second, which corresponds to every 125 interrupts.

## Calculating the Interval for Timer2 Compare Match

To determine the number of compare match that will occur in 1 seconds, 
we use the following parameters:

1. **Clock Frequency of ATmega328P**: 16 MHz (16,000,000 clock cycles per second)
2. **Prescaler for Timer2**: 1024 (each timer increment will require 1024 system clock cycles)
3. **Compare Match Value (OCR2A)**: 125-1 (Timer2 will reset every 125 timer increments in CTC mode)
4. 16*10^6/1024/125 = 125 compare match per seconds.

## Requirements

1. **Configure Timer2 in CTC mode**:
   - Set Timer2 to CTC mode to clear the timer on compare match.
   - Set the compare match value (OCR2A) to 124 to achieve the desired interrupt frequency.

2. **Set Timer2 Prescaler**:
   - Use a prescaler of 1024 to slow down the timer to an interrupt interval close to 1 ms.
   
3. **ISR (Interrupt Service Routine)**:
   - In the Timer2 compare match ISR:
     - Toggle D12 on each interrupt.
     - Increment an overflow counter and toggle the LED on D13 every 1 second (after 125 interrupts).
   
4. **Port and Pin Configurations**:
   - Set the appropriate data direction registers to configure pins D12 and D13 as outputs.

5. **Enable Global Interrupts**:
   - Enable global interrupts to allow the Timer2 ISR to execute.

## Constraints

- **Clock Frequency**: 16 MHz
- **Timer2**: 8-bit timer on ATmega328P

The program should achieve LED toggling without using any delay functions, 
relying entirely on Timer2's compare match interrupt for precise timing. 
This approach ensures that other operations in the main loop are unaffected by the timing requirements for the LEDs.

# Problem Statement: Create an LED Blink for Traffic Lights

**Objective:**
Write an Arduino program to simulate a traffic light system using three LEDs. 

1. The green LED should be on for 1 second
2. the yellow LED should be on for 0.2 seconds
3. and the red LED should be on for 1 second

in a continuous cycle.

**Requirements:**
1. Connect three LEDs to different digital pins on the Arduino 
(pin 11 for the red LED, pin 12 for the yellow LED, and pin 13 for the green LED).
2. Write the setup and loop functions to configure all three pins as outputs.
3. Implement the timing logic to control the intervals for each LED:
   - The green LED should be on for 1 second.
   - The yellow LED should be on for 0.2 seconds before the light turns red.
   - The red LED should be on for 1 second.
4. Ensure that the LEDs blink in the correct sequence (green, yellow, red) in a continuous loop.

**Constraints:**
- Do not use any external libraries.
- Ensure precise timing for each LED's interval.

**Hints:**
- Use the `digitalWrite` function to control the LEDs.
- Use the `delay` function to create the appropriate pauses between LED state changes.

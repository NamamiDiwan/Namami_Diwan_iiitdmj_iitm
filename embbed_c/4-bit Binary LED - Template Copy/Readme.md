## Problem Statement

Design and implement an Arduino program to create a 4-bit binary counter using LEDs, 
where each LED represents a bit in the counter that goes an entire cycle in 16 seconds.


### Requirements:
1. **LED Connections**: 
   - LED connected to pin 13 represents the MSB.
   - LED connected to pin 12 represents the second most significant bit.
   - LED connected to pin 11 represents the second least significant bit.
   - LED connected to pin 10 represents the LSB.
2. **Delays**: Each LED should toggle its state at a different interval:
   - LED on pin 13 toggles every 8 seconds.
   - LED on pin 12 toggles every 4 seconds.
   - LED on pin 11 toggles every 2 seconds.
   - LED on pin 10 toggles every 1 second.

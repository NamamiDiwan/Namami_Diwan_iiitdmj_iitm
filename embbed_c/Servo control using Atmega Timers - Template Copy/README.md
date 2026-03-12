# Arduino Servo Control using Timer2 PWM

## Objective

To implement timer based servo control with accurate angle measurement in Arduino using Atmega timers.

## Concepts Covered
- Timer2 configuration
- PWM signal generation for servo control
- Mapping values between different ranges
- Using `clip()` to constrain values

## Implementation Tasks
### Functions to Implement
1. **clip()**
   - Constrains a value within a given range.

2. **map()**
   - Maps an input value from one range to another, using `clip()`.

3. **servo_write_us()**
   - Generates a PWM signal for the given pin with a specified pulse width in microseconds.

4. **servo_write_angle()**
   - Converts an angle (0-180 degrees) to the corresponding pulse width and calls `servo_write_us()`.

### Timer2 Configuration
- Set **prescaler to 256**.
- Configure **Phase Correct PWM mode**.

### Pin Configuration
- **D11 and D3** are set as output to drive the servos.

## Expected output
1. The servos will move between predefined angles and pulse widths.
2. The program will run an automatic sweep motion to demonstrate smooth servo movement.
3. The oscilloscope will display the generated signal.


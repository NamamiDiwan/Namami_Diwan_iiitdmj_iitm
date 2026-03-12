### Problem Statement: Digital Blinking RGB LED Controller

**Objective:**

Design and implement a digital blinking RGB LED controller system using an STM32 microcontroller. The system should allow the user to change the color and blinking duration of the RGB LED using two buttons. The color and duration changes should be displayed via the serial monitor.

**Components:**
1. RGB LED connected to digital pins 13 (Red), 12 (Green), and 11 (Blue).
2. Two push buttons:
   - `colorBtn` connected to digital pin 6.
   - `durationBtn` connected to digital pin 7.
3. STM32 microcontroller.

**Functionality Requirements:**

1. **RGB LED Control:**
   - The RGB LED should blink with a specified color and duration.
   - The initial color of the LED should be white, and the initial duration should be 1000 ms.

2. **Button-Triggered Color Change:**
   - The `colorBtn` should cycle through predefined colors (white, red, green, blue, cyan, yellow, magenta).
   - The color should change each time the button is pressed and released.
   - The current color should be printed to the serial monitor in the format: `Color: <colorName>`.

3. **Button-Triggered Duration Change:**
   - The `durationBtn` should cycle through predefined durations (1000 ms, 800 ms, 600 ms, 400 ms, 200 ms).
   - The duration should change each time the button is pressed and released.
   - The current duration should be printed to the serial monitor in the format: `Duration: <duration> ms`.

4. **Timing and Interrupts:**
   - The system should use hardware interrupts to handle button presses for color and duration changes.
   - Debouncing should be handled to ensure reliable button press detection.
   - The RGB LED blinking should be controlled using a non-blocking approach with the `millis()` function to allow smooth operation and responsiveness to button presses.

### Notes:
- Ensure that the buttons are properly debounced to prevent multiple triggers on a single press.
- Modify the code as needed to suit your specific requirements and hardware setup.
- Ensure the serial monitor is open and set to 9600 baud rate to view the output.
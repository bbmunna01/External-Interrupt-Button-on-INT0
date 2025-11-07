In the breadboard, I connected an LED to a digital pin (D13) and other pin to GND and placed a button that one side pin is to D2 (INT0) and other pin to GND.
Here, the LED was controlled using the button. The button will interrupt the main task of Arduino. By pressing the button, it will do ISR at first then the main task.

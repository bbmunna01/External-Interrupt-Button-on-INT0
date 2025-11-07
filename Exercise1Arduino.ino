const int ledPin = 13; //PORTB5
const int buttonPin = 2; // INT0

volatile bool ledState = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // button to GND

  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, FALLING);
}

void loop() {
  digitalWrite(ledPin, ledState);
}

void toggleLED() {
  ledState = !ledState;
}
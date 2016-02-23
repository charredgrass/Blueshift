#include <Joystick.h>

void setup() {
  // Initialize Button Pins
  pinMode(0, INPUT_PULLUP); //Raise arm
  pinMode(1, INPUT_PULLUP); //Lower arm
  pinMode(2, INPUT_PULLUP); //Extend arm
  pinMode(3, INPUT_PULLUP); //Retract arm
  pinMode(4, INPUT_PULLUP); //Suck
  pinMode(5, INPUT_PULLUP); //launch
  pinMode(6, INPUT_PULLUP); //winch
  pinMode(7, INPUT_PULLUP); //release
  pinMode(8, INPUT_PULLUP); //missiles
  pinMode(9, INPUT_PULLUP); //launch init
  pinMode(10, INPUT_PULLUP); 
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Initializing Blueshift.");
  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 0;
const int numButts = 13;
// Last state of the button
int lastButtonState[numButts] = {0, 0, 0, 0};

void loop() {
  // Read pin values
  for (int index = 0; index < numButts; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  delay(50);
}

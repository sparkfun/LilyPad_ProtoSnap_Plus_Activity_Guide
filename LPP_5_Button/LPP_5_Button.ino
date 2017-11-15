/*
LilyPad ProtoSnap Plus Activity 5: Switch and Button Input
SparkFun Electronics
https://www.sparkfun.com/products/14346

Explore digital input and program flow control using the button and switch

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#5-switch-and-button-input

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create integer variables for the pins we'll be using

int buttonpin = A4;
int switchpin = A9;

int buttonLED = A5;
int switchLED = A8;

void setup()
{
  // Initialize the button and switch pins as inputs with pullups.
  // Pullups keep the inputs from "floating" when a switch or button is open / unpressed.

  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(switchpin, INPUT_PULLUP);

  // Initialize the LED pins as outputs:

  pinMode(buttonLED, OUTPUT);
  pinMode(switchLED, OUTPUT);
}

void loop()
{
  // This code will read the positions of the button and switch,
  // then use the "if" command to make LEDs follow these states.
  
  // Create variables to store the button and switch input values:

  int buttonstate;
  int switchstate;

  // Read and save the states of the button and switch:

  buttonstate = digitalRead(buttonpin);
  switchstate = digitalRead(switchpin);

  // The if-else statement lets you do different things based on different inputs:

  if (buttonstate == LOW) // The button will read as LOW when it's pressed
  {
    digitalWrite(buttonLED,HIGH); // If pressed, turn on the LED
  }
  else
  {
    digitalWrite(buttonLED,LOW); // If not pressed, turn off the LED
  }

  if (switchstate == LOW) // The switch will read as LOW when it's pressed
  {
    digitalWrite(switchLED,HIGH); // If the switch is on, turn on the LED
  }
  else
  {
    digitalWrite(switchLED,LOW); // If the switch is off, turn off the LED
  }
}


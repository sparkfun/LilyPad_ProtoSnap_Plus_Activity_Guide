/*
LilyPad ProtoSnap Plus Activity 6: Buttons and Switches
SparkFun Electronics
https://www.sparkfun.com/products/14346

Explore digital input and program flow control using the button and switch

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#6-buttons-and-switches

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

  // The button will read as LOW when it's pressed

  if (buttonstate == LOW) // Check to see if buttonstate is LOW (pressed) 
  {
    digitalWrite(buttonLED,HIGH); // If buttonstate is LOW (pressed), turn on the LED
  }
  else
  {
    digitalWrite(buttonLED,LOW); // If buttonstate is HIGH (unpressed), turn off the LED
  }

  if (switchstate == LOW) // Check to see if switchstate is LOW (switch is on)
  {
    digitalWrite(switchLED,HIGH); // If switchstate is LOW (on), turn on the LED
  }
  else
  {
    digitalWrite(switchLED,LOW); // If switchstate is HIGH (off), turn off the LED
  }
}


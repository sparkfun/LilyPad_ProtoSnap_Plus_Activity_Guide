/*
LilyPad ProtoSnap Plus Activity 9: Theremin
SparkFun Electronics
https://www.sparkfun.com/products/14346

A Theremin is an electronic musical instrument that is played by
moving your hands over it. In this activity we'll create a Theremin
using the light sensor and the buzzer.

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#9-theremin-project

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create variables for the pins we'll be using

int sensorpin = A2;
int buttonpin = A4;
int buzzer = A3;
int bargraphLED[6] = {15,16,17,18,19,20};

// Set the highest and lowest frequencies
// (Change these and see what happens)

int highestfrequency = 1047; // C6
int lowestfrequency = 523; // C5

void setup()
{
  int x;

  // Initialize the pins we'll be using
  
  pinMode(sensorpin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  
  for (x = 0; x <= 5; x++)
  {
    pinMode(bargraphLED[x],OUTPUT);
  }

  // Initialize the serial monitor

  Serial.begin(9600);
}

void loop()
{
  int sensorreading;
  int frequency;

  // Read the sensor value (will be 0 to 255):

  sensorreading = analogRead(sensorpin);

  // Print out the sensor reading:

  Serial.print("sensor value: ");
  Serial.println(sensorreading);

  // Display the sensor reading on the bar graph LEDs:

  barGraph(sensorreading);

  // Play a tone based on the light level:

  // The light sensor will return a value from 0 to 255,
  // but we want to play frequencies that are higher than that.
  // We'll use a built-in fuction called "map" that transforms one range
  // of values (0 to 255) to another (lowestfrequency to highestfrequency):

  frequency = map(sensorreading,0,255,lowestfrequency,highestfrequency);

  if (digitalRead(buttonpin) == LOW)
  {
    tone(buzzer,frequency);
  }
  else
  {
    noTone(buzzer);
  }
}

void barGraph(int value)
{
  // Create a LED bargraph using value as an input.
  // Value should be in the range 0 to 255.

  int x;
  
  // Step through the bargraph LEDs,
  // Turn them on or off depending on value.

  // Value will be in the range 0 to 255.
  // There are 6 LEDs in the bargraph.
  // 255 divided by 6 is 42, so 42 will be our threshold
  // between each LED (0,42,84, etc.)

  for (x=0; x <= 5; x++)
  {
    if (value > (x*42) )
    {
      digitalWrite(bargraphLED[x],HIGH);
    }
    else
    {
      digitalWrite(bargraphLED[x],LOW);
    }    
  }
}


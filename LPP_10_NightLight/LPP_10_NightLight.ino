/*
LilyPad ProtoSnap Plus Activity 10: Twinkling Night Light
SparkFun Electronics
https://www.sparkfun.com/products/14346

Create a twinkling night light that turns on when it gets dark.

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#10-twinkling-night-light-project

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create variables for the pins we'll be using:

int lightsensor = A2;

// Array of all the LEDs we'll be twinkling. You can set these to the sewtabs
// you'll be using in your project. Remember to only choose outputs that
// have the "~" symbol that are compatible with analogWrite.

int numLEDs = 3;
int LED[9] = {6,A7,A8};

int blueLED = 14;

// Threshold for light level (when it's darker than this, twinkle LEDs)

int threshold = 50;

void setup()
{
  int x;

  // Initialize the pins we'll be using
  
  pinMode(lightsensor, INPUT);

  for (x = 0; x <= numLEDs; x++)
  {
    pinMode(LED[x],OUTPUT);
  }

  pinMode(blueLED,OUTPUT);

  // Initialize the serial monitor

  Serial.begin(9600);
}

void loop()
{
  int x,lightlevel,brightness;

  // Read the sensor value (will be 0 to 255):

  lightlevel = analogRead(lightsensor);

  // Print out the sensor reading:

  Serial.print("light level: ");
  Serial.print(lightlevel);
  Serial.print(" threshold: ");
  Serial.print(threshold);
  Serial.print(" twinkle: ");

  // If the light level is below the threshold, twinkle LEDs:

  if (lightlevel < threshold)
  {
    Serial.println("ON");
    analogWrite(blueLED,10);
    
    // Pick a random LED:
    
    x = random(numLEDs);

    // Quickly ramp up the brightness of the LED from off to on:

    for (brightness = 0; brightness <= 255; brightness = brightness + 1)
    {
      analogWrite(LED[x],brightness);
      delay(1);
    }

    // Quickly ramp down the brightness of the LED from on to off:
    
    for (brightness = 255; brightness >= 0; brightness = brightness - 1)
    {
      analogWrite(LED[x],brightness);
      delay(1);
    }
    analogWrite(LED[x],0);

    // Wait a random amount of time (up to 2 seconds)

    delay(random(2000));
  }
  else
  {
    Serial.println("off");
    analogWrite(blueLED,128);
  }
}



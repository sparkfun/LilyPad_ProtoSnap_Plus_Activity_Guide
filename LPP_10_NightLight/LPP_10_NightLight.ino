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

// Array of all the LEDs we'll be using. You can set these to the sewtabs
// you'll be using in your project. Remember to only choose outputs that
// have the "~" symbol, that are compatible with analogWrite.

int numLEDs = 9;
int LED[9] = {6,A7,A8,15,16,17,18,19,20};

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
    
    // Pick a random LED:
    
    x = random(numLEDs);

    // Quickly ramp up the brightness of the LED from off to on:

    for (brightness = 0; brightness <= 255; brightness++)
    {
      analogWrite(LED[x],brightness);
      delay(1);
    }

    // Quickly ramp down the brightness of the LED from on to off:
    
    for (brightness = 255; brightness >= 0; brightness--)
    {
      analogWrite(LED[x],brightness);
      delay(1);
    }

    // Wait a random amount of time (up to 10 seconds)

    delay(random(10000));
  }
  else
  {
    Serial.println("off");
  }
}



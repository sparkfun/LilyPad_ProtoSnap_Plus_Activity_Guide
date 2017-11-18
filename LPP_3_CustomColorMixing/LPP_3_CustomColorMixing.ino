/*
LilyPad ProtoSnap Plus Activity 3: Custom Color Mixing
SparkFun Electronics
https://www.sparkfun.com/products/14346

Expand your color options using analogWrite and the RGB (Red Green Blue) LED

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#3-custom-color-mixing

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// The LilyPad USB Plus has a built-in RGB (Red / Green / Blue) LED.
// In this activity we'll use analogWrite to control the brightness of the three LEDs.
// Here we'll create a rainbow of tertiary colors by adding a 50%-brightness option.

// Create integer variables for our LED pins:

// The built-in LED:

int RGBredpin = 12;
int RGBgreenpin = 13;
int RGBbluepin = 14;

// The colored LEDs along the bottom edge of the board:

int redpin = 6;
int greenpin = A7;
int bluepin = A8;

void setup() {

// Make all of our LED pins outputs:

  pinMode(RGBredpin, OUTPUT);
  pinMode(RGBgreenpin, OUTPUT);
  pinMode(RGBbluepin, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
}

void loop()
{
  // In this code we'll step through twelve rainbow colors (primary, secondary, tertiary).

  // Unlike digitalWrite, which can be only HIGH (on) or LOW (off),
  // analogWrite lets you smoothly change the brightness from 0 (off) to 255 (fully on).
  // When analogWrite is used with the RGB LED, you can create millions of colors!

  // In the analogWrite functions:
  // 0 is off
  // 128 is halfway on (used for the tertiary colors)
  // 255 is full brigthness.
  
  // Red

  analogWrite(RGBredpin,255);
  analogWrite(RGBgreenpin,0);
  analogWrite(RGBbluepin,0);

  analogWrite(redpin,255);
  analogWrite(greenpin,0);
  analogWrite(bluepin,0);
  delay(1000);

  // Orange

  analogWrite(RGBredpin,255);
  analogWrite(RGBgreenpin,128);
  analogWrite(RGBbluepin,0);

  analogWrite(redpin,255);
  analogWrite(greenpin,128);
  analogWrite(bluepin,0);
  delay(1000);

  // Yellow

  analogWrite(RGBredpin,255);
  analogWrite(RGBgreenpin,255);
  analogWrite(RGBbluepin,0);

  analogWrite(redpin,255);
  analogWrite(greenpin,255);
  analogWrite(bluepin,0);
  delay(1000);

  // Chartruese

  analogWrite(RGBredpin,128);
  analogWrite(RGBgreenpin,255);
  analogWrite(RGBbluepin,0);

  analogWrite(redpin,128);
  analogWrite(greenpin,255);
  analogWrite(bluepin,0);
  delay(1000);

  // Green

  analogWrite(RGBredpin,0);
  analogWrite(RGBgreenpin,255);
  analogWrite(RGBbluepin,0);

  analogWrite(redpin,0);
  analogWrite(greenpin,255);
  analogWrite(bluepin,0);
  delay(1000);

  // Spring Green

  analogWrite(RGBredpin,0);
  analogWrite(RGBgreenpin,255);
  analogWrite(RGBbluepin,128);

  analogWrite(redpin,0);
  analogWrite(greenpin,255);
  analogWrite(bluepin,128);
  delay(1000);

  // Cyan

  analogWrite(RGBredpin,0);
  analogWrite(RGBgreenpin,255);
  analogWrite(RGBbluepin,255);

  analogWrite(redpin,0);
  analogWrite(greenpin,255);
  analogWrite(bluepin,255);
  delay(1000);

  // Azure

  analogWrite(RGBredpin,0);
  analogWrite(RGBgreenpin,128);
  analogWrite(RGBbluepin,255);

  analogWrite(redpin,0);
  analogWrite(greenpin,128);
  analogWrite(bluepin,255);
  delay(1000);

  // Blue

  analogWrite(RGBredpin,0);
  analogWrite(RGBgreenpin,0);
  analogWrite(RGBbluepin,255);

  analogWrite(redpin,0);
  analogWrite(greenpin,0);
  analogWrite(bluepin,255);
  delay(1000);

  // Violet

  analogWrite(RGBredpin,128);
  analogWrite(RGBgreenpin,0);
  analogWrite(RGBbluepin,255);

  analogWrite(redpin,128);
  analogWrite(greenpin,0);
  analogWrite(bluepin,255);
  delay(1000);

  // Magenta
  
  analogWrite(RGBredpin,255);
  analogWrite(RGBgreenpin,0);
  analogWrite(RGBbluepin,255);

  analogWrite(redpin,255);
  analogWrite(greenpin,0);
  analogWrite(bluepin,255);
  delay(1000);

  // Rose
  
  analogWrite(RGBredpin,255);
  analogWrite(RGBgreenpin,0);
  analogWrite(RGBbluepin,128);
  
  analogWrite(redpin,255);
  analogWrite(greenpin,0);
  analogWrite(bluepin,128);
  delay(1000);

}

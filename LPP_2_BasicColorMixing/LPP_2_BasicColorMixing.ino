/*
LilyPad ProtoSnap Plus Activity 2: Basic Color Mixing
SparkFun Electronics
https://www.sparkfun.com/products/14346

Create primary and secondary colors on the built-in RGB (Red/Green/Blue) LED

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#2-basic-color-mixing

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// The LilyPad USB Plus has a built-in RGB (Red / Green / Blue) LED.
// In this activity we'll use digitalWrite to tun the three LEDs on and off
// in various combinations to create eight primary and secondary colors.

// Create integer variables for our LED pins:

// The built-in LED:

int RGBredpin = 12;
int RGBgreenpin = 13;
int RGBbluepin = 14;

// The colored LEDs along the bottom edge of the board:

int redpin = 6;
int greenpin = A7;
int bluepin = A8;

void setup()
{
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

  // This code will step through the six primary and secondary colors, plus white and black.
  
  // For each of these colors, we'll turn the necessary RGB LEDs on or off.
  // We'll also turn on the same LEDs on the bottom edge, so you can see what's being mixed.

  // Black (all LEDs off)

  // RGB LEDs:
  
  digitalWrite(RGBredpin,LOW);
  digitalWrite(RGBgreenpin,LOW);
  digitalWrite(RGBbluepin,LOW);

  // Bottom-edge LEDs
  
  digitalWrite(redpin,LOW);
  digitalWrite(greenpin,LOW);
  digitalWrite(bluepin,LOW);
  delay(1000);

  // Red (red LED on)

  digitalWrite(RGBredpin,HIGH);
  digitalWrite(RGBgreenpin,LOW);
  digitalWrite(RGBbluepin,LOW);
  
  digitalWrite(redpin,HIGH);
  digitalWrite(greenpin,LOW);
  digitalWrite(bluepin,LOW);
  delay(1000);

  // Yellow (red and green LEDs on)

  digitalWrite(RGBredpin,HIGH);
  digitalWrite(RGBgreenpin,HIGH);
  digitalWrite(RGBbluepin,LOW);
  
  digitalWrite(redpin,HIGH);
  digitalWrite(greenpin,HIGH);
  digitalWrite(bluepin,LOW);
  delay(1000);

  // Green (green LED on)

  digitalWrite(RGBredpin,LOW);
  digitalWrite(RGBgreenpin,HIGH);
  digitalWrite(RGBbluepin,LOW);
  
  digitalWrite(redpin,LOW);
  digitalWrite(greenpin,HIGH);
  digitalWrite(bluepin,LOW);
  delay(1000);

  // Cyan (blue and green LEDs on)

  digitalWrite(RGBredpin,LOW);
  digitalWrite(RGBgreenpin,HIGH);
  digitalWrite(RGBbluepin,HIGH);
  
  digitalWrite(redpin,LOW);
  digitalWrite(greenpin,HIGH);
  digitalWrite(bluepin,HIGH);
  delay(1000);

  // Blue (blue LED on)

  digitalWrite(RGBredpin,LOW);
  digitalWrite(RGBgreenpin,LOW);
  digitalWrite(RGBbluepin,HIGH);
  
  digitalWrite(redpin,LOW);
  digitalWrite(greenpin,LOW);
  digitalWrite(bluepin,HIGH);
  delay(1000);

  // Magenta (red and blue LEDs on)

  digitalWrite(RGBredpin,HIGH);
  digitalWrite(RGBgreenpin,LOW);
  digitalWrite(RGBbluepin,HIGH);
  
  digitalWrite(redpin,HIGH);
  digitalWrite(greenpin,LOW);
  digitalWrite(bluepin,HIGH);
  delay(1000);

  // White (all LEDs on)

  digitalWrite(RGBredpin,HIGH);
  digitalWrite(RGBgreenpin,HIGH);
  digitalWrite(RGBbluepin,HIGH);
  
  digitalWrite(redpin,HIGH);
  digitalWrite(greenpin,HIGH);
  digitalWrite(bluepin,HIGH);
  delay(1000);
}

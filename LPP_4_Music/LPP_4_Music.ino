/*
LilyPad ProtoSnap Plus Activity 4: Making Music
SparkFun Electronics
https://www.sparkfun.com/products/14346

Play musical notes through the buzzer on the LilyPad ProtoSnap Plus

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#4-making-music

Uses frequencies from "melody" by Tom Igoe: https://www.arduino.cc/en/Tutorial/toneMelody

This code is released under the MIT License: (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create an integer variable naming the pin we'll use for the buzzer.
// On the ProtoSnap Plus, it's on A3.

int buzzerpin = A3;

// Map musical notes to their frequencies by creating variables for them.
// You can find the frequencies for higher and lower notes at: https://www.arduino.cc/en/Tutorial/toneMelody

int NOTE_C5 = 523;
int NOTE_CS5 = 554;
int NOTE_D5 = 587;
int NOTE_DS5 = 622;
int NOTE_E5 = 659;
int NOTE_F5 = 698;
int NOTE_FS5 = 740;
int NOTE_G5 = 784;
int NOTE_GS5 = 831;
int NOTE_A5 = 880;
int NOTE_AS5 = 932;
int NOTE_B5 = 988;
int NOTE_C6 = 1047;

// We'll also create a variable for how long to play each note in milliseconds.
// If you make this smaller, the notes will play faster.

int speed = 500;

void setup()
{
  // Set the buzzer pin to be an output:
  
  pinMode(buzzerpin, OUTPUT);
}

void loop()
{
  // This code will play a simple scale from C5 to C6.

  // The tone command takes two parameters: a pin number and a frequency.
  // The tone will play until we stop it with the noTone command.
  // Each of the below blocks plays one note; the note plays during the delay command.
  
  tone(buzzerpin,NOTE_C5);
  delay(speed);
  noTone(buzzerpin);

  tone(buzzerpin,NOTE_D5);
  delay(speed);
  noTone(buzzerpin);

  tone(buzzerpin,NOTE_E5);
  delay(speed);
  noTone(buzzerpin);

  tone(buzzerpin,NOTE_F5);
  delay(speed);
  noTone(buzzerpin);

  tone(buzzerpin,NOTE_G5);
  delay(speed);
  noTone(buzzerpin);

  tone(buzzerpin,NOTE_A5);
  delay(speed);
  noTone(buzzerpin);

  tone(buzzerpin,NOTE_B5);
  delay(speed);
  noTone(buzzerpin);

  tone(buzzerpin,NOTE_C6);
  delay(speed);
  noTone(buzzerpin);

  // A longer delay at the end pauses the sound before looping again.
  // Here we're taking the speed value and multiplying it by four:

  delay(speed * 4);

  // Try writing your own song using the noted defined at the top of the program!
}

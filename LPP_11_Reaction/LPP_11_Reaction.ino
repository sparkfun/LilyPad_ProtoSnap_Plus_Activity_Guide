/*
LilyPad ProtoSnap Plus Activity 11: Reaction Timer
SparkFun Electronics
https://www.sparkfun.com/products/14346

Create a reaction timer game

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#10-twinkling-night-light-project

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create variables for the pins we'll be using:

// Array of the bar graph LEDs:

int bargraphLED[6] = {15,16,17,18,19,20};

int redLED = 14;
int greenLED = 13;

int buttonpin = A4;

void setup()
{
  int x;

  // Initialize the pins we'll be using
  
  pinMode(buttonpin, INPUT);

  for (x = 0; x <= 5; x++)
  {
    pinMode(bargraphLED[x],OUTPUT);
  }

  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);

  // Initialize the serial monitor

  Serial.begin(9600);
}

void loop()
{
  int start, end, reactiontime;

  // Get ready, get set...

  digitalWrite(greenLED,HIGH);  // green

  delay(1000);
  
  digitalWrite(greenLED,HIGH);  // red + green = yellow
  digitalWrite(redLED,HIGH);

  delay(1000);
  
  digitalWrite(greenLED,LOW);
  digitalWrite(redLED,LOW);
  
  delay(1000);

  delay(random(5000));

  digitalWrite(redLED,HIGH);
  start = millis();

  if (digitalRead(buttonpin) == HIGH) // not pressed
  {
    ; // do nothing  
  }

  end = millis();

  reactiontime = end - start;

  Serial.print("reaction time: ");
  Serial.print(reactiontime);
  Serial.println(" milliseconds");

  // Map the reaction time into 0 to 255 so we can use
  // our bargraph function (below)
  
  barGraph(map(reactiontime,0,300,0,255));

  // Wait for another button press to start again
  
  if (digitalRead(buttonpin) == HIGH) // not pressed
  {
    ; // do nothing  
  }

  // Clear out the bargraph
  
  barGraph(0);
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


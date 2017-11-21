/*
LilyPad ProtoSnap Plus Activity 11: Reaction Timer
SparkFun Electronics
https://www.sparkfun.com/products/14346

Create a reaction timer game

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#11-reaction-timer-project

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create variables for the pins we'll be using:

// Array of the bar graph LEDs:

int bargraphLED[6] = {15,16,17,18,19,20};

int redLED = 12;
int greenLED = 13;

int buttonpin = A4;

void setup()
{
  int x;

  // Initialize the pins we'll be using
  
  pinMode(buttonpin, INPUT_PULLUP);

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
  int starttime, endtime, reactiontime;

  // Get ready, get set...

  analogWrite(greenLED,25);  // green

  delay(1000);
  
  analogWrite(redLED,75);  // red + green = yellow

  delay(1000);
  
  analogWrite(greenLED,0);
  analogWrite(redLED,0);
  
  delay(1000);

  delay(random(4000));

  analogWrite(redLED,75);
  starttime = millis();

  while (digitalRead(buttonpin) == HIGH) // not pressed
  {
    ; // do nothing  
  }
  analogWrite(redLED,0);
  endtime = millis();

  reactiontime = endtime - starttime;

  Serial.print("reaction time: ");
  Serial.print(reactiontime);
  Serial.println(" milliseconds");

  // Map the reaction time into 0 to 255 so we can use
  // our bargraph function (below)
  
  barGraph(constrain(map(reactiontime,0,600,0,255),0,255));

  // Wait for another button press to start again

  delay(1000);
  while (digitalRead(buttonpin) == HIGH) // not pressed
  {
    ; // do nothing
  }

  // Clear out the bargraph
  
  barGraph(0);
  delay(1000);
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


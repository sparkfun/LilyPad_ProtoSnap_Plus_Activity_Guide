/*
LilyPad ProtoSnap Plus Activity 6: Reading the Light Sensor
SparkFun Electronics
https://www.sparkfun.com/products/14346

Explore analog input from the light sensor

Follow the tutorial at: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide#6-reading-the-light-sensor

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create a variable for the pin we'll use:

int sensorpin = A2;

// The six white LEDs on the LilyPad USB Plus are numbered 15 through 20
// To make them easier to use, we'll put those numbers into a matrix:

int bargraphLED[6] = {15,16,17,18,19,20};

// The matrix is indexed from 0 to 5; for example bargraphLED[2] = 17

void setup()
{
  int x;

  // Initialize the sensor pin as an input, but without a pullup
  // (Pullups are only used for switch inputs)
  
  pinMode(sensorpin, INPUT);

  // Initialize the bargraph LED pins as outputs
  // We'll use the matrix we defined above,
  // where the LEDs are indexed from 0 to 5

  for (x = 0; x <= 5; x++)
  {
    pinMode(bargraphLED[x],OUTPUT);
  }

  // Initialize the serial monitor

  Serial.begin(9600);
}

void loop()
{
  int x,sensorreading;

  // Read the sensor value (will be 0 to 255):

  sensorreading = analogRead(sensorpin);

  // Print out the sensor reading:

  Serial.print("sensor value: ");
  Serial.println(sensorreading);

  // Step through the bargraph LEDs,
  // Turn on or off depending on the sensor reading

  // sensorreading will be in the range 0 to 255
  // there are 6 LEDs in the bargraph
  // 255 divided by 6 is 42

  for (x=0; x <= 5; x++)
  {
    if (sensorreading > (x*42) )
    {
      digitalWrite(bargraphLED[x],HIGH);
    }
    else
    {
      digitalWrite(bargraphLED[x],LOW);
    }    
  }
}


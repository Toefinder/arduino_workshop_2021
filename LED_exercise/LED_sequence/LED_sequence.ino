//Flowing LED Lights

/*
  Eight LEDs will light up one by one from left to right, and then go out one by
  one from right to left.

  After
  that, the LEDs will light up one by one from right to left, and then go out one
  by one from left to right.

  This
  process will repeat indefinitely.*

  /Email:info@primerobotics.in

  //Website:www.primerobotics.in

  /**************************************/

const int lowestPin = 2;//the lowest one attach to

const int highestPin = 9;//the highest one attach to

byte pinArray[] = {2, 3, 4, 5, 6, 7, 8, 10};
int pinArraySize = sizeof(pinArray);
int thisPin;
char incomingByte = 'n'; // for incoming serial data
/**************************************/

void setup()
{
  //set pins in the pin array as input
  for (int pinIndex = 0; pinIndex <= 8; pinIndex++)
  {
    thisPin = pinArray[pinIndex];
    pinMode(thisPin, OUTPUT); //initialize thisPin as an output
  }

  Serial.begin(9600);
  Serial.println("Enter 'n' for normal mode, 'r' for reverse");
}

/****************************************/

void loop()
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    if ((incomingByte != 'n') && (incomingByte != 'r')) {
      incomingByte = 'n';
    }
    Serial.print("Mode: ");
    Serial.println(incomingByte);
  }
  if (incomingByte == 'r') {
    //turn the led on from lowest to the highest and back
    for (int pinIndex = pinArraySize-1; pinIndex >= 0; pinIndex--)
    {
      thisPin = pinArray[pinIndex];
      digitalWrite(thisPin, HIGH); //turn this led on
      delay(100);//wait for 100 ms
    }
  
    //fade from the highest to the lowest
    for (int pinIndex = pinArraySize-1; pinIndex >= 0; pinIndex--)
    {
      thisPin = pinArray[pinIndex];
      digitalWrite(thisPin, LOW); //turn this led off
      delay(100);//wait for 100 ms
    }
  } else {
  //turn the led on from lowest to the highest and back
    for (int pinIndex = 0; pinIndex < pinArraySize; pinIndex++)
    {
      thisPin = pinArray[pinIndex];
      digitalWrite(thisPin, HIGH); //turn this led on
      delay(100);//wait for 100 ms
    }
  
    //fade from the highest to the lowest
    for (int pinIndex = 0; pinIndex < pinArraySize; pinIndex++)
    {
      thisPin = pinArray[pinIndex];
      digitalWrite(thisPin, LOW); //turn this led off
      delay(100);//wait for 100 ms
    }
  }
}

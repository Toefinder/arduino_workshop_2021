#define trigPin 9
#define echoPin 8
#define led 3

void setup()
{ 
  //Initialise Serial Monitor
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.println("Ultrasonic Sensor HC-SR04 and LED\n"); // print some text in Serial Monitor
  Serial.println("Proxi Warning\n");
  Serial.println("with Arduino UNO R3");
}

void loop()
{ 
  //Declare variables
  long duration, distance;
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  if (distance < 50 && distance > 30)
  {
    digitalWrite(led,HIGH);
    delay(200);
    digitalWrite(led,LOW);
    delay(200);
  }
  else if (distance < 30)
  {
      digitalWrite(led,HIGH);
      delay(50);
      digitalWrite(led,LOW);
      delay(50);
  }
  else 
  {
    digitalWrite(led,LOW);
  }
  Serial.print(distance);
  Serial.println(" cm");
  delay(20);
}

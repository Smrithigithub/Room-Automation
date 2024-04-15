const int trigPin1 = 7;
const int echoPin1 = 6;
int count1=0;
const int fixed=20; //fixed no. of people
int count2;
const int led1=3;
const int led2=8;
const int led3=9;
const int led4=10;

// Define the pins for the second ultrasonic sensor
const int trigPin2 = 5;
const int echoPin2 = 4;

void setup() {
  // Set the trigger pins as outputs
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  
  // Set the echo pins as inputs
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Measure distance for the first sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  long duration1 = pulseIn(echoPin1, HIGH);
  int distance1 = duration1 / 58;
  

  // Measure distance for the second sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 / 58;

  // Print the distances to the serial monitor
  

  //led part
  if(distance1==20)
  {
    digitalWrite(led1,HIGH);
    count1++;
  }
  else
  {
    digitalWrite(led1,LOW);
  }
  if(count1>0)
  {
      digitalWrite(led2,HIGH);
  }
  else
  {
    digitalWrite(led2,LOW);
  }
  if(count1==10)
  {
    count2=count1;
  }
  if(distance2==20)
  {
    digitalWrite(led3,HIGH);
    count2--;
  }
  else
  {
    digitalWrite(led3,LOW);
  }
   if(count2<0)
   {
    digitalWrite(led4,HIGH);
    digitalWrite(led2,LOW);
   }
   else
   {
    digitalWrite(led4,LOW);
    
   }
   
   
  Serial.print(" Distance 1: ");
  Serial.print(distance1);
  Serial.print(" Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  Serial.print(" Count1: ");
  Serial.print(count1);
  Serial.print(" Count2: ");
  Serial.print(count2);

  // Wait for a short time before measuring again
  delay(100);
}
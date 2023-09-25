#include <SoftwareSerial.h>
#include<Servo.h>
//SoftwareSerial BT (A0, A1);
Servo myservo1;
Servo myservo2;

int pos1=0;
int pos2=180;

//int motor_r2 = 6;
//int motor_r1 = 7;
//
//int motor_l2 = 8;
//int motor_l1 = 9;


int data, state;

void setup()
{
  myservo1.attach(4);
  myservo2.attach(3);
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
//  BT.begin(9600); // Setting the baud rate of Software Serial Library 
  delay(1000);
}


void loop()
{
  data = 0;
  //if some date is sent, reads it and saves in state
  if(Serial.available()>0)
    {
      data=Serial.read();
      Serial.print(data);
    }
    delay(500);


for (pos1=0;pos1<=30;pos1++){
  myservo1.write(pos1); 
  delay(40);
  }
  for(pos2=180;pos2>=150;pos2--){
  myservo2.write(pos2);
  delay(40);
  }
  for (pos1=30;pos1<=60;pos1++){
  myservo1.write(pos1);
  delay(40);
  }
  for(pos2=150;pos2>=120;pos2--){
  myservo2.write(pos2);




  delay(40);
  }
  for (pos1=60;pos1<=90;pos1++){
  myservo1.write(pos1);
  delay(40);
  }
  for(pos2=120;pos2>=90;pos2--){
    myservo2.write(pos2);
  delay(40);
  }
  delay(3000);
 for(pos1=90;pos1>=60;pos1--){
  myservo1.write(pos1);
  delay(40);
 }
 for(pos2=90;pos2<=120;pos2++){
  myservo2.write(pos2);
  delay(40);
 }
 for(pos1=60;pos1>=30;pos1--){
  myservo1.write(pos1);
  delay(40);
 }
 for(pos2=120;pos2<=150;pos2++){
  myservo2.write(pos2);
  delay(40);
 }for(pos1=30;pos1>=0;pos1--){
  myservo1.write(pos1);
  delay(40);
 }
  //if(BT.available() > 0){     
  //state = BT.read(); 
  //Serial.println(state);

  
  switch(data)  
  {
    case 49: forward(); break;
    case 50: turnRight(); break;
    case 51: turnLeft(); break;
    case 52: backward(); break;
    case 53: s_top(); break;
  }
  delay(500);

}

void forward(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);  
  Serial.println("forward");
}

void backward(){
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}


void turnRight(){
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void turnLeft(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}

void s_top(){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
}

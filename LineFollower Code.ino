#include <SoftwareSerial.h>
const int L_S = A5;  // sensor output for left sensor
const int R_S = A4;  // sensor output for right sensor
// Motor driver pins
const int ENB = 5; // motor 2 
const int IN4 = 6; // motor 2 left
const int IN3 = 7; // motor 2 left
const int IN2 = 3; // motor 1  right
const int IN1 = 9; // motor 1  right
const int ENA = 10; // motor 1 

void setup() {
  pinMode(L_S, INPUT);
  pinMode(R_S, INPUT);
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop() {
  int left = analogRead(L_S);
  int right = analogRead(R_S);

  //if Right Sensor and Left Sensor are at White color then it will call forword function
  if(left > 500 && right > 600){Stop();}
  //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
  else if(left > 500){turnLeft();}
  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
  else if(right > 500){turnRight();} 
  //if Right Sensor and Left Sensor are at Black color then it will call Stop function
  else {forword();}     
}

void forword(){  //forword
  digitalWrite(IN1, HIGH); //Right Motor forword Pin 
  digitalWrite(IN2, LOW);  //Right Motor backword Pin 
  digitalWrite(IN3, HIGH);  //Left Motor backword Pin 
  digitalWrite(IN4, LOW); //Left Motor forword Pin 
  analogWrite(ENA, 60);
  analogWrite(ENB, 60);
}
void backword(){ //backword
  digitalWrite(IN1, LOW);  //Right Motor forword Pin 
  digitalWrite(IN2, HIGH); //Right Motor backword Pin 
  digitalWrite(IN3, HIGH); //Left Motor backword Pin 
  digitalWrite(IN4, LOW);  //Left Motor forword Pin
  analogWrite(ENA, 60);
  analogWrite(ENB, 60); 
}
void turnRight(){ //turnRight
  digitalWrite(IN1, LOW);  //Right Motor forword Pin 
  digitalWrite(IN2, HIGH); //Right Motor backword Pin  
  digitalWrite(IN3, HIGH);  //Left Motor backword Pin 
  digitalWrite(IN4, LOW); //Left Motor forword Pin 
  analogWrite(ENA, 65);
  analogWrite(ENB, 55);
} 
void turnLeft(){ //turnLeft
  digitalWrite(IN1, HIGH); //Right Motor forword Pin 
  digitalWrite(IN2, LOW);  //Right Motor backword Pin 
  digitalWrite(IN3, LOW); //Left Motor backword Pin 
  digitalWrite(IN4, HIGH);  //Left Motor forword Pin
  analogWrite(ENA, 55);
  analogWrite(ENB, 65);
}
void Stop(){ //stop
  digitalWrite(IN1, LOW); //Right Motor forword Pin 
  digitalWrite(IN2, LOW); //Right Motor backword Pin 
  digitalWrite(IN3, LOW); //Left Motor backword Pin 
  digitalWrite(IN4, LOW); //Left Motor forword Pin 
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

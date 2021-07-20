  
#include <Servo.h>
#include<LiquidCrystal.h>
//define Pin numbers 
int trigPin = 9;
int echoPin = 8;
//Create servo object to control a servo
Servo S7;
Servo S6;
Servo S10;
Servo S13;
Servo S14;
Servo S15;
//LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT);
 Serial.begin(9600); //Strarts the serial communication
  S7.attach(7);//attach the servo to the pin 
  S6.attach(6);//attach the servo to the pin 
  S10.attach(10);//attach the servo to the pin 
  S13.attach(13);
  S14.attach(14);
  S15.attach(15);
  lcd.begin(16,2);
  
  //define intial postions for all motors
  S6.write(0);//intial pos
  S7.write(0);//intial pos
  S10.write(0);//intial pos
  S13.write(0);//intial pos
  S14.write(0);//intial pos
  S15.write(0);//intial pos
  
}//end void setup 
 


void loop(){

  //prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(calc_dis());
  if(calc_dis() <= 10){//motion#1
    S7.write(90);
    S6.write(90);
    S10.write(90);
    S13.write(90);
    S14.write(90);
    S15.write(90);
    delay(1000);
    lcd.setCursor(2,1);
    lcd.print("Hey near:)");
    
  }
  else if(calc_dis() <= 50){//motion#2
   delay(1000);
   S7.write(180);
   S6.write(180);
   S10.write(180); 
   S13.write(180);
   S14.write(180); 
   S15.write(180); 
   lcd.setCursor(2,1);
   lcd.print("Hey there:|"); 
  }
  else if(calc_dis() <= 100){//motion#3
   delay(1000);
   S7.write(0);
   S6.write(0);
   S10.write(0); 
   S13.write(0);
   S14.write(0); 
   S15.write(0); 
   lcd.setCursor(2,1);
   lcd.print("Hey far:("); 
    
    
  }
  
  lcd.setCursor(0,0);
  lcd.print("distance = ");
  lcd.print(calc_dis());
  
  
 
  
  
}//end void loop

//functions:)
int calc_dis(){
  
  int duration, distance;//define var
  digitalWrite(trigPin, LOW);//clear the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance; 
}

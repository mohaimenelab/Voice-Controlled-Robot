
#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

void displayinfo ();
void stopmotor ();
void motorcontrol ();
void buzzercontrol ();
void overweight ();

int trigpin = 19;    // PA2
int echopin = 18;    // PA3
long duration;
int distance;
int weight;

void setup() 
{
  
 pinMode(trigpin,OUTPUT);
 pinMode(echopin,INPUT);
 
 pinMode(28,OUTPUT);  //PC6--BUZZER
 
 pinMode(2,OUTPUT); //IN1
 pinMode(3,OUTPUT); //IN2------go to motor controller
 pinMode(30,OUTPUT);  //IN3
 pinMode(8,OUTPUT); //IN4

 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(30, LOW);
 digitalWrite(8, LOW);

 
 pinMode(10,INPUT);  //PB4
 pinMode(11,INPUT);  //PB5
 pinMode(12,INPUT);  //PB6----come from receiver IC
 pinMode(13,INPUT);  //PB7
 
 lcd.begin(20, 4);
 lcd.setCursor (0, 1);
 lcd.print("Starting....");
 delay(2000);
 lcd.setCursor (0, 1);
 lcd.print("                    ");  

}

void loop()
{
  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin,HIGH);
  distance = duration * 0.034/2 ;
  
  weight = analogRead(20);    // PA1 -- PRESSURE SENSOR
  
  if(weight >= 800)
  {
   stopmotor ();
   buzzercontrol ();
   overweight ();
  }
  
  else
  {   
    if ( distance <= 20 )
    {
      lcd.setCursor (0, 0);
      lcd.print("                    ");
      lcd.setCursor (0, 1);
      lcd.print("                    ");
      lcd.setCursor (0, 2);
      lcd.print(" Track is not clear ");
      lcd.setCursor (0, 3);
      lcd.print("                    ");
      digitalWrite(28, HIGH);
      delay(1000);
      digitalWrite(28, LOW);
      delay(5000);  
    }
    
    else
    {
      displayinfo ();
    }
    
     motorcontrol ();
    
  }

}  

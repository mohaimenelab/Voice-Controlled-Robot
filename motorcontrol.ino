
void motorcontrol ()
{
 
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigpin,LOW);

 duration = pulseIn(echopin,HIGH);
 distance = duration * 0.034/2 ;
 
 
 int p = digitalRead(10);
 int q = digitalRead(11);
 int r = digitalRead(12);
 int s = digitalRead(13);  


 if( p == 1 && q == 0 && r == 0 && s == 0)
 {

    if ( distance <= 20 )
    {
      stopmotor ();
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
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(30,HIGH);
      digitalWrite(8,LOW);
    }
  
 }
 
 
 else if( p == 0 && q == 1 && r == 0 && s == 0 )
 {
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(30,LOW);
 }
 
 else if( p == 0 && q == 0 && r == 1 && s == 0 )
 {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(30,LOW);
  digitalWrite(8,LOW);
 }
 else if( p == 0 && q == 0 && r == 0 && s == 1 )
 {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(30,HIGH);
  digitalWrite(8,LOW);
 }
else if( p == 0 && q == 0 && r == 0 && s == 0 )
{
  stopmotor ();
}
else if( p == 1 && q == 1 && r == 1 && s == 1 )
{
  stopmotor ();
}
 
}


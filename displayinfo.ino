void displayinfo ()
{
  
  lcd.setCursor (0, 0);
  lcd.print(" Name : Wall-e Bot  ");
  lcd.setCursor (0, 1);
  lcd.print(" Institute: Dhaka   ");
  lcd.setCursor (0, 2);
  lcd.print("Int.University (CSE)");
  lcd.setCursor (0, 3);
  lcd.print(" BAT Status :");
  
  int x = analogRead(21);   // PA0--BATTERY LEVEL
  x = map(x,682,920,0,100); 
  
  if(x >= 100)
  {
   lcd.setCursor (14, 3);
   lcd.print(" 100%  ");
  }
   
  else
  {
   lcd.setCursor (12, 3);
   lcd.print("   ");
   lcd.setCursor (15, 3);
   lcd.print(x);
   lcd.setCursor (17, 3);
   lcd.print("%  ");
  }
  
}


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int IRSensor1 = 2;
int IRSensor2 = 3; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13
int RELAY_PIN=8;
int statusSensor2;
int statusSensor1;


void setup() 
{

      lcd.init();                      // initialize the lcd 
    lcd.backlight();
      lcd.clear();
      lcd.print("Hello Welcome");
      delay(10000);

 pinMode(RELAY_PIN, OUTPUT);
  pinMode (IRSensor1, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
  pinMode (IRSensor2, INPUT); // sensor pin INPUT
}

void loop()
{
  statusSensor1 = digitalRead (IRSensor1);
  
  if (statusSensor1 == 1)
  {
    digitalWrite(LED, LOW); // LED LOW
    digitalWrite(RELAY_PIN, HIGH);
    lcd.clear();
      lcd.print("person came left");
  }
  

  else
  {
   {
   statusSensor2 = digitalRead (IRSensor2);
     if (statusSensor2 == 1)
    digitalWrite(LED, LOW); // LED LOW
    digitalWrite(RELAY_PIN, LOW);
    lcd.clear();
        lcd.print("person came in");}
    
  }
  }

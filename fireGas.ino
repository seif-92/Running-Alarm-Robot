# Running-Alarm-Robot
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define flame 3
#define buzzer 5
#define smoke A0
int Val = 0;
int sensorValue;


void loop()
{
  
  Val = digitalRead(flame);
  if (Val == LOW) {
  digitalWrite(buzzer, LOW);
  Val=0;
    lcd.setCursor(0,0);

  lcd.print("value of flame:");
  lcd.println(Val);

  }
  else {
  digitalWrite(buzzer, HIGH);
  Val=1;
    lcd.setCursor(0,0);

  lcd.print("value of flame:");
  lcd.println(Val);

    sensorValue = analogRead(smoke);
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    if(sensorValue > 300)
    {
    lcd.print(" | Smoke detected!");
    lcd.println(sensorValue);

    digitalWrite(buzzer,HIGH);
    }
    else
    {
    digitalWrite(buzzer,LOW);
    lcd.print("Sensor Value: ");
    lcd.println(sensorValue);
    }
    delay(2000);
      }


 
}
void setup()
{
  lcd.begin(16, 2);
  lcd.init();    
  lcd.setCursor(0,0);
                  
  lcd.backlight();
  



  pinMode(flame , INPUT);
  pinMode(buzzer,OUTPUT);
  
}

// C++ code
//

#include <LiquidCrystal.h>

int buzzerPin = 2;
int redPin = 10;
int greenPin = 12;
int bluePin = 11;

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
const int contrast = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  analogWrite(contrast, 100);
  lcd.begin(16, 2);
}

void loop()
{
   lcd.setCursor(0, 0);
   lcd.print("Light Status:");
   int light = analogRead(A0);
   Serial.println(light);
   
  
  if (light <= 200) {
  	digitalWrite(redPin, 252);
    digitalWrite(greenPin, 252);
    digitalWrite(bluePin, 252);
	lcd.setCursor(0,1);
    lcd.print("Dark:Needs Light");
  }
  
  if (light > 200 && light < 600)
  {
  	digitalWrite(redPin, 0);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
    lcd.setCursor(0,1);
    lcd.print("Normal              ");
  }
  
  if (light >= 600) {
    digitalWrite(redPin, 252);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
    lcd.setCursor(0,1);
    lcd.print("DANGER: TOO MUCH LIGHT");
  	tone(buzzerPin, 1000);
    delay(1000);
    noTone(buzzerPin);
    delay(1000);
    
  }
}
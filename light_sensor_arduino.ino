// C++ code
//

int buzzerPin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
   int light = analogRead(A0);
   Serial.println(light);
  
  if (light <= 200) {
    
  }
  
  if (light >= 600) {
    tone(buzzerPin, 1000);
    delay(1000);
    noTone(buzzerPin);
    delay(1000);
  }
}

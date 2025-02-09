void setup()
{
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
}

void loop()
{
  static uint32_t timer = millis();
  if (digitalRead(7) == 1 & millis() - timer >= 1000){
  	Serial.println("Next Track");
  }
  else if (digitalRead(8) == 1 & millis() - timer >= 1000){
    Serial.println("Pause");
  }
  else if (digitalRead(9) == 1 & millis() - timer >= 1000){
    Serial.println("Previous Track");
  }
}
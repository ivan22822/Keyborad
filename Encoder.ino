#include <EncButton.h>

/* Пины энкодера */
#define ENC_DT 5
#define ENC_CK 6
#define ENC_SW 4

/* Обьекты энкодера и декодера */
EncButton enc(ENC_DT, ENC_CK, ENC_SW);
void setup() {
  Serial.begin(9600);
  EICRA |= FALLING << 2;        // Настраиваем режим прерывания INT1 (FALLING)
  EIMSK |= 1 << INT1;           // Активируем прерывание INT1 

}

void loop() {
  enc.tick();               // Тикер энкодера
  if (enc.left())       Serial.println("Volume down");
  if (enc.right())      Serial.println("Volume up");
  if (enc.hasClicks(1)) Serial.println("Mute");
}

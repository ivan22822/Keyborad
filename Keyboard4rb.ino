#include <EasyHID.h>
#include <EncButton.h>

/* Пины энкодера */
#define ENC_DT 5
#define ENC_CK 6
#define ENC_SW 4

/* Обьекты энкодера и декодера */
EncButton enc(ENC_DT, ENC_CK, ENC_SW);
void setup() {
  HID.begin();      // Инициализация USB
  pinMode(9, INPUT);      //предыдущий трек                
  pinMode(8, INPUT);      //паузы
  pinMode(7, INPUT);      //следующий трек
  EICRA |= FALLING << 2;        // Настраиваем режим прерывания INT1 (FALLING)
  EIMSK |= 1 << INT1;           // Активируем прерывание INT1 
}


void loop() {
  HID.tick();               // Тикер HID
  enc.tick();               // Тикер энкодера
  static uint32_t timer = millis();
  /* Отслеживание энкодера и выдача команд */
  if (enc.left())       Keyboard.clickMultimediaKey(KEY_VOL_DOWN);
  if (enc.right())      Keyboard.clickMultimediaKey(KEY_VOL_UP);
  if (enc.hasClicks(1)) Keyboard.clickMultimediaKey(KEY_MUTE);

  if (digitalRead(9) == 1 & millis() - timer >= 1000){
    timer = millis();
    Keyboard.clickMultimediaKey(KEY_PREV_TRACK);
  } 
  if (digitalRead(8) == 1 & millis() - timer >= 1000){
    timer = millis();
    Keyboard.clickMultimediaKey(KEY_PLAYPAUSE);
  }
  if (digitalRead(7) == 1 & millis() - timer >= 1000){
    timer = millis();
    Keyboard.clickMultimediaKey(KEY_NEXT_TRACK);
  }

}

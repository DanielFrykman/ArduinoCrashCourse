//made by: Daniel Lilja Frykman
#include <U8g2lib.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, D1, D2, U8X8_PIN_NONE);

void OLEDsetup() {
  u8g2.begin();
}

void OLED(const char* input) {
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(0, 10, input); // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
}

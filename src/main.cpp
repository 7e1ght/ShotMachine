#include <Arduino.h>

#include <UTFT.h>
#include <URTouch.h>

#include "config/config.h"

UTFT screen(display::DISPLAY_MODEL, display::RS_PIN, display::WR_PIN, display::CS_PIN, display::RST_PIN);
URTouch touch(touchscreen::TCLK_PIN, touchscreen::TCS_PIN, touchscreen::TDIN_PIN, touchscreen::DOUT_PIN, touchscreen::IRQ_PIN);

extern uint8_t SmallFont[];

void setup()
{
  Serial.begin(9600);

  screen.InitLCD();
  screen.clrScr();
  screen.setFont(SmallFont);

  touch.InitTouch();
  touch.setPrecision(PREC_MEDIUM);

}

void loop()
{
}
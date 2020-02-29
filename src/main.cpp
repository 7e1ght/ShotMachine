#include <Arduino.h>

#include <UTFT.h>
#include <URTouch.h>

#include "config/config.h"

UTFT screen(cfg::display::DISPLAY_MODEL, cfg::display::RS_PIN, cfg::display::WR_PIN, cfg::display::CS_PIN, cfg::display::RST_PIN);
URTouch touch(cfg::touchscreen::TCLK_PIN, cfg::touchscreen::TCS_PIN, cfg::touchscreen::TDIN_PIN, cfg::touchscreen::DOUT_PIN, cfg::touchscreen::IRQ_PIN);

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
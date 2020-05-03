#include <Arduino.h>

#include "config/config.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Bottle.hpp"
#include "bar/Cocktail.hpp"
#include "bar/Liquid.hpp"

#include "bar/Barman.hpp"

#include "bar/GlassScanner.hpp"

#include "scenes/MainScene.hpp"

#include "support/TouchScreen.hpp"

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void setup()
{
  Serial.begin(9600);

  Barman::getInstance().addOrder(1, 0);

  Serial.println( Barman::getInstance().isLiquidEnough(Liquid::VODKA, 10) );

  Serial.println( freeRam() );
}

void loop()
{
  // supp::Point p = TouchScreen::getInstance().getTouch();
  // dbg::printPoint(p);

  // mainScene->doLoop( p );
}
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

#include <Stepper.h>

#include "support/Hand.hpp"

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

MainScene* mainScene;

void setup()
{
  Serial.begin(9600);

  // Hand::getInstance().moveHandTo(Barman::getInstance().getGlasses()[1]);


  // pinMode(cfg::hand::ENABLE_DISABLE_PIN, OUTPUT);
  // digitalWrite(cfg::hand::ENABLE_DISABLE_PIN, HIGH);

  // delay(5000);

  // Glass glass = Barman::getInstanrce().getGlasses()[1];

  // Serial.println(glass.getId());

  // Hand::getInstance().moveHandTo(glass);

  // mainScene = new MainScene();

  // mainScene->renderScene();


  Serial.println( freeRam() );
}

void loop()
{
  Serial.println( Barman::getInstance().getNextGlassId() );

  // supp::Point p = TouchScreen::getInstance().getTouch();
  // dbg::printPoint(p);

  // mainScene->doLoop( p );
}
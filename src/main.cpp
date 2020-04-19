#include <Arduino.h>

#include "config/config.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Bottle.hpp"
#include "bar/Cocktail.hpp"
#include "bar/Liquid.hpp"

#include "bar/Barman.hpp"

void initShotMap()
{
  Cocktail water("Water");

  water.addStep(20, Bottle(35, Liquid::VODA));
  water.addStep(100, Bottle(37, Liquid::VODA));
  water.addStep(30, Bottle(39, Liquid::VODA));
  water.addStep(50, Bottle(41, Liquid::NO_LIQUID));
  water.addStep(10, Bottle(43, Liquid::NO_LIQUID));

  supp::shotMap.push_back(water);

  Cocktail water2("Vlad");

  water2.addStep(20, Bottle(49, Liquid::VODA));
  water2.addStep(100, Bottle(47, Liquid::VODA));
  water2.addStep(30, Bottle(45, Liquid::VODA));
  water2.addStep(50, Bottle(43, Liquid::NO_LIQUID));
  water2.addStep(10, Bottle(41, Liquid::NO_LIQUID));

  supp::shotMap.push_back(water2);
}

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void setup()
{
  Serial.begin(9600);

  initShotMap();

  for(int i = 0; supp::shotMap.size() > i; ++i)
  {
    Serial.println( supp::shotMap[i].getName() );
    supp::shotMap[i].makeCocktail();
  }
  
  Serial.println( freeRam() );
}

void loop()
{
  // digitalWrite(15, LOW);
  // delay(2);
  // digitalWrite(15, HIGH);
  // delay(100);
  // digitalWrite(15, LOW);

  // int d = pulseIn(14, HIGH);

  // Serial.println(d);
}
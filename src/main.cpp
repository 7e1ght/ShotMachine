#include <Arduino.h>

#include "config/config.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Bottle.hpp"
#include "bar/Cocktail.hpp"
#include "bar/Liquid.hpp"

#include "bar/Barman.hpp"

#include "bar/GlassScanner.hpp"

inline void water() noexcept
{
  Cocktail water("Water");

  water.addStep(20, Bottle(35, Liquid::VODA));
  water.addStep(100, Bottle(37, Liquid::VODA));
  water.addStep(30, Bottle(39, Liquid::VODA));
  water.addStep(50, Bottle(41, Liquid::NO_LIQUID));
  water.addStep(10, Bottle(43, Liquid::NO_LIQUID));

  supp::shotMap.push_back(water);
}

inline void vlad() noexcept
{
  Cocktail water2("Vlad");

  water2.addStep(20, Bottle(49, Liquid::VODA));
  water2.addStep(100, Bottle(47, Liquid::VODA));
  water2.addStep(30, Bottle(45, Liquid::VODA));
  water2.addStep(50, Bottle(43, Liquid::NO_LIQUID));
  water2.addStep(10, Bottle(41, Liquid::NO_LIQUID));

  supp::shotMap.push_back(water2);
}

void initShotMap() noexcept
{
  water();
  vlad();
}

void initGlass() noexcept
{
  supp::allGlass.push_back( Glass(15, 14) );
  supp::allGlass.push_back( Glass(17, 16) );
  supp::allGlass.push_back( Glass(19, 18) );
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
  initGlass();

  // for(int i = 0; i < supp::allGlass.size(); ++i)
  // {
  //   supp::allGlass[i].update();
  // }

  // for(int i = 0; i < supp::allGlass.size(); ++i)
  // {
  //   Serial.println( supp::allGlass[i].getAvaiable() );
  // }

  GlassScanner::update();

  Barman::getInstance().addOrder(supp::allGlass[0], supp::shotMap[0]);
  Barman::getInstance().addOrder(supp::allGlass[0], supp::shotMap[1]);
  Barman::getInstance().addOrder(supp::allGlass[1], supp::shotMap[1]);
  
  Barman::getInstance().executeOrder();
  
  Serial.println( freeRam() );
}

void loop()
{
}
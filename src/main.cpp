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

inline void water() noexcept
{
  Cocktail water("Water");

  water.addStep(20, Bottle(35, Liquid::VODA));
  water.addStep(100, Bottle(37, Liquid::VODA));
  water.addStep(30, Bottle(39, Liquid::VODA));
  water.addStep(50, Bottle(41, Liquid::VODKA));
  water.addStep(10, Bottle(43, Liquid::VODKA));

  Barman::shotMap.push_back(water);
}

inline void vlad() noexcept
{
  Cocktail water2("Vlad");

  water2.addStep(30, Bottle(49, Liquid::VODA));
  water2.addStep(110, Bottle(47, Liquid::VODA));
  water2.addStep(40, Bottle(45, Liquid::VODA));
  water2.addStep(60, Bottle(43, Liquid::VODKA));
  water2.addStep(20, Bottle(41, Liquid::VODKA));

  Barman::shotMap.push_back(water2);
}

inline void die() noexcept
{
  Cocktail d("Die");

  d.addStep(999, Bottle(49, Liquid::VODKA));
  d.addStep(999, Bottle(47, Liquid::VODKA));
  d.addStep(999, Bottle(45, Liquid::VODKA));
  d.addStep(999, Bottle(43, Liquid::VODKA));
  d.addStep(999, Bottle(41, Liquid::VODKA));

  Barman::shotMap.push_back(d);
}

void initShotMap() noexcept
{
  water();
  vlad();
  die();
}

void initGlass() noexcept
{
  Barman::allGlass.push_back( Glass(15, 14) );
  Barman::allGlass.push_back( Glass(17, 16) );
  Barman::allGlass.push_back( Glass(19, 18) );
}

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

  initShotMap();
  // initGlass();

  // for(int i = 0; i < supp::allGlass.size(); ++i)
  // {
  //   supp::allGlass[i].update();
  // }

  // for(int i = 0; i < supp::allGlass.size(); ++i)
  // {
  //   Serial.println( supp::allGlass[i].getAvaiable() );
  // }

  // GlassScanner::update();

  // Barman::getInstance().addOrder(supp::allGlass[0], supp::shotMap[0]);
  // Barman::getInstance().addOrder(supp::allGlass[0], supp::shotMap[1]);
  // Barman::getInstance().addOrder(supp::allGlass[1], supp::shotMap[1]);
  
  // Barman::getInstance().executeOrder();

  mainScene = new MainScene;
  mainScene->renderScene();
  
  Serial.println( Barman::shotMap[0].getName() );

  Serial.println( freeRam() );
}

void loop()
{
  supp::Point p = TouchScreen::getInstance().getTouch();
  dbg::printPoint(p);

  mainScene->doLoop( p );
}
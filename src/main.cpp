#include <Arduino.h>

#include "config/config.hpp"
#include "support/Vector.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"

#include "support/Screen.hpp"
#include "support/TouchScreen.hpp"

#include "support/debug.hpp"

#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"

#include "scenes/MainScene.hpp"
#include "scenes/NewTemplate.hpp"

#include "support/Counter.hpp"
#include "bar/Glass.hpp"
#include "bar/Bottle.hpp"

IScene* mainScene;
IScene* newTemplate;

ListContainer* tc;

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

const int trig = 46;
const int echo = 47;

void setup()
{
  Serial.begin(9600);

  // mainScene = new MainScene();
  // mainScene->renderScene();

  Serial.println(freeRam());

  Bottle b(47, Liquid::NO_LIQUID);

  b.pour(100);
}

void loop()
{



}
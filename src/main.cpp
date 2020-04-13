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

#include "support/Wrapper.hpp"

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

EmptyContainer* ec;
TextContainer* tc;

void setup()
{
  Serial.begin(9600);

  ec = new EmptyContainer({0, 50}, {240, 25}, supp::DEFAULT_BG_LIGHT_COLOR);
  tc = new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR);

  ec->addContainer( tc, IContainerBase::POSITION_CENTER );

  ec->draw();

  Serial.println(freeRam());

  delay(2000);

  delete ec;

  Serial.println(freeRam());
}

void loop()
{
}
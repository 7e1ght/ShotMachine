#include <Arduino.h>

#include "config/config.hpp"
#include "support/ListedMap.hpp"
#include "support/Vector.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"
#include "containers/test_func.hpp"

#include "support/Screen.hpp"
#include "support/TouchScreen.hpp"

#include "support/debug.hpp"

EmptyContainer* ec;

ButtonContainer* headerButton;
ButtonContainer* centerButton;
ButtonContainer* bottomButton;

TextContainer* tc;

void setup()
{
    Serial.begin(9600);
    
}

void loop()
{
    supp::Point touchPoint = TouchScreen::getInstance().getTouch();
    dbg::printPoint(touchPoint);
    ec->handleTouch(touchPoint);
}
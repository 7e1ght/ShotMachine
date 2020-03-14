#include <Arduino.h>

#include "config/config.hpp"
#include "support/ListedMap.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"
#include "containers/test_func.hpp"

#include "support/Screen.hpp"
#include "support/TouchScreen.hpp"

#include "support/debug.hpp"

EmptyContainer* ec;

void setup()
{
    Serial.begin(9600);

    ec = new EmptyContainer({0, 0}, {50, 50}, supp::DEFAULT_BG_LIGHT_COLOR);
    ec->draw();
}

void loop()
{
    supp::Point touchPoint = TouchScreen::getInstance().getTouch();
    dbg::printPoint(touchPoint);
}
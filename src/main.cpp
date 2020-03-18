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

using Vpint = supp::Vector<uint8_t*>;

Vpint vpint;

void setup()
{
    Serial.begin(9600);

    tc = new TextContainer("Vlad", {50, 50}, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR);

    tc->draw();
}

void loop()
{
    // supp::Point touchPoint = TouchScreen::getInstance().getTouch();
    // dbg::printPoint(touchPoint);
    // ec->handleTouch(touchPoint);

    delay(2000);
    tc->setText("lox");
    
}
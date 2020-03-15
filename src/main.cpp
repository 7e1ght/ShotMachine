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

Vector<int> vint;

void setup()
{
    Serial.begin(9600);

    // ec = new EmptyContainer ({10, 192}, {220, 90}, supp::DEFAULT_BG_LIGHT_COLOR);

    // tc = new TextContainer("X", {0, 0}, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_LIGHT_COLOR);

    // ec->addContainer(tc, IContainerBase::POSITION_CENTER);

    // ec->draw();

    vint.push_back(1);
    vint.push_back(2);
    vint.push_back(3);
    vint.push_back(4);
    vint.push_back(5);
    vint.push_back(6);
}

void loop()
{
    // supp::Point touchPoint = TouchScreen::getInstance().getTouch();
    // dbg::printPoint(touchPoint);
    // ec->handleTouch(touchPoint);
}
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
ButtonContainer* minus;
ButtonContainer* plus;
TextContainer* number;

int counter = 0;
void setup()
{
    Serial.begin(9600);

    ec = new EmptyContainer(supp::Point(50, 50), supp::Size(100, 100), supp::DEFAULT_BG_LIGHT_COLOR);

    number = new TextContainer("0", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, ec->getMainColor());

    auto plusFunc = 
    [=]()
    {
        int currentNumber = atoi(number->getText().c_str());
        Serial.println(currentNumber);
        number->setText( String(currentNumber+10) );
    };

    auto minusFunc = 
    [=]()
    {
        int currentNumber = atoi(number->getText().c_str());
        Serial.println(currentNumber);
        number->setText( String(currentNumber-10) );
    };

    minus = new ButtonContainer("-", minusFunc, supp::NO_POSITION, supp::Size(25), ec->getMainColor());
    plus = new ButtonContainer("+", plusFunc, supp::NO_POSITION, supp::Size(25), ec->getMainColor());

    ec->addContainer(minus, IContainerBase::POSITION_LEFT);
    ec->addContainer(number, IContainerBase::POSITION_CENTER);
    ec->addContainer(plus, IContainerBase::POSITION_RIGHT);
    
    ec->draw();
}

void loop()
{
    supp::Point touchPoint = TouchScreen::getInstance().getTouch();
    delay(100);
    dbg::printPoint(touchPoint);
    ec->handleTouch( touchPoint );
}
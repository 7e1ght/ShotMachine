#include <Arduino.h>

#include "config/config.hpp"
#include "support/Vector.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"

#include "support/Screen.hpp"
#include "support/TouchScreen.hpp"

#include "support/debug.hpp"

#include "windows/TestWindow.hpp"
#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"

EmptyContainer* ec1;
EmptyContainer* ec2;
EmptyContainer* ec3;
EmptyContainer* ec4;

ButtonContainer* headerButton;
ButtonContainer* centerButton;
ButtonContainer* bottomButton;

TextContainer* tc1;
TextContainer* tc2;

TripleContainer* tc;

ListContainer* lc;

void setup()
{
    Serial.begin(9600);

    
    // tc = new TripleContainer({0, 100}, {240, 25}, supp::DEFAULT_BG_LIGHT_COLOR);

    tc1 = new TextContainer( "Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR );
    // headerButton = new ButtonContainer("x", [](){ Serial.println("Tap"); }, supp::NO_POSITION, {20, 20}, supp::DEFAULT_BG_LIGHT_COLOR);

    // ec1 = new EmptyContainer({50, 50}, {80, 50}, {255, 0, 0});
    // ec2 = new EmptyContainer(supp::NO_POSITION, {80, 25}, {0, 255, 0});
    // ec3 = new EmptyContainer(supp::NO_POSITION, {80, 25}, {0, 0, 255});

    // ec4 = new EmptyContainer({0, 0}, supp::FULLSCREEN, supp::DEFAULT_BG_LIGHT_COLOR);

    // tc->setLeft(ec1);
    // tc->setMiddle(ec2);
    // tc->setRight(ec3);

    // ec4->addContainer(tc, IContainerBase::POSITION_CENTER);
    // ec4->draw();

    // delay(1000);
    // ec2->setMainColor({255, 255, 0});

    lc = new ListContainer(2, {0, 50}, {100, 100}, supp::DEFAULT_BG_LIGHT_COLOR);

    lc->addItem(tc1);

    lc->draw();
}

void loop()
{
    // supp::Point tp = TouchScreen::getInstance().getTouch();
    // tc->handleTouch(tp);
}
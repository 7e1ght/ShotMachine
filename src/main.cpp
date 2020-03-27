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

void setup()
{
    Serial.begin(9600);

    
    tc = new TripleContainer({0, 100}, {240, 25}, supp::DEFAULT_BG_DARK_COLOR);

    tc1 = new TextContainer( "Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR );
    headerButton = new ButtonContainer("x", [](){ Serial.println("Tap"); }, supp::NO_POSITION, {20, 20}, supp::DEFAULT_BG_LIGHT_COLOR);

    ec1 = new EmptyContainer({50, 50}, {80, 50}, {255, 0, 0});
    ec2 = new EmptyContainer(supp::NO_POSITION, {80, 25}, {0, 255, 0});
    ec3 = new EmptyContainer(supp::NO_POSITION, {80, 25}, {0, 0, 255});

    tc->setLeft(ec1);
    tc->setMiddle(ec2);
    tc->setRight(ec3);

    tc->draw();

    delay(5000);
    ec2->setMainColor({255, 255, 0});

    tc->setPosition({0, 200});
}

void loop()
{
    // supp::Point tp = TouchScreen::getInstance().getTouch();
    // tc->handleTouch(tp);
}
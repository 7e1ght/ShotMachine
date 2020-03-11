#include <Arduino.h>

#include "config/config.hpp"
#include "support/ListedMap.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"

#include "support/Screen.hpp"
#include "support/TouchScreen.hpp"

#include "support/debug.hpp"

TextContainer* tc;
EmptyContainer* ec;
EmptyContainer* ec2;

void setup()
{
    Serial.begin(9600);
    
    tc = new TextContainer("Vlad", {50, 50}, supp::calcTextSize("Vlad"), supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR);
    ec = new EmptyContainer({50, 50}, {cfg::display::SCREEN_WIDTH, cfg::display::SCREEN_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
    ec2 = new EmptyContainer({100, 100}, {50, 50}, supp::DEFAULT_BG_LIGHT_COLOR);

    ec2->addContainer(tc);
    ec->addContainer(ec2);
    ec->draw();
}

void loop()
{
    ec->handleTouch(
        TouchScreen::getInstance().getTouch()
    );
}
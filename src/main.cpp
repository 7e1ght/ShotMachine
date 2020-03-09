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

void setup()
{
    Serial.begin(9600);
    
    tc = new TextContainer("Vlad", {50, 50}, supp::calcTextSize("Vlad"));
    ec = new EmptyContainer({0, 0}, {cfg::display::SCREEN_WIDTH, cfg::display::SCREEN_HEIGHT});

    ec->addContainer(tc);
}

void loop()
{
    ec->draw();
}
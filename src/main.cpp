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

void setup()
{
    Serial.begin(9600);

    EmptyContainer ec(supp::Point(0, 0), supp::Size(cfg::display::SCREEN_WIDTH, cfg::display::SCREEN_HEIGHT), supp::DEFAULT_BG_DARK_COLOR);
    ButtonContainer bc("x", [](){}, supp::NO_POSITION, supp::Size(100, 50), supp::DEFAULT_BG_LIGHT_COLOR);

    ec.addContainer(&bc, IContainerBase::POSITION_CENTER);
    ec.draw();
}

void loop()
{
}
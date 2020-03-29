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


ListContainer::Item* item1;
ListContainer::Item* item2;
ListContainer::Item* item3;
ListContainer::Item* item4;
ListContainer::Item* item5;

void setup()
{
    Serial.begin(9600);

    tc1 = new TextContainer( "Vlad", {0, 0}, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR );

    ec1 = new EmptyContainer(supp::NO_POSITION, {65, 30}, {255, 0, 0});
    ec2 = new EmptyContainer(supp::NO_POSITION, {65, 30}, {0, 255, 0});
    ec3 = new EmptyContainer(supp::NO_POSITION, {65, 30}, {0, 0, 255});

    ec4 = new EmptyContainer(supp::Point(0), supp::FULLSCREEN, supp::DEFAULT_BG_LIGHT_COLOR);
    ec4->draw();

    lc = new ListContainer(2, {0, 50}, {240, 100}, ec4->getMainColor());

    tc = new TripleContainer({0, 100}, {240, 50}, supp::DEFAULT_BG_LIGHT_COLOR);

    headerButton = new ButtonContainer("x", [](){ Serial.println("Vlad"); }, supp::NO_POSITION, {65, 30}, supp::DEFAULT_BG_DARK_COLOR);

    item1 = new ListContainer::Item({0, 0}, {240, 50}, supp::DEFAULT_BG_DARK_COLOR);
    item2 = new ListContainer::Item({0, 50}, {240, 50}, {255, 255, 0});
    item3 = new ListContainer::Item({0, 100}, {240, 50}, {255, 0, 0});
    item4 = new ListContainer::Item({0, 150}, {240, 50}, {0, 255, 0});
    item5 = new ListContainer::Item({0, 50}, {240, 50}, {0, 0, 255});

    // item1->draw();
    // item2->draw();
    ec4->addContainer(lc, IContainerBase::POSITION_ABSOLUTE);

    lc->addItem(item3);
    lc->addItem(item4);
    lc->addItem(item5);
    lc->addItem(item2);
    
    delay(2000);
    lc->setPosition({0, 200});

    delay(2000);
    lc->moveRangeDown();

    delay(2000);
    lc->moveRangeDown();

    lc->moveRangeDown();
    lc->moveRangeDown();

    lc->draw();

    // delay(2000);
    // lc->moveRangeDown();

    // delay(2000);
    // lc->setPosition({0, 100});
    // lc->draw();

    // delay(2000);
    // lc->moveRangeDown();

    // item1->draw();
    // item2->draw();
    // item3->draw();
    // item4->draw();
    // item5->draw();

    // lc->addItem(item1);
    // lc->addItem(item2);
    // lc->addItem(item3);
    // lc->addItem(item4);
    // lc->addItem(item5);

    // lc->draw();

    // delay(2000);
    // lc->moveRangeDown();

    // delay(2000);
    // lc->moveRangeDown();

    // delay(2000);
    // lc->moveRangeDown();

    // delay(2000);
    // lc->moveRangeDown();
}

void loop()
{
    supp::Point tp = TouchScreen::getInstance().getTouch();
    // dbg::printPoint(tp);
    item3->handleTouch(tp);
}
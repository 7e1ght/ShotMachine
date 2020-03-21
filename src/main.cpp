#include <Arduino.h>

#include "config/config.hpp"
#include "support/Vector.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"
#include "containers/test_func.hpp"

#include "support/Screen.hpp"
#include "support/TouchScreen.hpp"

#include "support/debug.hpp"

#include "Windows/TestWindow.hpp"

EmptyContainer* ec1;
EmptyContainer* ec2;
EmptyContainer* ec3;

ButtonContainer* headerButton;
ButtonContainer* centerButton;
ButtonContainer* bottomButton;

TextContainer* tc1;
TextContainer* tc2;

TestWindow* tw;


// mAllScreen( new EmptyContainer({0,0}, supp::FULLSCREEN, supp::DEFAULT_BG_LIGHT_COLOR) ),
//     mUpperBar( new EmptyContainer(supp::NO_POSITION, {0, 25}, supp::DEFAULT_BG_DARK_COLOR) ),
//     mLoweBar( new EmptyContainer(supp::NO_POSITION, {0, 25}, supp::DEFAULT_BG_DARK_COLOR) ),
//     mUpperText( new TextContainer("Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR) ),
//     mLowerText( new TextContainer("Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR) )


void setup()
{
    Serial.begin(9600);

    ec1 = new EmptyContainer({0, 0}, supp::FULLSCREEN, supp::DEFAULT_BG_LIGHT_COLOR);
    ec2 = new EmptyContainer(supp::NO_POSITION, {0, 25}, supp::DEFAULT_BG_DARK_COLOR);
    ec3 = new EmptyContainer(supp::NO_POSITION, {0, 25}, supp::DEFAULT_BG_DARK_COLOR);

    tc1 = new TextContainer("Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR);
    tc2 = new TextContainer("Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR);

    ec2->addContainer(tc1, IContainerBase::POSITION_CENTER);
    ec3->addContainer(tc2, IContainerBase::POSITION_CENTER);

    ec1->addContainer(ec2,IContainerBase::POSITION_TOP);
    ec1->addContainer(ec3,IContainerBase::POSITION_BOTTOM);

    ec1->draw();

    // tw = new TestWindow();
    // tw->drawAll();

}

void loop()
{
    if(TouchScreen::getInstance().readyTouch())
    {
        if( tc1->getText() == "Vlad" ) tc1->setText("No Vlad");
        else tc1->setText("Vlad");
    }
}
#ifndef MAIN_SCENE_HPP
#define MAIN_SCENE_HPP

#include "IScene.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"
#include "containers/ButtonContainer.hpp"

class MainScene
: public IScene
{
public:
    virtual SCENE_ID doLoop(supp::Point touchPoint) override;

    MainScene();
private:
    void initElements() noexcept;
    void addElements() noexcept;

    TripleContainer* upperBar;
    TripleContainer* lowerBar;

    EmptyContainer* contentLayout;

    ListContainer* cocktailContent;

    EmptyContainer* buttonLayout;
 
    ButtonContainer* createTemplate;
    ButtonContainer* toQueu;
    ButtonContainer* coock;
};

inline void MainScene::initElements() noexcept
{
    upperBar = new TripleContainer(supp::NO_POSITION, {0, supp::DEFAULT_ELEMENT_HEIGHT}, supp::NO_COLOR);
    upperBar->setLeft( new TextContainer("<", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR));
    upperBar->setMiddle( new TextContainer("Slot8", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR));
    upperBar->setRight( new TextContainer(">", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR));

    lowerBar = new TripleContainer(supp::NO_POSITION, {0, supp::DEFAULT_ELEMENT_HEIGHT}, supp::NO_COLOR);
    lowerBar->setLeft( new TextContainer("<", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR));
    lowerBar->setMiddle( new TextContainer("Slot8", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR));
    lowerBar->setRight( new TextContainer(">", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::NO_COLOR));

    contentLayout = new EmptyContainer({0, 25}, {220, cfg::display::SCREEN_HEIGHT-70}, supp::NO_COLOR);
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()),
        nullptr,
        new TextContainer("200", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()),
        nullptr,
        new TextContainer("200", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()),
        nullptr,
        new TextContainer("200", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()),
        nullptr,
        new TextContainer("200", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()),
        nullptr,
        new TextContainer("200", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()),
        nullptr,
        new TextContainer("200", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );
    cocktailContent->addItem(
        new TextContainer("vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()),
        nullptr,
        new TextContainer("200", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor())
    );

    cocktailContent = new ListContainer(8, supp::NO_POSITION, {220, 155}, mainLayout->getMainColor());
    buttonLayout = new EmptyContainer(supp::NO_POSITION, {220, 95}, mainLayout->getMainColor());
    createTemplate = new ButtonContainer("New template", [](){ Serial.println("New template"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
    toQueu = new ButtonContainer("To queu", [](){ Serial.println("To queu"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
    coock = new ButtonContainer("Coock", [](){ Serial.println("Coock"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
}

inline void MainScene::addElements() noexcept
{
    mainLayout->addContainer(upperBar, IContainerBase::POSITION_TOP);
    mainLayout->addContainer(lowerBar, IContainerBase::POSITION_BOTTOM);
    mainLayout->addContainer(contentLayout, IContainerBase::POSITION_CENTER);

    contentLayout->addContainer(cocktailContent, IContainerBase::POSITION_TOP);
    contentLayout->addContainer(buttonLayout, IContainerBase::POSITION_BOTTOM);

    buttonLayout->addContainer(createTemplate, IContainerBase::POSITION_TOP);
    buttonLayout->addContainer(toQueu, IContainerBase::POSITION_CENTER);
    buttonLayout->addContainer(coock, IContainerBase::POSITION_BOTTOM);
}

#endif // MAIN_SCENE_HPP
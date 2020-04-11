#include "scenes/MainScene.hpp"

MainScene::MainScene()
: IScene(IScene::SCENE_ID::MAIN)
{
    initCallbacks();
    initElements();
    addElements();
}

void MainScene::initElements() noexcept
{
    upperBar = new TripleContainer(supp::NO_POSITION, {0, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
    upperBar->setMiddleWidth(200);
    upperBar->setLeft( new TextContainer("<", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, upperBar->getMainColor()));
    upperBar->setMiddle( new TextContainer("GlassNumber", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, upperBar->getMainColor()));
    upperBar->setRight( new TextContainer(">", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, upperBar->getMainColor()));

    lowerBar = new TripleContainer(supp::NO_POSITION, {0, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
    lowerBar->setMiddleWidth(200);
    lowerBar->setLeft( new TextContainer("<", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, lowerBar->getMainColor() ));
    lowerBar->setMiddle( new TextContainer("Cocktail", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, lowerBar->getMainColor() ));
    lowerBar->setRight( new TextContainer(">", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, lowerBar->getMainColor() ));

    contentLayout = new EmptyContainer({0, 25}, {220, cfg::display::SCREEN_HEIGHT-70}, mMainLayout->getMainColor() );

    cocktailContent = new ListContainer(8, supp::NO_POSITION, {220, 155}, mMainLayout->getMainColor());

    buttonLayout = new EmptyContainer(supp::NO_POSITION, {220, 95}, mMainLayout->getMainColor());
    createTemplate = new ButtonContainer("New template", [](){ Serial.println("New template"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
    toQueu = new ButtonContainer("To queu", [](){ Serial.println("To queu"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
    coock = new ButtonContainer("Coock", [](){ Serial.println("Coock"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
}

void MainScene::initCallbacks() noexcept
{

}

void MainScene::addElements() noexcept
{
    mMainLayout->addContainer(upperBar, IContainerBase::POSITION_TOP);
    mMainLayout->addContainer(lowerBar, IContainerBase::POSITION_BOTTOM);
    mMainLayout->addContainer(contentLayout, IContainerBase::POSITION_CENTER);

    contentLayout->addContainer(cocktailContent, IContainerBase::POSITION_TOP);
    contentLayout->addContainer(buttonLayout, IContainerBase::POSITION_BOTTOM);

    buttonLayout->addContainer(createTemplate, IContainerBase::POSITION_TOP);
    buttonLayout->addContainer(toQueu, IContainerBase::POSITION_CENTER);
    buttonLayout->addContainer(coock, IContainerBase::POSITION_BOTTOM);
}
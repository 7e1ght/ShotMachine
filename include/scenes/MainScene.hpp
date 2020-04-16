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
    MainScene();
private:
    void initElements() noexcept;
    void addElements() noexcept;

    void addItem(const String& leftSide, const String& rightSide) noexcept;

    TripleContainer* upperBar;
    TripleContainer* lowerBar;

    EmptyContainer* contentLayout;

    ListContainer* cocktailContent;

    EmptyContainer* buttonLayout;
 
    ButtonContainer* createTemplate;
    ButtonContainer* toQueu;
    ButtonContainer* coock;

    ~MainScene()
    {
        delete mMainLayout;
    }
};

#endif // MAIN_SCENE_HPP
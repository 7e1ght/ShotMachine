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
    void initCallbacks() noexcept;
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

#endif // MAIN_SCENE_HPP
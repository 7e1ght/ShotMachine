#ifndef I_SCENE_HPP
#define I_SCENE_HPP

#include "support/support.hpp"
#include "containers/EmptyContainer.hpp"

class IScene
{
public:
    enum class SCENE_ID
    {
        MAIN,
        NO_SCENE
    };

    void renderScene() const noexcept
    {
        mainLayout->draw();
    }

    virtual SCENE_ID doLoop(supp::Point touchPoint) = 0;

    IScene();
    virtual ~IScene(){}
protected:
    EmptyContainer* mainLayout;
};

#endif // I_SCENE_HPP
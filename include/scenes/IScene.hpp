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
        NEW_TEMPLATE,
        
        NO_SCENE
    };

    void renderScene() const noexcept
    {
        mMainLayout->draw();
    }

    virtual SCENE_ID doLoop(supp::Point touchPoint);

    IScene(SCENE_ID defaultSceneID);
    virtual ~IScene(){}
protected:
    EmptyContainer* mMainLayout;
    
private:
    void handleTouch( supp::Point touchPoint ) 
    { 
        if(supp::NO_TOUCH != touchPoint)
        {
            mMainLayout->handleTouch(touchPoint);    
        }
    }

    virtual void specificStep() {};

    SCENE_ID mReturnSceneId;
};

#endif // I_SCENE_HPP
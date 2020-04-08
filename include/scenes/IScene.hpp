#ifndef I_SCENE_HPP
#define I_SCENE_HPP

#include "support/support.hpp"

class IScene
{
public:
    enum class SCENE_ID
    {
        MAIN
    };


    virtual SCENE_ID doLoop(supp::Point touchPoint) = 0;
};

#endif // I_SCENE_HPP
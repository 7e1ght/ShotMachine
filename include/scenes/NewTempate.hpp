#ifndef NEW_TEMPLATE_HPP
#define NEW_TEMPLATE_HPP

#include "IScene.hpp"
#include "support/support.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"
#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"

class NewTemplate
: public IScene
{
public:
private: 
    TripleContainer* mUpperBar;
    TextContainer* mMaxGlassCapacity;
    ListContainer* mLiquidList;
    ButtonContainer* mVireButton;
    ButtonContainer* mOkButton;

    EmptyContainer* mContentLayout;
};

#endif // NEW_TEMPLATE_HPP
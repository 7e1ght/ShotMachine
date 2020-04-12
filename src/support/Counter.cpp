#include "support/Counter.hpp"

#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"

Counter::Counter(int step, supp::Point point, supp::Size size, supp::Color color, IContainerBase* parent)
: TripleContainer(point, size, color, parent)
, mCount(0)
, mStep(step)
{
    TextContainer* val = new TextContainer(String(mCount), supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, color);

    auto lowCount =
    [&, val]()
    {
        if(0 != mCount)
        {
            mCount = mCount - mStep;
       
            val->setText( String(mCount) );
            val->draw();
        }
    };

    auto upCount =
    [&, val]()
    {
        if(1000 > mCount + mStep)
        {
            mCount = mCount + mStep;
            val->setText( String(mCount) );
            val->draw();
        }
    };

    TripleContainer::setLeft(new ButtonContainer("-", lowCount, supp::NO_POSITION, {16, 16}, color));

    TripleContainer::setMiddle( val );
    TripleContainer::setMiddleWidth( size.width-16*2 );

    TripleContainer::setRight( new ButtonContainer("+", upCount, supp::NO_POSITION, {16, 16}, color) );
}
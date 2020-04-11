#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "containers/TripleContainer.hpp"

class Counter
: public TripleContainer
{
public:
    Counter(int step, supp::Point point, supp::Size size, supp::Color color, IContainerBase* parent = nullptr);
    
    int getCount() const noexcept { return mCount;}
    void setCount(int count) noexcept { mCount = count; };

    int getStep() const noexcept { return mStep; };
    void setStep(int step) noexcept { mStep = step; };
    
private:
    int mCount;
    int mStep;
};

#endif // COUNTER_HPP
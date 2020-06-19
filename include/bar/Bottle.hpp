#ifndef BOTTLE_HPP
#define BOTTLE_HPP

#include "Liquid.hpp"
#include "support/support.hpp"

namespace cfg
{
    namespace bottle
    {
        const double RUM_DELAY = 2.0; // sec
        const double MARTINI_DELAY = 2.0; 
        const double SYRUP_COCONUT_DELAY = 4.5;
        const double COLA_DELAY = 2.0;
        const double PINEAPPLE_JUICE_DELAY = 1.0;
        const double ORANGE_JUICE_DELAY = 1.0; 
    }
}


class Bottle
{
private:
    Liquid::Type mLiquid;
    mutable int16_t mCapacity;
    uint16_t mPin;
public:
    void pour(uint16_t size) const noexcept;
    Liquid::Type getLiquid() const noexcept { return mLiquid; }
    uint16_t getCapacity() const noexcept { return mCapacity; }
    uint16_t getPin() const noexcept { return mPin; }

    bool isEmpty() const noexcept
    {
        return 0 >= mCapacity;
    }

    Bottle(uint16_t pin, Liquid::Type type);
    Bottle() : mLiquid(Liquid::NO_LIQUID), mCapacity(supp::DEFAULT_BOTTLE_CAPACITY), mPin(0) {}
};

#endif // BOTTLE_HPP
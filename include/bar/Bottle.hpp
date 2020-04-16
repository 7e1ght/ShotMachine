#ifndef BOTTLE_HPP
#define BOTTLE_HPP

#include "Liquid.hpp"
#include "support/support.hpp"

class Bottle
{
private:
    Liquid::Type mLiquid;
    uint16_t mCapacity;
    uint16_t mPin;
public:
    void pour(uint16_t size) noexcept;
    uint16_t getCapacity() const noexcept { return mCapacity; }
    uint16_t getPin() const noexcept { return mPin; }

    Bottle(uint16_t pin, Liquid::Type type) : mLiquid(type), mCapacity(supp::DEFAULT_BOTTLE_CAPACITY), mPin(pin) {}
    Bottle() : mLiquid(Liquid::NO_LIQUID), mCapacity(supp::DEFAULT_BOTTLE_CAPACITY), mPin(0) {}
};

#endif // BOTTLE_HPP
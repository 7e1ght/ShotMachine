#ifndef GLASS_HPP
#define GLASS_HPP

#include "support/support.hpp"

class Glass
{
private:
    uint16_t mPin;
public:
    uint16_t getPin() const noexcept { return mPin; }

    Glass operator=(const Glass& other)
    {
        mPin = other.mPin;
    }

    Glass(const uint16_t pin) : mPin(pin) {}
    Glass() : mPin(0) {}
};

#endif // GLASS_HPP
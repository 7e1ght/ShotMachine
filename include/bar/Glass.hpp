#ifndef GLASS_HPP
#define GLASS_HPP

#include "support/support.hpp"

class Glass
{
private:
    const uint16_t mPin;
public:
    uint16_t getPin() const noexcept { return mPin; }

    Glass(const uint16_t pin) : mPin(pin) {}
};

#endif // GLASS_HPP
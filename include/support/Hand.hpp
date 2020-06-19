#ifndef HAND_H
#define HAND_H

#include <UTFT.h>
#include <Stepper.h>

#include "config/config.hpp"
#include "support/support.hpp"
#include "bar/Glass.hpp"

namespace cfg
{
    namespace hand
    {
        const uint16_t FULL_ROTATE_STEPS = 800;

        const uint8_t DIRECTION_PIN = 9;
        const uint8_t STEP_PIN = 8;
        const uint8_t ENABLE_DISABLE_PIN = 11;
    }
}

class Hand 
    : private Stepper
{
private:
    Hand();
    uint16_t mStepped;
public:
    static Hand& getInstance() noexcept;

    void makeSteps(int16_t steps) noexcept;
    uint16_t getStepped() noexcept;
    void resetStepped() noexcept;
};

inline uint16_t Hand::getStepped() noexcept
{
    return mStepped;
}

inline void Hand::makeSteps(int16_t steps) noexcept
{
    digitalWrite(cfg::hand::ENABLE_DISABLE_PIN, HIGH);
    Stepper::step(steps);
    mStepped += steps;
    digitalWrite(cfg::hand::ENABLE_DISABLE_PIN, LOW);
}

inline void Hand::resetStepped() noexcept
{
    mStepped = 0;
}

#endif // HAND_H
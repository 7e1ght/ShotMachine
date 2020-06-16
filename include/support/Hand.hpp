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
    }
}

class Hand 
    : private Stepper
{
private:
    Hand();

public:
    static Hand& getInstance() noexcept;
    void makeSteps(uint8_t steps) noexcept;
};

inline void Hand::makeSteps(uint8_t steps) noexcept
{
    Stepper::step(steps);
}

#endif // HAND_H
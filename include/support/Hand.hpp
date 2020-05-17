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
        const uint8_t ENABLE_DISABLE_PIN = 10;

        const uint8_t INITIAL_STEP = 100;

        const uint8_t DISTANCE_STEP = 20;
    }
}

class Hand 
    : private Stepper
{
private:
    Hand();
    mutable uint16_t stepped;

public:
    static Hand& getInstance() noexcept;

    void moveHandTo(const uint8_t glassId) noexcept;

    void resetPosition() noexcept
    {
        Stepper::step(-stepped);
        stepped = 0;
    }
};

#endif // HAND_H
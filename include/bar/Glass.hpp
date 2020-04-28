#ifndef GLASS_HPP
#define GLASS_HPP

#include "support/support.hpp"

class Glass
{
private:
    uint8_t mId;

    uint16_t mTrigPin;
    uint16_t mEchoPin;

    static uint8_t idCounter;

    bool update() const noexcept;
public:

    bool isAvailable() const noexcept { return update(); }

    uint8_t getId() const noexcept { return mId; }

    uint16_t getTrimPin() const noexcept { return mTrigPin; }
    uint16_t getEchoPin() const noexcept { return mEchoPin; }

    bool operator==(const Glass& other) const;

    Glass(const uint16_t trigPin, const uint16_t echoPin);
    Glass() : mTrigPin(0), mEchoPin(0), mId(0) {}
};

#endif // GLASS_HPP
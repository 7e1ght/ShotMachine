#include "bar/Bottle.hpp"

void Bottle::pour(uint16_t size) const noexcept
{
    if(0 < mCapacity)
    {
        unsigned long timeStart = millis();

        double time = static_cast<double>(size)/supp::GRAM_PER_SECOND;

        digitalWrite(mPin, LOW);
        while( (millis()-timeStart)/1000.0 <= time );
        
        digitalWrite(mPin, HIGH);

        mCapacity -= size;
    }
}

Bottle::Bottle(uint16_t pin, Liquid::Type type)
: mLiquid(type)
, mCapacity(supp::DEFAULT_BOTTLE_CAPACITY)
, mPin(pin)
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}
#include "bar/Bottle.hpp"

void Bottle::pour(uint16_t size) noexcept
{
    if(0 < mCapacity)
    {
        pinMode(mPin, OUTPUT);
        digitalWrite(mPin, LOW);

        unsigned long timeStart = millis();
        double time = static_cast<double>(size)/supp::DEFAULT_COEF;

        while( (millis()-timeStart)/1000.0 <= time );
        
        digitalWrite(mPin, HIGH);

        mCapacity -= size;
    }
}
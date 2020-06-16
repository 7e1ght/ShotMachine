#include "bar/Glass.hpp"

Glass::Glass(const uint16_t trigPin, const uint16_t echoPin) : mTrigPin(trigPin), mEchoPin(echoPin)
{
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

bool Glass::update() const noexcept
{
   digitalWrite(mTrigPin, LOW);
   delay(2);

   digitalWrite(mTrigPin, HIGH);
   delay(5);

   digitalWrite(mTrigPin, LOW);

   uint16_t distance = pulseIn(mEchoPin, HIGH);

   Serial.println( String("Distance = ") + distance );

   return distance <= 300 && 100 <= distance;
}

bool Glass::operator==(const Glass& other) const
{
   return ( (other.mTrigPin == mTrigPin) && (other.mEchoPin == mEchoPin) );
}
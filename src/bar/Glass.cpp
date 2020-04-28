#include "bar/Glass.hpp"

uint8_t Glass::idCounter = 1;

Glass::Glass(const uint16_t trigPin, const uint16_t echoPin) : mTrigPin(trigPin), mEchoPin(echoPin)
{
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   mId = idCounter++;
}

bool Glass::update() const noexcept
{
   digitalWrite(mTrigPin, LOW);
   delay(2);

   digitalWrite(mTrigPin, HIGH);
   delay(150);

   digitalWrite(mTrigPin, LOW);

   uint16_t distance = pulseIn(mEchoPin, HIGH);

   Serial.println( distance );

   return distance <= 300 && 100 <= distance;
}

bool Glass::operator==(const Glass& other) const
{
   return ( (other.mId == mId) && (other.mTrigPin == mTrigPin) && (other.mEchoPin == mEchoPin) );
}
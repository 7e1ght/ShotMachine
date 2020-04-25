#include "bar/Glass.hpp"

uint8_t Glass::idCounter = 1;

Glass::Glass(const uint16_t trigPin, const uint16_t echoPin) : mTrigPin(trigPin), mEchoPin(echoPin), mIsAvailable(false)  
{
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   mId = idCounter++;
}

void Glass::update() noexcept
{
   digitalWrite(mTrigPin, LOW);
   delay(2);

   digitalWrite(mTrigPin, HIGH);
   delay(150);

   digitalWrite(mTrigPin, LOW);

   int distance = pulseIn(mEchoPin, HIGH);

   mIsAvailable = (distance <= 300);

   Serial.println( distance );
}

bool Glass::operator==(const Glass& other) const
{
   return ( (other.mId == mId) && (other.mTrigPin == mTrigPin) && (other.mEchoPin == mEchoPin) && (other.mIsAvailable == mIsAvailable));
}
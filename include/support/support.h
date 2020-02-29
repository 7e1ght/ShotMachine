#ifndef SUPPORT_H
#define SUPPORT_H

#include <stdio.h>

namespace supp
{
    struct Point
    {
        int16_t x;
        int16_t y;
    };

    struct Size
    {
        uint16_t width;
        uint16_t height;
    };

    template<typename Key, typename Value>
    class Pair
    {
    public:
        Pair()
        : mKey()
        , mValue() 
        {}

        Pair(Key key, Value value)
        : mKey(key)
        , mValue(value)
        {}

        void setKey(Key newKey)
        {
            mKey = newKey;
        }

        void setValue(Value newValue)
        {
            mValue = newValue;
        }

        Key getKey()
        {
            return mKey;
        }

        Value getValue()
        {
            return mValue;
        }

    private:
        Key mKey;
        Value mValue;
    };


}

#endif // SUPPORT_H
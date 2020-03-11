#ifndef SUPPORT_H
#define SUPPORT_H

#include <stdio.h>
#include <WString.h>
#include <HardwareSerial.h>

namespace supp
{
    struct Point
    {
        int16_t x;
        int16_t y;

        constexpr bool operator==(const Point& other) const noexcept
        {
            return(x == other.x && y == other.y);
        }

        constexpr bool operator!=(const Point& other) const noexcept
        {
            return (x != other.x && y != other.y);
        }

        constexpr bool operator>=(const Point& other) const noexcept
        {
            return (x <= other.x && y <= other.y); 
        }

        constexpr bool operator<=(const Point& other) const noexcept
        {
            return (x >= other.x && y >= other.y); 
        }
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

        void setKey(Key newKey) noexcept
        {
            mKey = newKey;
        }

        void setValue(Value newValue) noexcept
        {
            mValue = newValue;
        }

        const Key& getKey() const noexcept
        {
            return mKey;
        }

        const Value& getValue() const noexcept
        {
            return mValue;
        }

        Key& getKey() noexcept
        {
            return mKey;
        }

        Value& getValue() noexcept
        {
            return mValue;
        }
    private:
        Key mKey;
        Value mValue;
    };


    template<typename Key, typename Value>
    class Pair<Key, Value*>
    {
    public:
        Pair()
        : mKey()
        , mValue(nullptr) 
        {}

        Pair(Key key, Value* value) 
        : mKey(key)
        , mValue(value)
        {}

        ~Pair()
        {
            delete mValue;
        }

        void setKey(Key newKey) noexcept
        {
            mKey = newKey;
        }

        void setValue(Value* newValue) noexcept
        {
            delete mValue;
            mValue = newValue;
        }

        const Key& getKey() const noexcept
        {
            return mKey;
        }

        const Value* getValue() const noexcept
        {
            return mValue;
        }

        Key& getKey() noexcept
        {
            return mKey;
        }

        Value* getValue() noexcept
        {
            return mValue;
        }
    private:
        Key mKey;
        Value* mValue;
    };

    struct Color
    {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    };

    const Size calcTextSize(const String& text) noexcept;

    const Color DEFAULT_BG_LIGHT_COLOR = {96, 125, 139};
    const Color DEFAULT_BG_DARK_COLOR = {69, 90, 100};
    const Color DEFAULT_TEXT_COLOR = {248, 248, 248};
    const Point NO_TOUCH = {-1, -1};
    const uint64_t DEFAULT_TAP_DELAY = 1000;
}
#endif // SUPPORT_H
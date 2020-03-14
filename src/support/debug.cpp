#include "support/debug.hpp"

void dbg::printPoint(const supp::Point& point) noexcept
{
    // if(supp::NO_TOUCH != point)
    // {
            Serial.print("x = ");
            Serial.print(point.x);
            Serial.print(" ");
            Serial.print("y = ");
            Serial.println(point.y);
    // }
    
}

void dbg::printSize(const supp::Size& size) noexcept
{
    Serial.print("width = ");
    Serial.print(size.width);
    Serial.print(" ");
    Serial.print("height = ");
    Serial.println(size.height);
}
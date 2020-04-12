#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "support/support.hpp"

namespace dbg
{
    void printPoint(const supp::Point& point) noexcept;
    void printSize(const supp::Size& size) noexcept ;
    void printColor(const supp::Color& color ) noexcept;
}

#endif // DEBUG_HPP
#ifndef GLASS_SCANNER_HPP
#define GLASS_SCANNER_HPP

#include "support/Vector.hpp"
#include "support/support.hpp"

#include "bar/Glass.hpp"

class GlassScanner
{
private:
    supp::Vector<Glass> mAvaiableGlass;
    GlassScanner() {}

public:
    GlassScanner& getInstance() const noexcept
    {
        static GlassScanner gs;

        return gs;
    }

    void update() noexcept;
    const supp::Vector<Glass>& getAvaiableGlass() const noexcept
    { return mAvaiableGlass; }
};

#endif // GLASS_SCANNER_HPP
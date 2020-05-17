#ifndef CONFIG_H
#define CONFIG_H

#include <UTFT.h>

namespace cfg
{

namespace display
{
    const uint8_t DISPLAY_MODEL = CTE32_R2;
    const uint8_t RS_PIN = 38;
    const uint8_t WR_PIN = 39;
    const uint8_t CS_PIN = 40;
    const uint8_t RST_PIN = 41;

    const uint16_t SCREEN_WIDTH = 240;
    const uint16_t SCREEN_HEIGHT = 320;
}

namespace touchscreen
{
    const uint8_t TCLK_PIN = 6;
    const uint8_t TCS_PIN = 5;
    const uint8_t TDIN_PIN = 4;
    const uint8_t DOUT_PIN = 3;
    const uint8_t IRQ_PIN = 2;
}

namespace vector
{
    const uint8_t DEFAULT_CAPACITY = 5;
}

namespace UI
{
    const uint8_t DEFAULT_BAR_HEIGHT = 25;
}

namespace glass
{
    const uint16_t CAPACITY = 300;
}

}

#endif // CONFIG_H
/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Set palette

 ***************************************************/
#include "blank.h"

#include <arch/zxn.h>
#include "inttypes.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/
// Tile map palette
// RRRGGGBB 8 bit colour
// NB Default transparency palette index is 0xF
static const uint8_t tile_palette[] = 
{
    0x00,       // black
    0xFF,       // white
    0xE0,       // red
    0x1C,       // green
    0x03,       // blue
    0xFC,       // yellow
    0x1F,       // cyan
    0xE3,       // magenta
    0x0,
    0x0,
    0x0,    
    0x0,
    0x0,
    0x0,    
    0x0,
    0x0        // default transparent index
};

/***************************************************
 * functions definitions
 ***************************************************/


void palette_init()
{
    // 0x43 Palette Control
    // 7    0 = enable auto-increment
    // 6-4  011 = seletect tilemap first palette for writing reading
    // 3-1  000 = select sprite palette 0, layer 2 palette 0, ULA palette 0
    // 0    1 = enable ULANext mode 
    ZXN_WRITE_REG(0x43, 0b00110000);

    // 041 Palette Value (8 bit colour)
    // Write palette
    for (uint8_t i = 0 ; i < 16; i++) {
        //ZXN_WRITE_REG(0x41,i);
        ZXN_WRITE_REG(0x41, tile_palette[i]);
    }
}

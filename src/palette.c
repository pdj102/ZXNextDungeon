/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief ZXnext palette

 ***************************************************/
#include "palette.h"

#include <arch/zxn.h>
#include <inttypes.h>

// Set TILE_PALETTE_SIZE to the size of the palette data
#define TILE_PALETTE_SIZE 96

/***************************************************
 * private types
 ***************************************************/

// tile_palette is defined in palette_data.asm
extern uint8_t tile_palette[];

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/



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
    
    // Tile map palette
    // RRRGGGBB 8 bit colour
    // NB Default transparency palette index is 0xF
    for (uint8_t i = 0 ; i < TILE_PALETTE_SIZE; i++) {
        ZXN_WRITE_REG(0x41, tile_palette[i]);
    }
}

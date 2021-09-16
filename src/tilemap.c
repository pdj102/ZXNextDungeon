/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manages ZX Next tilemap

 ***************************************************/
#include "tilemap.h"

#include <arch/zxn.h>

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/
int volatile * const tilemap_base_p = (int *) 0x6000;

int volatile * const tile_def_base_p = (int *) 0x6A00;


// tile definitions
static const uint16_t tile_pattern[] = 
{
    // 3412 3412 pixel position left to right

    // 0x0 coloured square
    0x0000, 0x1111,
    0x2222, 0x3333,
    0x4444, 0x5555,
    0x6666, 0x7777,
    0x8888, 0x9999,
    0xAAAA, 0xBBBB,
    0xCCCC, 0xDDDD,
    0xEEEE, 0xFFFF,

    // 0x1 box
    0xFFFF, 0xFFFF,
    0x00F0, 0x0F00,
    0x00F0, 0x0F00,
    0x00F0, 0x0F00,
    0x00F0, 0x0F00,
    0x00F0, 0x0F00,
    0x00F0, 0x0F00,
    0xFFFF, 0xFFFF,

    // 0x2 red brick
    0X1111, 0x1111,
    0x2212, 0x2222,
    0x2212, 0x2222,
    0x1111, 0x1111,
    0x2222, 0x1222,
    0x2222, 0x1222,
    0x2222, 0x1222,
    0x1111, 0x1111
};



/***************************************************
 * functions definitions
 ***************************************************/

void tilemap_init()
{
    // 0x6E - Tilemap base address
    // sets the tilemap base address offset within bank 5 (bank 5 is at 0x4000)
    // The ULA screen is located 0x4000 - 0x5FFF (7 KiB) so setting tilemap base address to 0x6000 avoids it
    // If ULA screen is not required it could be turned off and the tilemap written at 0x4000
    // 0x6E is set with the MSB which represents an n x 256 byte offset. (0x6000 - 0x4000) / 0x100 = 32
    // 40 x 32 tilemap is 2,560 bytes
    ZXN_NEXTREG(0x6E, 32);

    // 0x6F - Tile definitions base address
    // sets the tile definitions base address offset within bank 5 (bank 5 is at 0x4000)
    // The tilemap is 2,560 bytes so setting the base address to 0x6A00 avoids it
    // 0x6F is set with the MSB which represents an n x 256 byte offset. (0x6A00 - 0x4000) / 0x100 = 42
    ZXN_NEXTREG(0x6F, 42);

    // write tile defs
    for (uint8_t i = 0; i < 32*3; i++)
    {
        *(tile_def_base_p+i) = tile_pattern[i];
    }

    // TEST write tile 0 and attribute 0 
    for (uint16_t i = 0; i < 40*32; i++) {
        *(tilemap_base_p+i) = 0x0;
    }

    *(tilemap_base_p+0) = (0b0 << 0) + (0b0000 << 12);
    *(tilemap_base_p+1) = (0b0 << 0) + (0b0001 << 12);
    *(tilemap_base_p+2) = (0b0 << 0) + (0b0010 << 12);
    *(tilemap_base_p+3) = (0b0 << 0) + (0b0011 << 12);          


    //0x6B Tilemap Control
    // Turn on the tilemap layer, 40x32, attributes enabled
    // bit 7    1 = enable tilemap
    // bit 6    = 0 for 40x32, 1 for 80x32
    // bit 5    = 1 to eliminate the attribute entry in the tilemap
    // bit 4    = palette select
    // bits 3-2 = Reserved set to 0
    // bit 1    = 1 to activate 512 tile mode
    // bit 0    = 1 to force tilemap on top of ULA    

    ZXN_WRITE_REG(0x6B, 0b10000000);

}

void tilemap_set_tile(uint8_t x, uint8_t y, uint8_t tile)
{
    uint8_t attr;
    uint16_t addr;

    attr = 0b001 << 4;

    addr = (y*32) + x * 2;

    *(tilemap_base_p+addr) = tile;


}


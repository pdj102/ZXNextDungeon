/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tile definitions

 ***************************************************/
#include "tile_defns.h"

#include <stdint.h>             // standard names for ints with no ambiguity
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
uint16_t volatile * const tile_def_base_p = (uint16_t *) 0x6A00;

// tile definitions
static const uint16_t tile_pattern[] = 
{
    // nibble order of pixels left to right 3412 3412 

    // 0x0 coloured square to show palette
    0x0000, 0x1111,
    0x2222, 0x3333,
    0x4444, 0x5555,
    0x6666, 0x7777,
    0x8888, 0x9999,
    0xAAAA, 0xBBBB,
    0xCCCC, 0xDDDD,
    0xEEEE, 0xFFFF,

    // 0x1 floor
    0x0000, 0x0000,
    0x0000, 0x0000,    
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0000, 0x0000,

    // 0x2 red brick
    0X2212, 0x2222,
    0x2212, 0x2222,
    0x2212, 0x2222,
    0x1111, 0x1111,
    0x2222, 0x1222,
    0x2222, 0x1222,
    0x2222, 0x1222,

    // 0x1 box

    0x1111, 0x1111,
    0x0010, 0x0100,
    0x0010, 0x0100,
    0x0010, 0x0100,
    0x0010, 0x0100,
    0x0010, 0x0100,
    0x0010, 0x0100,
    0x1111, 0x1111,    
};

/***************************************************
 * functions definitions
 ***************************************************/

void tile_defns_init()
{
    // 0x6F - Tile definitions base address
    // sets the tile definitions base address offset within bank 5 (bank 5 is at 0x4000)
    // The tilemap is 2,560 bytes so setting the base address to 0x6A00 avoids it
    // 0x6F is set with the MSB which represents an n x 256 byte offset. (0x6A00 - 0x4000) / 0x100 = 42
    ZXN_NEXTREG(0x6F, 42);

    // write tile defs to tile definitions base address
    for (uint16_t i = 0; i < sizeof tile_pattern / sizeof tile_pattern[0]; i++)
    {
        *(tile_def_base_p+i) = tile_pattern[i];
    }

}

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
uint8_t volatile * const tile_def_base_p = (uint8_t *) 0x6A00;

// tile definitions
static const uint8_t tile_pattern[] = 
{
    // Sprite 0 - 0x0 transparent tile
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 

    // Sprite 0 - 0x1 transparent tile
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 

    // Sprite 0 - 0x2 transparent tile
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 

    // Sprite 0 - 0x3 transparent tile
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 

	// Sprite 1 - 0x0
     0x54, 0x44, 0x31, 0x55,
	 0x43, 0x33, 0x31, 0x54,
	 0x33, 0x33, 0x31, 0x43,
	 0x11, 0x11, 0x11, 0x11,
	 0x43, 0x15, 0x55, 0x44,
	 0x33, 0x15, 0x44, 0x33,
	 0x33, 0x14, 0x33, 0x33,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 1 - 0x1
	 0x14, 0x44, 0x31, 0x55,
	 0x13, 0x33, 0x31, 0x54,
	 0x13, 0x33, 0x31, 0x43,
	 0x11, 0x11, 0x11, 0x11,
	 0x13, 0x15, 0x55, 0x44,
	 0x13, 0x15, 0x44, 0x33,
	 0x13, 0x14, 0x33, 0x33,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 1 - 0x2
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	// Sprite 1 - 0x3
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	// Sprite 2 - 0x0
	 0x44, 0x54, 0x44, 0x44,
	 0x44, 0x44, 0x44, 0x54,
	 0x55, 0x55, 0x44, 0x44,
	 0x44, 0x44, 0x44, 0x44,
	 0x44, 0x44, 0x44, 0x54,
	 0x54, 0x44, 0x44, 0x44,
	 0x44, 0x44, 0x55, 0x55,
	 0x44, 0x44, 0x44, 0x54,
	// Sprite 2 - 0x1
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 2 - 0x2
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 2 - 0x3
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	// Sprite 3 - 0x0
	 0x11, 0x11, 0x11, 0x11,
	 0x13, 0x33, 0x33, 0x33,
	 0x13, 0x44, 0x44, 0x44,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	// Sprite 3 - 0x1
	 0x11, 0x11, 0x11, 0x11,
	 0x33, 0x33, 0x33, 0x33,
	 0x44, 0x44, 0x44, 0x44,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 3 - 0x2
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x44, 0x44, 0x44,
	 0x13, 0x33, 0x33, 0x33,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 3 - 0x3
	 0x11, 0x11, 0x11, 0x11, 
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x44, 0x44, 0x44, 0x44,
	 0x33, 0x33, 0x33, 0x33,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 4 - 0x0
	 0x11, 0x11, 0x11, 0x11,
	 0x33, 0x33, 0x33, 0x31,
	 0x44, 0x44, 0x44, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	// Sprite 4 - 0x1
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	// Sprite 4 - 0x2
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x44, 0x44, 0x44, 0x31,
	 0x33, 0x33, 0x33, 0x31,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 4 - 0x3
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	// Sprite 5 - 0x0
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x44,
	 0x11, 0x11, 0x14, 0x43,
	 0x11, 0x11, 0x14, 0x31,
	// Sprite 5 - 0x1
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x44, 0x44, 0x44, 0x44,
	 0x33, 0x33, 0x33, 0x33,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 5 - 0x2
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x31,
	// Sprite 5 - 0x3
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	 0x33, 0x33, 0x33, 0x33,
	// Sprite 6 - 0x0
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x44, 0x11, 0x11, 0x11,
	 0x34, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	// Sprite 6 - 0x1
	 0x11, 0x11, 0x14, 0x31,
	 0x11, 0x11, 0x14, 0x43,
	 0x11, 0x11, 0x11, 0x44,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 6 - 0x2
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	 0x13, 0x41, 0x11, 0x11,
	// Sprite 6 - 0x3
	 0x13, 0x41, 0x11, 0x11,
	 0x34, 0x41, 0x11, 0x11,
	 0x44, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 7 - 0x0	player
     0x66, 0x60, 0x0, 0x6,
	 0x66, 0x0, 0xff, 0xff,
	 0x66, 0xf, 0xf, 0xf,
	 0x63, 0xf, 0xf4, 0x43,
	 0x33, 0x32, 0x44, 0x65,
	 0x34, 0x2, 0x20, 0x23,
	 0x0, 0x21, 0x1, 0x66,
	 0x61, 0x30, 0x13, 0x16,
	// Sprite 7 - 0x1
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 7 - 0x2
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	// Sprite 7 - 0x3
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,
	 0x11, 0x11, 0x11, 0x11,

	// Sprite 8 - 0x0 palette offset 2 enemy
	 0x4f, 0x3, 0x30, 0x34,
	 0xf0, 0x30, 0x1, 0x34,
	 0xf3, 0x5, 0x5, 0x34,
	 0x3, 0x0, 0x0, 0x34,
	 0x40, 0x10, 0x1, 0x34,
	 0xf0, 0x1, 0x10, 0x4,
	 0xf0, 0x10, 0x4, 0x34,
	 0x1, 0x0, 0x0, 0x34,

	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,

	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,

	0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,

	// Sprite 9 - 0x0 palette offset 4 for red 5 for blue
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xf5, 0x55, 0x5f,
	 0xff, 0xff, 0x55, 0xff,
	 0xff, 0xf5, 0x77, 0x5f,
	 0xff, 0x57, 0x66, 0x65,
	 0xff, 0x56, 0x66, 0x65,
	 0xff, 0xf5, 0x55, 0x5f,

	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,

	 0xff, 0xf6, 0x76, 0xff,
	 0xff, 0x75, 0x65, 0x7f,
	 0xff, 0xf4, 0x54, 0xff,
	 0xff, 0x4f, 0xff, 0x4f,
	 0xff, 0x3f, 0xff, 0x3f,
	 0xff, 0x3f, 0xff, 0x3f,
	 0xff, 0xf2, 0x22, 0xff,
	 0xff, 0xff, 0xff, 0xff,

	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff,
	 0xff, 0xff, 0xff, 0xff

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
  
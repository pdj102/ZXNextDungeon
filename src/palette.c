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
// 0 - wall palette
    0x24,       
    0x29,       
    0x44,       
    0x41,       
    0x6e,       
    0x97,       
    0xFF,       
    0x0,       
    0x0,
    0x0,
    0x0,    
    0x0,
    0x0,
    0x0,    
    0x0,
    0x0,        // default transparent index

// 1 player palette
    0x24,
    0x28,
    0x2d,
    0x48,
    0x6d,
    0xd5,
    0xda,
    0xfa,
    0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

// 2 monster palette
    0x24, 0x64, 0x6d, 0x89,
	0xff, 0xd5, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0,     

// 3 not used - make a green item palette
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,  

// 4 red items
	 0x0, 0xff, 0x8c, 0xb0,
	 0xd5, 0x64, 0xa4, 0xc9,
	 0x0, 0x0, 0x0, 0x0,
	 0x0, 0x0, 0x0, 0x0,

// 5 blue items
	 0x0, 0xff, 0x8c, 0xb0,
	 0xd5, 0x1, 0x3, 0x2f,
	 0x0, 0x0, 0x0, 0x0,
	 0x0, 0x0, 0x0, 0x0,

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
    for (uint8_t i = 0 ; i < sizeof tile_palette / sizeof tile_palette[0]; i++) {
        //ZXN_WRITE_REG(0x41,i);
        ZXN_WRITE_REG(0x41, tile_palette[i]);
    }
}

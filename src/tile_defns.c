/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tile definitions

 ***************************************************/
#include "tile_defns.h"

#include <stdint.h>             // standard names for ints with no ambiguity
#include <arch/zxn.h>


// Set NUM_SPRITES to number of sprites exported x 4 
#define NUM_SPRITES 40 * 4  //40

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/
uint8_t volatile * const tile_def_base_p = (uint8_t *) 0x4a00; // 0x4a00 

// tile_pattern is defined in tile_defns_data.asm
extern uint8_t tile_pattern[];


/***************************************************
 * functions definitions
 ***************************************************/

void tile_defns_init()
{
    /* 0x6F - Tile definitions base address
     *
     * sets the tile definitions base address offset within bank 5 
     * Bank 5 is located at 0x4000 - 0x7fff
     * The ULA screen is located 0x4000 - 0x5FFF (7 KiB) 
     * The ULA screen is not required and has been disabled so we can write the tilemap at 0x4000
     * The tilemap is 2,560 (0xa00) bytes so occupies 0x4000 - 0x49ff
     * Loading the tile definitions at or above 0x4A00 avoids it
     * 0x6F is set with the MSB which represents an n x 256 byte offset. (0x4A00 - 0x4000) / 0x100 = 10 decimal 
     * 
     */
    ZXN_NEXTREG(0x6F, 10);

}
  
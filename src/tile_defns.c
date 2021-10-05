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
uint8_t volatile * const tile_def_base_p = (uint8_t *) 0x6A00;

// tile_pattern is defined in tile_defns_data.asm
extern uint8_t tile_pattern[];


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
    //for (uint16_t i = 0; i < sizeof tile_pattern / sizeof tile_pattern[0]; i++)
    //{
    //    *(tile_def_base_p+i) = tile_pattern[i];
    //}

    //for (uint16_t i = 0; i < NUM_SPRITES * 4 * 8; i++)
    //{
    //   *(tile_def_base_p+i) = tile_pattern[i];
    //}

}
  
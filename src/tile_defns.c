/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Tile definitions

**************************************************/

#include "tile_defns.h"

#include <stdint.h>             /* standard names for ints with no ambiguity */
#include <arch/zxn.h>           /* ZXN_NEXTREG */


/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions
 ***************************************************/

void tile_defns_init()
{
    /*
     * Set the ZXnext register for the base memory address of the tile definitions
     * 
     * 0x6F - Tile definitions base address
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
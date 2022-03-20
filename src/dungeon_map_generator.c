/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Dungeon map generator 

 ***************************************************/
#include "dungeon_map_generator.h"

#include <inttypes.h>
#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions     

#include "dungeon_map_generator_bank.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/
// Some handy dungeon tiles

const dungeon_tile_t tiles[] = 
{
    { {TILE_FLOOR_1, NO_MIRROR | NO_ROTATE | PALETTE_DUNGEON}, FLOOR}, // tile_FLOOR
    { {TILE_WALL_1, NO_MIRROR | NO_ROTATE | PALETTE_DUNGEON}, WALL},   // tile_WALL_1
    { {TILE_CEILING, NO_MIRROR | NO_ROTATE | PALETTE_DUNGEON}, WALL}   // tile_CEILING
};


/***************************************************
 * functions definitions
 ***************************************************/

void dungeon_map_generate()
{
    /* Map Dungeon Map Generator (bank 18) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 18);
    /* Call banked code */ 
    dungeon_map_generate_b(); 
}
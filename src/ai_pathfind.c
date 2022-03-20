/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   AI pathfinder

 ***************************************************/
#include "ai_pathfind.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions

#include "ai_pathfind_bank.h"
#include "coord_type.h"


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void ai_pathfind(uint8_t x, uint8_t y)
{
    /* Map AI (bank 19) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 19);
    /* Call banked code */    
    ai_pathfind_b(x, y);
}



direction_t ai_pathfind_direction_to_player(const coord_t *coord)
{
    /* Map AI (bank 19) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 19);
    /* Call banked code */    
    return ai_pathfind_direction_to_player_b(coord);
}
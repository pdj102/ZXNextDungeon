/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   AI 

 ***************************************************/
#include "ai.h"
#include "ai_bank.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions

#include "entity_creature.h"



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


void ai_turn(creature_t *creature_ptr)
{
    /* Map AI (bank 19) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 19);
    /* Call banked code */    
    ai_turn_b(creature_ptr); 
}
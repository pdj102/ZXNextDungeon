/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Ai code

 ***************************************************/
#include "ai.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions 

#include "ai_bank.h"

#include "globaldata.h"


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

// TODO switch bank back

void ai_init(ai_t *ai_p)
{
    /* Map Ai code (bank 26) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 26);
    /* Call banked code */ 
    ai_init_b(ai_p); 
}

void ai_turn( creature_t *creature_p )
{
    /* Map Ai code (bank 26) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 26);
    /* Call banked code */ 
    ai_turn_b( creature_p ); 
}

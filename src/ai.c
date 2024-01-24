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
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    ai_init_b(ai_p); 

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);    
}

void ai_turn( creature_t *creature_p )
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    ai_turn_b( creature_p ); 

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

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

/**
 * Notify AI of attack by another creature
 * 
 * @return void
 */
void ai_is_attacked(creature_t *target_p, creature_t *attacker_p)
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    ai_is_attacked_b( target_p, attacker_p ); 

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

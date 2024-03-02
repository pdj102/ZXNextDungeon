/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Ai code

 ***************************************************/
#include "ai.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions 

#include "ai_bank.h"

#include "object.h"

#include "creature.h"

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

void ai_init( ai_t *ai_p, creature_t *creature_p )
{
    ai_p->creature_p = creature_p;

    ai_p->state = ai_base_state(creature_p->obj_p->subtype);
    ai_p->sub_state = NO_SUB_STATE;
    ai_p->target = 0;
    ai_p->goto_x = 0;
    ai_p->goto_y = 0;
    ai_p->pathfind_page = 80 + creature_p->index;
}


void ai_turn( ai_t *ai_p )
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    ai_turn_b( ai_p ); 

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

/**
 * Notify AI of attack by another creature
 * 
 * @return void
 */
void ai_is_attacked(ai_t *ai_p, creature_t *attacker_p)
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);
    ai_is_attacked_b( ai_p, attacker_p ); 

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

ai_state_t ai_base_state(object_subtype_e subtype)
{
    uint8_t current_bank;
    ai_state_t ai_state;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);
    ai_state = ai_base_state_b( subtype ); 

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);    

    return ai_state;
}

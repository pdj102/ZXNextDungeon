/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

    Banked code. Do not call directly    

**************************************************/

#include "creature_create_bank.h"

#include <stdint.h>

#include "creature.h"
#include "object.h"

#pragma output CRT_ORG_CODE = 0xC000

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

creature_t* creature_create_b(object_t *obj_p)
{
    creature_t *creature_p;

    // get a free creature slot
    if ( ! (creature_p = creature_getfree()) )
    {
        return 0;
    }
    
    // set common object attributes
    creature_p->free = 0;
    creature_p->next = 0;
    creature_p->obj_p = obj_p;
    creature_p->energy = 0;
    creature_p->creature_class = AI;

    switch (obj_p->subtype)
    {
    case HUMANOID_HUMAN:
        creature_p->speed = 10;
        creature_p->hp = 10;
        creature_p->ac = 10;

        creature_p->melee_damage_roll.n = 1;
        creature_p->melee_damage_roll.d = 6;
        creature_p->melee_damage_roll.mod = 0;
        creature_p->melee_modifier = 0;
        break;
    case BEAST_SNAKE:
        creature_p->speed = 5;
        creature_p->hp = 15;        
        creature_p->ac = 5;
        break;
    default:
        break;
    }

    return creature_p;
}

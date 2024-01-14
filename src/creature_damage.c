/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - damage

    Attempt to apply damage to a creature

 ***************************************************/

#include <stdint.h>

#include "creature_damage.h"

#include "creature.h"

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

uint8_t creature_damage(creature_t *target_p, uint8_t base_damage, damage_type_t type)
{
    uint8_t damage;

    // TODO apply damage resistance and vulnerability
    damage = base_damage;

    if (target_p->hp > damage)
    {
        // apply damage 
        target_p->hp -= damage;
        return damage;
    }

    // Drop to zero hit points
    target_p->hp = 0;
    
    return damage;
}


/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - melee strike

    Creature attempts a melee strike on another creature

 ***************************************************/

#include <stdint.h>

#include "creature_melee_strike.h"

#include "creature.h"
#include "dice.h"

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


uint8_t creature_melee_strike(creature_t *attacker_p, creature_t *target_p)
{
    uint8_t attack_roll;
    
    // reduce attackers energy 
    attacker_p->energy -= 100;

    attack_roll = dice_1d20() + attacker_p->melee.attack_bonus;

    if (attack_roll < target_p->ac)
    {
        // Miss
        return 0;
    }
    // Hit
    return 1;
}


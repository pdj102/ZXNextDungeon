/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - melee strike

    Creature attempts a melee strike on another creature

 ***************************************************/

#include <inttypes.h>

#include "creature_melee_strike.h"

#include "creature.h"
#include "dice.h"
#include "text.h"

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
    uint8_t damage_roll;

    attacker_p->energy - 100;

    attack_roll = dice_1d20() + attacker_p->melee_modifier;

    if (attack_roll >= target_p->ac)
    {
        text_print_string("MISS\n");
        return 0;
    }
    else
    {
        text_print_string("HIT ");
        damage_roll = dice_roll(&attacker_p->melee_damage_roll) + attacker_p->melee_modifier;
        text_print_uint8(damage_roll);
        text_print_string(" POINTS DAMAGE\n");
        return 1;
    }

}


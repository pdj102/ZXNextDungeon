/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - melee strike

    Creature attempts a melee strike on another creature

 ***************************************************/

#include "creature_action_melee_strike.h"

#include <stdint.h>

#include "object_strike.h"

#include "creature.h"
#include "creature_list.h"
#include "creature_take_damage.h"

#include "globaldata.h"
#include "dice.h"
#include "text.h"
#include "util.h"

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

uint8_t creature_action_melee_strike_dir(creature_t *attacker_p, direction_t d)
{
    int8_t dx, dy;

    util_dir_to_dxdy(d, &dx, &dy);

    return creature_action_melee_strike_d(attacker_p, dx, dy);
}

uint8_t creature_action_melee_strike_d(creature_t *attacker_p, int8_t dx, int8_t dy)
{
    creature_t *target_p;
    uint8_t x, y;

    x = attacker_p->obj_p->x + dx;
    y = attacker_p->obj_p->y + dy;

    if ( target_p = creature_list_first_is_a_at(x, y, object_strike_is))
    {
        creature_action_melee_strike(attacker_p, target_p);
        return 1;
    }
    return 0;
}

uint8_t creature_action_melee_strike(creature_t *attacker_p, creature_t *target_p)
{
    uint8_t attack_roll;
    uint8_t damage_roll;
    
    // reduce attackers energy 
    attacker_p->energy = 0;

    // TODO manage negative attack bonus. Minimum attack roll is 1
    attack_roll = dice_1d20() + attacker_p->melee.attack_bonus;

    text_printf("%t STRIKES %t ", (unsigned int)attacker_p->obj_p->name_token, (unsigned int)target_p->obj_p->name_token);

    if (attack_roll < target_p->ac)
    {
        // Miss
        text_printf("AND MISSES\n");
    }
    else
    {
        // Hit
        text_printf("AND HITS\n");
    
        // TODO manage negative damage bonus. Minimum damage roll is be zero
        damage_roll = dice_roll(&target_p->melee.damage_roll) + attacker_p->melee.damage_bonus;
        creature_take_damage(target_p, damage_roll, attacker_p->melee.damage_type);
    }

    // Notify AI of attack
    if (target_p->ai_or_player == AI)
    {
        ai_is_attacked(&globaldata.ai[target_p->index], attacker_p);
    }
    return 1;
}


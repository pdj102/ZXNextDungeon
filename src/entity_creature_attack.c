/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    Creature entity attack action

 ***************************************************/
#include "entity_creature_attack.h"

#include <inttypes.h>
#include <stdio.h>          // sprintf

#include "entity.h"
#include "entity_creature.h"
#include "messages.h"



/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/


/***************************************************
 * function definitions
 ***************************************************/


uint8_t entity_creature_strike(creature_t *attacker_creature_ptr, int8_t dx, int8_t dy)
{
    int8_t attack_roll;
    int8_t dmg_roll;

    char message[40];

    creature_t *target_creature_ptr;
  
    target_creature_ptr = entity_creature_at( attacker_creature_ptr->entity_ptr->x+dx, attacker_creature_ptr->entity_ptr->y+dy );

    if (target_creature_ptr == NULL)
    {
        // no creature to strike at
        return 0;
    }

    // Attempt strike on creature

    // decrease energy by speed
    attacker_creature_ptr->entity_ptr->current_energy = (10 - attacker_creature_ptr->speed);

    // attack roll
    attack_roll = dice_roll_1d20();

    // add proficiency modifier to attack roll
    attack_roll += attacker_creature_ptr->melee_attack_1.proficiency_mod;

    // add strength ability modifier to attack roll
    attack_roll += ability_modifier(attacker_creature_ptr->strength);

    // if attack roll is negative set it to 0
    if (attack_roll < 0 ) attack_roll = 0;

    // 1         10        20        30
    // 01234567890123456789012345678901
    // AAAAAAAAAA STRIKES AT TTTTTTTTTT
    sprintf(message, "%s STRIKES AT %s", attacker_creature_ptr->name, target_creature_ptr->name);
    messages_print(message);

    // Sucessful hit?
    if ((uint8_t) attack_roll > target_creature_ptr->ac)
    {
        // todo roll for damage
        dmg_roll = dice_roll(& (attacker_creature_ptr->melee_attack_1.dmg_die) );

        // add strength ability modifier to attack roll
        dmg_roll += ability_modifier(attacker_creature_ptr->strength);

        // if dmg roll is negative set it to 0
        if (dmg_roll < 0 ) dmg_roll = 0;

        target_creature_ptr->curr_hp -= dmg_roll;

        // 012345678901234567890123456789
        // DD points damage
        sprintf(message, "%u POINTS DAMAGE", dmg_roll);
        messages_print(message);

        // Is target dead?
        if (target_creature_ptr->curr_hp <= 0)
        {
            // 012345678901234567890123456789
            // TTTTTTTTTT is killed!
            sprintf(message, "%s IS KILLED!", target_creature_ptr->name);
            messages_print(message);

            entity_creature_delete(target_creature_ptr);
        }
        else
        {
            // todo entity_event_hit();
        }
    }
    else
    {
        // Miss!
        sprintf(message, "MISS");
        messages_print(message);
    }
    return 1;
}
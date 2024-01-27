/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - damage

    Attempt to apply damage to a creature

 ***************************************************/

#include <stdint.h>

#include "creature_damage.h"

#include "creature.h"
#include "creature_destroy.h"

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

uint8_t creature_damage(creature_t *target_p, uint8_t base_damage, damage_type_t type)
{
    uint8_t damage;
    uint16_t damage_token;

    // TODO modify damage based on target resistance, immunity or vulnerability
    damage = base_damage;

    // TODO print message if resisted, immune or vulnerable

    if (damage > 0)
    {
        // Target takes damage
        // text_printf("%t TAKES ", target_p->obj_p->name_token);
        // text_printf("%u POINTS OF ", damage);
        // text_printf("%u DAMAGE\n", type);
        switch (type)
        {
        case ACID:
            damage_token = 160;
            break;

        case BLUDGEONGING:
            damage_token = 161;
            break;

        case COLD:
            damage_token = 162;
            break;

        case FIRE:
            damage_token = 163;
            break;

        case FORCE:
            damage_token = 164;
            break;

        case LIGHTNING:
            damage_token = 165;
            break;
        case PIERCING:
            damage_token = 166;
            break;

        case POSION:
            damage_token = 167;
            break;

        case SLASHING:
            damage_token = 168;
            break;

        default:
            damage_token = 169;
            break;
        }

        text_printf("%t TAKES %u POINTS OF %t DAMAGE\n", (unsigned int)target_p->obj_p->name_token, (unsigned char)damage, (unsigned int)damage_token);

        if (target_p->hp > damage)
        {
            // apply damage
            target_p->hp -= damage;
        }
        else
        {
            // Drop to zero hit points
            target_p->hp = 0;
        }

        // Is target dead?
        if (target_p->hp == 0)
        {
            text_printf("%t IS DEAD\n", target_p->obj_p->name_token);

            // Destory the creature
            creature_destroy(target_p);
        }
    }

    return damage;
}


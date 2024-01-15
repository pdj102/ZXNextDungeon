/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - strike action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_strike_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_strike.h"
#include "object_destroy.h"

#include "object_dungeon_list.h"

#include "creature.h"
#include "creature_melee_strike.h"
#include "creature_damage.h"
#include "creature_destroy.h"

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

void player_strike_b( void )
{
    int8_t dx, dy;
    uint8_t x, y;
    uint8_t damage_roll;
    uint8_t actual_damage;

    object_t *obj_p;

    creature_t *target_p;

    if (! (get_dir_or_cancel_b(&dx, &dy)) )
    {
        return;
    }

    x = globaldata.player.player_creature_p->obj_p->x + dx;
    y = globaldata.player.player_creature_p->obj_p->y + dy;

    if ( obj_p = object_dungeon_list_first_is_at(x, y, object_strike_is))
    {
        target_p = obj_p->creature_p;

        globaldata.player.player_creature_p->energy = 0;

        // Miss?
        if (!creature_melee_strike(globaldata.player.player_creature_p, target_p))
        {
            text_printf("YOU MISS THE %t\n", (uint16_t)target_p->obj_p->name_token);
        }

        // Hit
        text_printf("YOU HIT THE %t\n", (uint16_t)target_p->obj_p->name_token);

        // Roll for melee damage
        damage_roll = dice_roll(&globaldata.player.player_creature_p->melee_damage_roll) + globaldata.player.player_creature_p->melee_modifier;

        // Attempt to apply damage
        actual_damage = creature_damage(target_p, damage_roll, globaldata.player.player_creature_p->melee_damage_type);

        // Was the target immune, vulnerable or resist damage? 
        if (actual_damage == 0)
        {
            text_printf("YOUR HIT HAS NO EFFECT\n");
        }
        else if (actual_damage < damage_roll)
        {
            text_printf("IT RESISTS SOME DAMAGE\n");
        }
        else if (actual_damage > damage_roll)
        {
            text_printf("YOUR HIT CAUSES EXTRA DAMAGE\n");
        }

        text_printf("HIT POINTS %u\n", target_p->hp);

        // Is the target dead?
        if (target_p->hp == 0)
        {
            text_printf("YOU KILLED THE %t\n", (uint16_t)target_p->obj_p->name_token);
            
            // Destory the creature
            object_destroy(target_p->obj_p);
            creature_destroy(target_p);
        }
    }
}
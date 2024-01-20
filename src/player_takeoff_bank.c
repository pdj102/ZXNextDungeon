/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - takeoff an item

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_takeoff_bank.h"

#include <stdint.h>

#include "player_equipment_bank.h"
#include "player_calc_stats_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_takeoff.h"

#include "object_dungeon_list.h"

#include "creature.h"

#include "ui_stats.h"



/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
void player_takeoff_melee_b(object_t *obj_p);

void player_takeoff_ranged_b(object_t *obj_p);

void player_takeoff_wand_b(object_t *obj_p);

void player_takeoff_armour_b(object_t *obj_p);

void player_takeoff_shield_b(object_t *obj_p);

void player_takeoff_ring_b(object_t *obj_p);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void player_takeoff_b( void)
{
    object_t *obj_p;

    uint8_t obj_type;

    obj_p = player_equipment_select_object( );

    if (!obj_p)
    {
        return;
    }

    // Take off item
    if (globaldata.player.armour == obj_p)
    {
        globaldata.player.armour = 0;
    }
    else if (globaldata.player.melee_weapon == obj_p)
    {
        globaldata.player.melee_weapon = 0;
    }
    else if (globaldata.player.ranged_weapon == obj_p)
    {
        globaldata.player.ranged_weapon = 0;
    }
    else if (globaldata.player.ring_left == obj_p)
    {
        globaldata.player.ring_left = 0;
    }
    else if (globaldata.player.ring_right == obj_p)
    {
        globaldata.player.ring_right = 0;
    }
 
    globaldata.player.player_creature_p->energy = 0;
    text_printf("YOU TAKEOFF THE %t\n", (uint16_t)obj_p->name_token);

    // recalculate stats
    player_calc_stats_b();
    // update ui stats 
    ui_display_stats();
}

void player_takeoff_melee_b(object_t *obj_p)
{
    globaldata.player.melee_weapon = obj_p;
}

void player_takeoff_ranged_b(object_t *obj_p)
{
    globaldata.player.ranged_weapon = obj_p;
}

void player_takeoff_wand_b(object_t *obj_p)
{
    // TODO
}

void player_takeoff_armour_b(object_t *obj_p)
{
    globaldata.player.armour = obj_p;
}

void player_takeoff_shield_b(object_t *obj_p)
{
    // TODO check for two-handed weapon
    globaldata.player.shield = obj_p;
}

void player_takeoff_ring_b(object_t *obj_p)
{
    // TODO handle left and right hands
    globaldata.player.ring_left = obj_p;
}

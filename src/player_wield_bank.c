/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - wield an item

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_wield_bank.h"

#include <stdint.h>

#include "player_inventory_bank.h"

#include "player_calc_stats_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_wield.h"

#include "object_dungeon_list.h"

#include "creature.h"

#include "ui_stats.h"



/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
void player_wield_melee_b(object_t *obj_p);

void player_wield_ranged_b(object_t *obj_p);

void player_wield_wand_b(object_t *obj_p);

void player_wield_armour_b(object_t *obj_p);

void player_wield_shield_b(object_t *obj_p);

void player_wield_ring_b(object_t *obj_p);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void player_wield_b( void)
{
    object_t *obj_p;

    uint8_t obj_type;

    obj_p = player_inventory_select_object_is_a_b( object_wield_is );

    if (!obj_p)
    {
        return;
    }
    
    obj_type = obj_p->type;

    switch (obj_type)
    {
    case MELEE_WEAPON:
        player_wield_melee_b(obj_p);
        break;
    case RANGED_WEAPON:
        player_wield_ranged_b(obj_p);
        break;
    case WAND:
        player_wield_wand_b(obj_p);
        break;    
    case ARMOUR:
        player_wield_armour_b(obj_p);
        break;
    case SHIELD:
        player_wield_shield_b(obj_p);
        break;    
    case RING:
        player_wield_ring_b(obj_p);
        break;    
    default:
        break;
    }

    globaldata.player.player_creature_p->energy = 0;
    text_printf("You wield the %t\n", (unsigned int)obj_p->name_token);

    // recalculate stats
    player_calc_stats_b();
    // update ui stats 
    ui_display_stats();
}

void player_wield_melee_b(object_t *obj_p)
{
    globaldata.player.melee_weapon = obj_p;
}

void player_wield_ranged_b(object_t *obj_p)
{
    globaldata.player.ranged_weapon = obj_p;
}

void player_wield_wand_b(object_t *obj_p)
{
    // TODO
}

void player_wield_armour_b(object_t *obj_p)
{
    globaldata.player.armour = obj_p;
}

void player_wield_shield_b(object_t *obj_p)
{
    // TODO check for two-handed weapon
    globaldata.player.shield = obj_p;
}

void player_wield_ring_b(object_t *obj_p)
{
    // TODO handle left and right hands
    globaldata.player.ring_left = obj_p;
}

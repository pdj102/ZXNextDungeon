/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - equip an item

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_equip_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_equip.h"

#include "object_dungeon_list.h"

#include "creature.h"



/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
void player_equip_melee_b(object_t *obj_p);

void player_equip_ranged_b(object_t *obj_p);

void player_equip_wand_b(object_t *obj_p);

void player_equip_armour_b(object_t *obj_p);

void player_equip_shield_b(object_t *obj_p);

void player_equip_ring_b(object_t *obj_p);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void player_equip_b( void)
{
    object_t *obj_p;

    uint8_t obj_type;

    obj_p = select_object_from_inventory_b( object_equip_is );

    if (!obj_p)
    {
        return;
    }
    
    obj_type = obj_p->type;

    switch (obj_type)
    {
    case MELEE_WEAPON:
        player_equip_melee_b(obj_p);
        break;
    case RANGED_WEAPON:
        player_equip_ranged_b(obj_p);
        break;
    case WAND:
        player_equip_wand_b(obj_p);
        break;    
    case ARMOUR:
        player_equip_armour_b(obj_p);
        break;
    case SHIELD:
        player_equip_shield_b(obj_p);
        break;    
    case RING:
        player_equip_ring_b(obj_p);
        break;    
    default:
        break;
    }

    globaldata.player.player_creature_p->energy = 0;
    text_printf("YOU EQUIP THE %t\n", (uint16_t)obj_p->name_token);
}

void player_equip_melee_b(object_t *obj_p)
{
    globaldata.player.melee_weapon = obj_p;
}

void player_equip_ranged_b(object_t *obj_p)
{
    globaldata.player.ranged_weapon = obj_p;
}

void player_equip_wand_b(object_t *obj_p)
{
    // TODO
}

void player_equip_armour_b(object_t *obj_p)
{
    globaldata.player.armour = obj_p;
}

void player_equip_shield_b(object_t *obj_p)
{
    // TODO check for two-handed weapon
    globaldata.player.shield = obj_p;
}

void player_equip_ring_b(object_t *obj_p)
{
    // TODO handle left and right hands
    globaldata.player.ring_left = obj_p;
}

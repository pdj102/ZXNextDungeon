/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - create object

    Banked code do not call directly

**************************************************/

#include <stdint.h>
#include <adt/p_forward_list.h>

#include "object.h"
#include "object_move.h"
#include "tilemap.h"

#include "text.h"

#pragma output CRT_ORG_CODE = 0xC000

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

object_t* object_create_b(object_subtype_e subtype, uint8_t x, uint8_t y)
{
    object_t *obj_ptr;

    // get a free object slot
    if ( ! (obj_ptr = object_getfree()) )
    {
        return 0;
    }
    
    // set common object attributes
    obj_ptr->free = 0;
    obj_ptr->next = 0;    
    p_forward_list_init(&(obj_ptr->obj_list));
    obj_ptr->subtype = subtype;
    obj_ptr->x = x;     
    obj_ptr->y = y;

    switch (subtype)
    {
        case DOOR_OPEN:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = DOOR;
            obj_ptr->subtype = DOOR_OPEN;
            obj_ptr->name_token = 80;
            obj_ptr->tilemap_tile.tile_attr = PALETTE_ORANGE;
            obj_ptr->tilemap_tile.tile_id = 18;
            obj_ptr->blocking = 0;
            break;

        case DOOR_CLOSED:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = DOOR;
            obj_ptr->subtype = DOOR_CLOSED;
            obj_ptr->name_token = 90;            
            obj_ptr->tilemap_tile.tile_attr = PALETTE_ORANGE;
            obj_ptr->tilemap_tile.tile_id = 19;
            obj_ptr->blocking = 1;
            break;

        case CHEST_LARGE:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = CHEST;
            obj_ptr->subtype = CHEST_LARGE;
            obj_ptr->name_token = 91;            
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 20;
            obj_ptr->blocking = 1;
            break;

        case TRAP_NOISE:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = TRAP;
            obj_ptr->subtype = TRAP_NOISE;
            obj_ptr->name_token = 92;            
            obj_ptr->tilemap_tile.tile_attr = PALETTE_ORANGE;
            obj_ptr->tilemap_tile.tile_id = 21;
            obj_ptr->blocking = 0;
            break;              

        case HUMANOID_HUMAN:
            obj_ptr->class = CREATURE;
            obj_ptr->type = HUMANOID;
            obj_ptr->subtype = HUMANOID_HUMAN;
            obj_ptr->name_token = 110;            
            obj_ptr->tilemap_tile.tile_attr = PALETTE_BLUE;
            obj_ptr->tilemap_tile.tile_id = 129;
            obj_ptr->blocking = 1;
            break;

        case BEAST_SNAKE:
            obj_ptr->class = CREATURE;
            obj_ptr->type = BEAST;
            obj_ptr->subtype = BEAST_SNAKE;
            obj_ptr->name_token = 120;            
            obj_ptr->tilemap_tile.tile_attr = PALETTE_GREEN;
            obj_ptr->tilemap_tile.tile_id = 128;
            obj_ptr->blocking = 1;
            break;

        case PLANT_WITHERWEED:
            obj_ptr->class = CREATURE;
            obj_ptr->type = PLANTS;
            obj_ptr->subtype = PLANT_WITHERWEED;
            obj_ptr->name_token =  140;            
            obj_ptr->tilemap_tile.tile_attr = PALETTE_GREEN;
            obj_ptr->tilemap_tile.tile_id = 130;
            obj_ptr->blocking = 1;
            break;                

        case POTION_HEALING:
            obj_ptr->class = ITEM;
            obj_ptr->type = POTION;
            obj_ptr->subtype = POTION_HEALING;
            obj_ptr->name_token = 31;              
            obj_ptr->tilemap_tile.tile_attr = PALETTE_BLUE;
            obj_ptr->tilemap_tile.tile_id = 8;
            obj_ptr->blocking = 0;
            break;

        case OOZE_GREY:
            obj_ptr->class = CREATURE;
            obj_ptr->type = OOZE;
            obj_ptr->subtype = OOZE_GREY;
            obj_ptr->name_token = 130;              
            obj_ptr->tilemap_tile.tile_attr = PALETTE_BLUE;
            obj_ptr->tilemap_tile.tile_id = 'o';
            obj_ptr->blocking = 1;
            break;

        case OOZE_SLIME:
            obj_ptr->class = CREATURE;
            obj_ptr->type = OOZE;
            obj_ptr->subtype = OOZE_SLIME;
            obj_ptr->name_token = 131;              
            obj_ptr->tilemap_tile.tile_attr = PALETTE_GREEN;
            obj_ptr->tilemap_tile.tile_id = 'o';
            obj_ptr->blocking = 1;
            break;

        case POTION_SPEED:
            obj_ptr->class = ITEM;
            obj_ptr->type = POTION;
            obj_ptr->subtype = POTION_SPEED;
            obj_ptr->name_token = 32;            
            obj_ptr->tilemap_tile.tile_attr = PALETTE_GREEN;
            obj_ptr->tilemap_tile.tile_id = 8;
            obj_ptr->blocking = 0;            
            break;

        case RING_HP:
            obj_ptr->class = ITEM;
            obj_ptr->type = RING;
            obj_ptr->subtype = RING_HP;
            obj_ptr->name_token = 71;
            obj_ptr->attr_1 = 2;                  
            obj_ptr->tilemap_tile.tile_attr = PALETTE_BLUE;
            obj_ptr->tilemap_tile.tile_id = 17;
            obj_ptr->blocking = 0;            
            break;            

        default:
            obj_ptr->class = ITEM;
            obj_ptr->type = RING;
            obj_ptr->subtype = RING_HP;
            obj_ptr->attr_1 = 0;
            obj_ptr->name_token = 71;            
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = '?';
            obj_ptr->blocking = 1; 
            break;             
    }
    return obj_ptr;
}
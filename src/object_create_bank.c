/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - create object

    Banked code do not call directly

**************************************************/

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "object.h"
#include "tilemap.h"

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


// TO DO move into  bank code for creating objects 
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
    obj_ptr->x = x;
    obj_ptr->y = y;

    switch (subtype)
    {
        case DOOR_OPEN:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = DOOR;
            obj_ptr->subtype = DOOR_OPEN;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 45;
            obj_ptr->blocking = 0;
            break;

        case DOOR_CLOSED:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = DOOR;
            obj_ptr->subtype = DOOR_CLOSED;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 43;
            obj_ptr->blocking = 1;
            break;

        case CHEST_LARGE:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = CHEST;
            obj_ptr->subtype = CHEST_LARGE;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 38;
            obj_ptr->blocking = 1;
            break;

        case TRAP_NOISE:
            obj_ptr->class = PHYSICAL;
            obj_ptr->type = TRAP;
            obj_ptr->subtype = TRAP_NOISE;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 37;
            obj_ptr->blocking = 0;
            break;              

        case HUMANOID_HUMAN:
            obj_ptr->class = CREATURE;
            obj_ptr->type = HUMANOID;
            obj_ptr->subtype = HUMANOID_HUMAN;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 42;
            obj_ptr->blocking = 1;
            break;

        case BEAST_SNAKE:
            obj_ptr->class = CREATURE;
            obj_ptr->type = BEAST;
            obj_ptr->subtype = BEAST_SNAKE;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 83;
            obj_ptr->blocking = 1;
            break;       

        case POTION_HEALING:
            obj_ptr->class = ITEM;
            obj_ptr->type = POTION;
            obj_ptr->subtype = POTION_HEALING;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 80;
            obj_ptr->blocking = 0;
            break;

        case POTION_SPEED:
            obj_ptr->class = ITEM;
            obj_ptr->type = POTION;
            obj_ptr->subtype = POTION_SPEED;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 80;
            obj_ptr->blocking = 0;            
            break;

        default:
            obj_ptr->class = ITEM;
            obj_ptr->type = POTION;
            obj_ptr->subtype = POTION_SPEED;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 35;
            obj_ptr->blocking = 1; 
            break;             
    }
    return obj_ptr;
}
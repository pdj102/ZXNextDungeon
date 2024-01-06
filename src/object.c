/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

**************************************************/

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "object.h"
#include "object_list.h"
#include "globaldata.h"
#include "tilemap.h"
#include "dungeonmap.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

object_t* object_getfree();

void object_free(object_t *obj_tofree);


/***************************************************
 * private variables - static
 ***************************************************/

// helper pointer to the global object data array
// TO DO make static
object_t *const objects = &globaldata.objects[0];

/***************************************************
 * functions
 ***************************************************/

void object_init()
{
    for (uint8_t i = 0; i < MAX_OBJECT; i++)
    {
        objects[i].free = 1;
    }
}



// TO DO move into  bank code for creating objects 
object_t* object_create(object_subtype_e subtype, uint8_t x, uint8_t y)
{
    object_t *obj_ptr;

    // get a free object slot
    if ( ! (obj_ptr = object_getfree()) )
    {
        return obj_ptr;
    }
    
    // set common object attributes
    obj_ptr->free = 0;
    // obj_ptr->obj_list = 0;
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

        case HUMANOID_HUMAN:
            obj_ptr->class = CREATURE;
            obj_ptr->type = HUMANOID;
            obj_ptr->subtype = HUMANOID_HUMAN;
            obj_ptr->tilemap_tile.tile_attr = 0;
            obj_ptr->tilemap_tile.tile_id = 42;
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

object_t* object_getfree()
{
    for (uint8_t i = 0; i < MAX_OBJECT; i++)
    {
        if (objects[i].free)
        {
            return &objects[i];
        }
    }
    // no free object slot
    return 0;
}

void object_free(object_t *obj_p)
{
       obj_p->free = 1;
}

void object_destroy(object_t *obj_p)
{
    text_print_string("DESTROY OBJ");
    // destroy objects contained by this object
    object_t *obj_ptr = object_list_first(obj_p);

    while (obj_ptr)
    {
        object_destroy(obj_ptr);
        obj_ptr = object_list_next(obj_ptr);
    }
    // free the object
    object_free(obj_p);
}
/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

**************************************************/

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "object.h"
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


/***************************************************
 * private variables - static
 ***************************************************/

// helper pointer to the global object data array
// TO DO make static
object_t *const objects = &globaldata.objects[0];

// List of in use objects
static p_forward_list_t dungeon_object_list; 

/***************************************************
 * functions
 ***************************************************/

void object_init()
{
    p_forward_list_init(&dungeon_object_list);

    for (uint8_t i = 0; i < MAX_OBJECT; i++)
    {
        objects[i].free = 1;
    }
}

uint8_t object_add_to_dungeon_list(object_t* obj_ptr)
{
    // Object must not belong to another list
    // This partially checks for this but if object is last object in a list this check will not spot this
    /*
    if (obj_ptr->next !=0)
    {
        return 0;
    }
    */
    p_forward_list_push_front(&dungeon_object_list, &obj_ptr->next);
    return 1;
}

uint8_t object_remove_from_dungeon_list(object_t* obj_ptr)
{
    p_forward_list_remove(&dungeon_object_list, &obj_ptr->next);
    return 1;
}

uint8_t object_add_object_to_object_list(object_t* obj_ptr, object_t* obj_container_ptr)
{
    p_forward_list_push_front(&obj_container_ptr->obj_list, &obj_ptr->next);

    return 1;
}

uint8_t object_remove_object_from_object_list(object_t* obj_ptr, object_t* obj_container_ptr)
{
    p_forward_list_remove(&obj_container_ptr->obj_list, &obj_ptr->next);
    return 1;
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
    obj_ptr->obj_list = 0;
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

void object_xy(object_t *obj, uint8_t x, uint8_t y)
{
    obj->x = x;
    obj->y = y;
}

uint8_t object_isblocking(uint8_t x, uint8_t y)
{
    object_t *object_ptr;

    for (object_ptr = p_forward_list_front(&dungeon_object_list); object_ptr; object_ptr = p_forward_list_next(object_ptr))
    {
        if (!object_ptr->blocking)
        {
            continue;
        }
        if (object_ptr->x == x && object_ptr->y == y)
        {
            return 1;
        }
    }
    return 0;
}

void object_drawall()
{
    object_t *obj_ptr;

    for (obj_ptr = p_forward_list_front(&dungeon_object_list); obj_ptr; obj_ptr = p_forward_list_next(obj_ptr))
    {
        dungeonmap_draw_single_tile(obj_ptr->x, obj_ptr->y, &obj_ptr->tilemap_tile);
    }    
}

object_t *object_dungeon_list_first()
{
    return p_forward_list_front(&dungeon_object_list);
}

object_t *object_list_first(object_t *obj_ptr)
{
    return p_forward_list_front(&obj_ptr->obj_list);
}

object_t *object_list_next(object_t *obj_ptr)
{
    return p_forward_list_next(obj_ptr);
}
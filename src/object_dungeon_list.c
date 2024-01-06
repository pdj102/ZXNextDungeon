/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon list of objects

**************************************************/

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "object.h"
#include "object_dungeon_list.h"
#include "globaldata.h"
#include "tilemap.h"
#include "dungeonmap.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/


/***************************************************
 * private variables - static
 ***************************************************/

// List of dungeon objects
static p_forward_list_t dungeon_object_list; 

/***************************************************
 * functions
 ***************************************************/

void object_dungeon_list_init()
{
    p_forward_list_init(&dungeon_object_list);
}

void object_dungeon_list_add(object_t* obj_ptr)
{
    p_forward_list_push_front(&dungeon_object_list, &obj_ptr->next);
}

uint8_t object_dungeon_list_remove(object_t* obj_ptr)
{
    p_forward_list_remove(&dungeon_object_list, &obj_ptr->next);
    return 1;
}

uint8_t object_dungeon_list_isblocking_at(uint8_t x, uint8_t y)
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

void object_dungeon_list_drawall()
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

object_t *object_dungeon_list_next(object_t *obj_ptr)
{
    return p_forward_list_next(obj_ptr);
}
/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon list of objects

**************************************************/

#include <stdint.h>
#include <adt/p_forward_list.h>

#include "object.h"
#include "object_dungeon_list.h"
#include "globaldata.h"
#include "dungeonmap.h"

#include "util.h"

/***************************************************
 * private types
 ***************************************************/
// Typedef for object_is functions
// typedef int (*object_is_a_t)(object_t *);
typedef void (*object_is_a_t)( void);

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions
 ***************************************************/

void object_dungeon_list_init( void )
{
    p_forward_list_init(&globaldata.dungeon_object_list); 
}

void object_dungeon_list_add(object_t *const obj_ptr)
{
    util_assert(obj_ptr->next == 0);        // assert object is not a member of a linked list 

    p_forward_list_push_front(&globaldata.dungeon_object_list, obj_ptr);
}

uint8_t object_dungeon_list_remove(object_t *const obj_ptr)
{
    p_forward_list_remove(&globaldata.dungeon_object_list, obj_ptr);
    obj_ptr->next = 0;       // Set linked list *next to NULL to indicate object is safe to delete

    return 1;
}

uint8_t object_dungeon_list_isblocking_at(uint8_t x, uint8_t y)
{
    object_t *object_ptr;

    for (object_ptr = p_forward_list_front(&globaldata.dungeon_object_list); object_ptr; object_ptr = p_forward_list_next(object_ptr))
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

void object_dungeon_list_drawall( void )
{
    object_t *obj_ptr;

    for (obj_ptr = p_forward_list_front(&globaldata.dungeon_object_list); obj_ptr; obj_ptr = p_forward_list_next(obj_ptr))
    {
        dungeonmap_draw_single_tile(obj_ptr->x, obj_ptr->y, &obj_ptr->tilemap_tile);
    }    
}

object_t *object_dungeon_list_first( void )
{
    return p_forward_list_front(&globaldata.dungeon_object_list);
}

object_t *object_dungeon_list_next(object_t *const obj_ptr)
{
    return p_forward_list_next(obj_ptr);
}

object_t *object_dungeon_list_first_at(uint8_t x, uint8_t y)
{
    object_t *obj_p;

    for (obj_p = object_dungeon_list_first(); obj_p; obj_p = object_dungeon_list_next(obj_p))
    {
        if (obj_p->x == x && obj_p->y == y)
        {
            return obj_p;
        }
    }
    return 0;
}

object_t *object_dungeon_list_next_at(object_t *obj_p, uint8_t x, uint8_t y)
{
    while (obj_p = object_dungeon_list_next(obj_p))
    {
        if (obj_p->x == x && obj_p->y == y)
        {
            return obj_p;
        }
    }
    return 0;
}

object_t *object_dungeon_list_first_is_at(uint8_t x, uint8_t y, object_is_a is_a_p)
{
    object_t *obj_p = object_dungeon_list_first_at(x, y);

    while( obj_p )
    {
        if (is_a_p(obj_p))
        {
            return obj_p;
        }
        obj_p = object_dungeon_list_next_at(obj_p, x, y);
    }
    return 0;
}

object_t *object_dungeon_list_next_is_at(object_t *obj_p, uint8_t x, uint8_t y, object_is_a is_a_p)
{
    while ( obj_p = object_dungeon_list_next_at(obj_p, x, y) )
    {
        if (is_a_p(obj_p))
        {
            return obj_p;
        }
    }
    return 0;
}

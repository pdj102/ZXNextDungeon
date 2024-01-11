/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

**************************************************/

#include <stdint.h>
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

void object_free(object_t *obj_tofree);


/***************************************************
 * private variables - static
 ***************************************************/

// helper pointer to the global object data array
static object_t *const objects = &globaldata.objects;

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

void object_delete(object_t *obj_p)
{
    // destroy objects contained by this object
    object_t *obj_ptr = object_list_first(obj_p);

    while (obj_ptr)
    {
        object_delete(obj_ptr);
        obj_ptr = object_list_next(obj_ptr);
    }
    // free the object
    object_free(obj_p);
}
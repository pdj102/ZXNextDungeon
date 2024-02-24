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

#include "util.h"

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
// static object_t *objects = &globaldata.objects[];

/***************************************************
 * functions
 ***************************************************/

void object_init( void )
{
    for (uint8_t i = 0; i < MAX_OBJECT; i++)
    {
        globaldata.objects[i].free = 1;
    }
}

object_t* object_getfree( void )
{
    for (uint8_t i = 0; i < MAX_OBJECT; i++)
    {
        if (globaldata.objects[i].free)
        {
            return &globaldata.objects[i];
        }
    }
    // no free object slot
    return 0;
}

void object_free(object_t *const obj_p)
{
    util_assert(obj_p->free != 1);      // assert object is not marked free
    util_assert(obj_p->next == 0);      // assert object linked list pointer is NULL 

    obj_p->free = 1;                    // free the creature slot

}
/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - destroy

**************************************************/
#include <stdint.h>

#include "object_destroy.h"

#include "object.h"
#include "object_list.h"
#include "dungeonmap_list.h"

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

uint8_t object_destroy_is(object_t *obj_p)
{
    // Everything can be destroyed
    return 1;
}

uint8_t object_destroy(object_t *obj_p)
{
    dungeonmap_list_remove(obj_p);          // remove object from list of dungeon objects
    object_free(obj_p);                         // mark object slot as free

    // destroy any objects contained by this object
    object_t *obj_ptr = object_list_first(obj_p);

    while (obj_ptr)
    {
        object_destroy(obj_ptr);
        obj_ptr = object_list_first(obj_p);     // get next using list_first instead of list_next as destroying an object resets its link list pointer to NULL and cannot be used
    }
    return 1;
}
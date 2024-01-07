/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - destroy

**************************************************/
#include <inttypes.h>

#include "object_destroy.h"

#include "object.h"
#include "object_dungeon_list.h"

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

uint8_t object_destroy_is(object_t *obj)
{
    // Everything can be destroyed
    return 1;
}

uint8_t object_destroy(object_t *obj_todestroy)
{

    object_dungeon_list_remove(obj_todestroy);
    object_delete(obj_todestroy);

    return 1;
}
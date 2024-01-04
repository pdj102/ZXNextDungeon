/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - destroy

**************************************************/
#include <inttypes.h>

#include "object_action_destroy.h"

#include "object.h"

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

uint8_t object_action_is_destroy(object_t *obj)
{
    // Everything can be destroyed
    return 1;
}

uint8_t object_action_destroy(object_t *obj_todestroy)
{
    object_t    obj_ptr;

    object_remove_from_dungeon_list(obj_todestroy);

    object_destroy(obj_todestroy);

    return 1;
}


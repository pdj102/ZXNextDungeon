/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - step on

**************************************************/
#include <inttypes.h>

#include "object_action_stepon.h"

#include "object.h"
#include "object_dungeon_list.h"
#include "text.h"

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


uint8_t object_action_is_stepon(object_t *obj_p)
{
    switch (obj_p->type)
    {
        case TRAP:
            return 1;
        default:
            return 0;
    }
}


uint8_t object_action_stepon(object_t *obj_p)
{
    text_print_string("BANG");

    return 1;
}


void *object_action_stepon_all(uint8_t x, uint8_t y)
{
    object_t *obj_p;

    for (obj_p = object_dungeon_list_first_at(x, y); obj_p; obj_p = object_dungeon_list_next_at(obj_p, x, y))
    {
        if (object_action_is_stepon(obj_p))
        {
            object_action_stepon(obj_p);
        }
    }
}

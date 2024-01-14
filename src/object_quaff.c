/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - quaff

**************************************************/
#include <stdint.h>

#include "object_quaff.h"

#include "object.h"
#include "object_list.h"

#include "creature.h"

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

uint8_t object_quaff_is(const object_t *obj_p)
{
    switch (obj_p->type)
    {
    case POTION:
        return 1;
    default:
        return 0;
    }
}

uint8_t object_quaff(creature_t *creature_p, object_t *obj_p)
{
    switch (obj_p->subtype)
    {
    case POTION_HEALING:
        creature_p->hp++;

        object_list_remove(obj_p, creature_p->obj_p);
        object_delete(obj_p);

        return 1;
    default:
        return 0;
    }
}
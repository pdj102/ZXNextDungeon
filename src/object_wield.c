/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - wield

**************************************************/
#include <stdint.h>

#include "object_wield.h"

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

uint8_t object_wield_is(const object_t *obj_p)
{
    switch (obj_p->type)
    {
    case MELEE_WEAPON:
    case RANGED_WEAPON:
    case WAND:
    case ARMOUR:
    case SHIELD:
    case RING:
        return 1;
    default:
        return 0;
    }
}


/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - destroy

**************************************************/
#include <stdint.h>

#include "object_destroy.h"

#include "creature.h"
#include "creature_list.h"

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

uint8_t creature_destroy_is(creature_t *creature_p)
{
    // Everything can be destroyed
    return 1;
}

uint8_t creature_destroy(creature_t *creature_p)
{
    // Destroy the creature's object
    object_destroy(creature_p->obj_p);

    // Remove creature from the creature list
    creature_list_remove(creature_p);

    // Free the creature slot
    creature_free(creature_p);

    return 1;
}
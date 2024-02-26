/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - remove

**************************************************/

#include "object_remove.h"

#include <stdint.h>

#include "object.h"

#include "dungeonmap.h"
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


void object_remove(object_t *const obj_p)
{

    // Add object to dungeon map list
    dungeonmap_list_remove(obj_p);

    // Reset the object flags
    dungeonmap_setobjflags(obj_p->x, obj_p->y);
}
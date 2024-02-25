/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - strike

**************************************************/
#include <stdint.h>

#include "object_strike.h"

#include "object.h"
#include "object_list.h"

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

uint8_t object_strike_is(object_t *obj_p)
{
    // All creatures can be striked 
    if (obj_p->class == CREATURE)
    {
        return 1;
    }
    // Everything else cannot
    return 0;
}

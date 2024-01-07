/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon list of creatures

**************************************************/

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "text.h"

#include "creature.h"

#include "globaldata.h"

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

void creature_list_init()
{
    p_forward_list_init(&globaldata.creature_list);
}

void creature_list_add(creature_t *creature_p)
{
    p_forward_list_push_front(&globaldata.creature_list, creature_p);
}

uint8_t creature_list_remove(creature_t *creature_p)
{
    p_forward_list_remove(&globaldata.creature_list, creature_p);
    return 1;
}

creature_t *creature_list_first()
{
    return p_forward_list_front(&globaldata.creature_list);
}

creature_t *creature_list_next(creature_t *creature_p)
{
    return p_forward_list_next(creature_p);
}

void creature_list_update_all()
{
    creature_t *creature_p;
    
    for (creature_p = p_forward_list_front(&globaldata.creature_list); creature_p; creature_p = p_forward_list_next(creature_p))
    {
        creature_turn(creature_p);
    }    
}


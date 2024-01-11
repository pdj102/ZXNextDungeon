/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief List of timed events

**************************************************/

#include <stdint.h>
#include <adt/p_forward_list.h>

#include "event.h"

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

void event_list_init()
{
    p_forward_list_init(&globaldata.event_list);
}

void event_list_add(event_t *event_p)
{
    p_forward_list_push_front(&globaldata.event_list, event_p);
}

uint8_t event_list_remove(event_t *event_p)
{
    p_forward_list_remove(&globaldata.event_list, event_p);
    return 1;
}

event_t *event_list_first()
{
    return p_forward_list_front(&globaldata.event_list);
}

event_t *event_list_next(event_t *event_p)
{
    return p_forward_list_next(event_p);
}

void event_list_update_all()
{
    event_t *event_p;

    for (event_p = p_forward_list_front(&globaldata.event_list); event_p; event_p = p_forward_list_next(event_p))
    {
        if (event_update(event_p))
        {
            // event fired. Remove from list
            event_list_remove(event_p);
        }
    }    
}


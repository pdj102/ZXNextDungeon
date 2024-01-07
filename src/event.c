/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Time event

 ***************************************************/
#include "event.h"

#include <inttypes.h>

#include "globaldata.h"

#include "text.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

event_t* event_getfree();

void event_free(event_t *event_p);

/***************************************************
 * private variables - static
 ***************************************************/
// helper pointer to the global event 
static event_t *const events = &globaldata.events[0];

/***************************************************
 * functions definitions
 ***************************************************/

void event_init()
{
    for (uint8_t i = 0; i < MAX_EVENT; i++)
    {
        events[i].free = 1;
    }
}

event_t *event_create(event_callback cb, uint8_t ticks)
{
    event_t *event_p;

    // get a free event slot
    if ( ! (event_p = event_getfree()) )
    {
        return 0;
    }
    
    // set common object attributes
    event_p->free = 0;
    event_p->next = 0;

    event_p->ticks = ticks;
    event_p->cb = cb;

    return event_p;
}

void event_decrement(event_t *event_p)
{
    (event_p->ticks)--;

    if (event_p->ticks == 0)
    {
        text_print_string("EVENT FIRED");
        event_p->cb();
    }
}


event_t* event_getfree()
{
    for (uint8_t i = 0; i < MAX_EVENT; i++)
    {
        if (events[i].free)
        {
            return &events[i];
        }
    }
    // no free object slot
    return 0;
}

void event_free(event_t *event_p)
{
       event_p->free = 1;
}

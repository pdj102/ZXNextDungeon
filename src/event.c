/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Timed event

 ***************************************************/
#include "event.h"

#include <stdint.h>

#include "globaldata.h"

#include "text.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

event_t* event_getfree( void );

void event_free(event_t *event_p);

/***************************************************
 * private variables - static
 ***************************************************/
// helper pointer to the global event 
// static event_t *const events = &globaldata.events[0];

/***************************************************
 * functions definitions
 ***************************************************/

void event_init()
{
    for (uint8_t i = 0; i < MAX_EVENT; i++)
    {
        globaldata.events[i].free = 1;
        globaldata.events[i].next = 0;
    }
}

// event_t *event_create(event_callback cb, uint8_t ticks)
event_t *event_create_object_cb(event_callback cb, object_t *obj_p, uint8_t turns)
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

    event_p->cb = cb;
    event_p->obj_p = obj_p;
    event_p->turns = turns;
    event_p->ticks = 0;

    return event_p;
}

uint8_t event_update(event_t *event_p)
{
    if (event_p->turns == 0)
    {
        text_print_string("EVENT FIRED\n");
        event_p->cb(event_p->obj_p);
        event_free(event_p);

        return 1;
    }
    
    if (event_p->ticks >= 10)
    {
        event_p->ticks -= 10;
    }
    else
    {
        event_p->ticks = 100;
        event_p->turns -= 1;
    }    
    return 0;
}


event_t* event_getfree()
{
    for (uint8_t i = 0; i < MAX_EVENT; i++)
    {
        if (globaldata.events[i].free)
        {
            return &globaldata.events[i];
        }
    }
    // no free object slot
    return 0;
}

void event_free(event_t *event_p)
{
       event_p->free = 1;
}

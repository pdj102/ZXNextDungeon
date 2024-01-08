/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Timed event

    Time is based on turns and ticks

    1 turn = 100 ticks

    Game time progresses by 10 ticks per game loop

    An average cretrure will take 1 action per turn

 ***************************************************/

#ifndef EVENT_H 
    #define EVENT_H 

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "object.h"

#define MAX_EVENT  20


/***************************************************
 * types
 ***************************************************/

typedef uint8_t (*event_callback)(object_t *);

typedef struct event_s
{
    void                    *next;              
    uint8_t                 free;               /**< 1 if event slot is free */
    uint8_t                 ticks;              /**< number of ticks */
    uint8_t                 turns;              /**< number of turns */
    event_callback          cb;                 /**< call back function - object action */
    object_t                *obj_p;             /**< call back function - object*/
} event_t;



/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the object data structure. Must be called before using Object 
 * 
 * @return void
 */
void event_init();

/**
 * Create an event  
 *
 * @param cb        call back function
 * @param *obj_p    call back function obj_p data
 * @param turns     timer number of turns
 * 
 * @return pointer to created event or NULL on failed to create
 */
event_t *event_create_object_cb(event_callback cb, object_t *obj_p, uint8_t turns);

/**
 * Update event timer and if triggered call callback function and delete event.  
 * 
 * @param   *event_p  Event
 * 
 * @return  1 if event fired (e.g. need to delete the event from the event list) or 0
 */
uint8_t event_update(event_t *event_p);

#endif
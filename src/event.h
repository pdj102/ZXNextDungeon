/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Timed event

 ***************************************************/

#ifndef EVENT_H 
    #define EVENT_H 

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "object.h"

#define MAX_EVENT  40


/***************************************************
 * types
 ***************************************************/

typedef uint8_t (*event_callback)(object_t *);

typedef struct event_s
{
    void                    *next;              
    uint8_t                 free;               /**< 1 if event slot is free */
    uint8_t                 ticks;
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
 * @param ticks     timer number of turns
 * 
 * @return pointer to created event or NULL on failed to create
 */
event_t *event_create_object_cb(event_callback cb, object_t *obj_p, uint8_t ticks);

/**
 * Update event timer and if triggered call callback function and delete event.  
 * 
 * @param   *event_p  Event
 */
void event_update(event_t *event_p);

#endif
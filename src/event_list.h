/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief List of timed events

 ***************************************************/

#ifndef EVENT_LIST_H 
    #define EVENT_LIST_H 

#include <inttypes.h>

#include "event.h"


/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the event list. Must be called before using the list
 * 
 * @return void
 */
void event_list_init();

/**
 * Add an object to the list
 *
 * @param *event_t pointer to event
 * 
 * @return uint8_t  1 success 0 fail
 */
void event_list_add(event_t* event_p);

/**
 * Remove the event from the list 
 *
 * @param *event_p pointer to event
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t event_list_remove(event_t* event_p);

/**
 * Returns the first event in the event list
 * 
 * @return *event_t    pointer to first object or 0 if no objects
 */
event_t *event_list_first();

/**
 * Returns the next event in the event  list
 * 
 * @return *object_t    pointer to next object or 0 if no more objects
 */
event_t *event_list_next(event_t *obj_ptr);

/**
 * Update all event timers. If triggered call callback function and delete event.  
 * 
 */
void event_list_update_all();

#endif
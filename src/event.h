/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Time event

 ***************************************************/

#ifndef EVENT_H 
    #define EVENT_H 

#include <inttypes.h>
#include <adt/p_forward_list.h>

#define MAX_EVENT  40


/***************************************************
 * types
 ***************************************************/

typedef void (*event_callback)(void);

typedef struct event_s
{
    void                    *next;              
    uint8_t                 free;               /**< 1 if event slot is free */
    uint8_t                 ticks;
    event_callback          cb;
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
 * @return pointer to created event or NULL on failed to create
 */
event_t *event_create(event_callback cb, uint8_t ticks);

/**
 * Event decrement timer
 * 
 * @param   *event_p  Event
 */
void event_decrement(event_t *event_p);

#endif
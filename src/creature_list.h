/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief @brief List of creatures

 ***************************************************/

#ifndef CREATURE_LIST_H 
    #define CREATURE_LIST_H 

#include <stdint.h>

#include "creature.h"


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
 * Initialises the creature list. Must be called before using the list
 * 
 * @return void
 */
void creature_list_init( void );

/**
 * Add a creature to the list
 *
 * @param *creature_t pointer to creature
 * 
 * @return uint8_t  1 success 0 fail
 */
void creature_list_add(creature_t* creature_p);

/**
 * Remove the creature from the list 
 *
 * @param *creature_p pointer to creature
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t creature_list_remove(creature_t* creature_p);

/**
 * Returns the first creature in the creature list
 * 
 * @return *creature_t    pointer to first creature or 0 if no creatures
 */
creature_t *creature_list_first( void );

/**
 * Returns the next creature in the creature  list
 * 
 * @return *creature_t    pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_next(creature_t *obj_ptr);

/**
 * All creatures take a turn
 * 
 */
void creature_list_update_all( void );

#endif
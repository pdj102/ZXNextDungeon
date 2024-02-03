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
 * Returns the first creature in the creature list at location x, y
 * 
 * @param x                 dungeon x position
 * @param y                 dungeon y position
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_first_at(uint8_t x, uint8_t y);

/**
 * Returns the next creature in the creature list at location x, y
 * 
 * @param creature_p        pointer to previously returned creature from list
 * @param x                 dungeon x position
 * @param y                 dungeon y position
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_next_at(creature_t *creature_p, uint8_t x, uint8_t y);

/**
 * Returns the first creature in the creature list at location x, y and is_a function returns true
 * 
 * @param x                 dungeon x position
 * @param y                 dungeon y position
 * @param is_a_p            pointer to is_a function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_first_is_a_at(uint8_t x, uint8_t y, object_is_a is_a_p);

/**
 * Returns the next creature in the creature list at location x, y and is_a function returns true
 *
 * @param creature_p        pointer to previously returned creature from list 
 * @param x                 dungeon x position
 * @param y                 dungeon y position
 * @param is_a_p            pointer to is_a function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_next_is_a_at(creature_t *creature_p, uint8_t x, uint8_t y, object_is_a is_a_p);

/**
 * Returns the first creature in the creature list within rect x1, y1, x2, y2 and is_a function returns true
 * 
 * @param x1                dungeon x1 position
 * @param y1                dungeon y1 position
 * @param x2                dungeon x2 position
 * @param y2                dungeon y2 position
 * @param is_a_p            pointer to is_a function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_first_is_a_within_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_is_a is_a_p);

/**
 * Returns the next creature in the creature list within rect x1, y1, x2, y2 and is_a function returns true
 *
 * @param creature_p        pointer to previously returned creature from list 
 * @param x1                dungeon x1 position
 * @param y1                dungeon y1 position
 * @param x2                dungeon x2 position
 * @param y2                dungeon y2 position
 * @param is_a_p            pointer to is_a function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_next_is_a_within_rect(creature_t *creature_p, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_is_a is_a_p);

/**
 * Returns the first creature in the creature list within rect x1, y1, x2, y2 and is_a2 function returns true
 * 
 * @param x1                dungeon x1 position
 * @param y1                dungeon y1 position
 * @param x2                dungeon x2 position
 * @param y2                dungeon y2 position
 * @param agent_p           the agent creature 
 * @param is_a2_p           pointer to is_a2 function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_first_is_a2_within_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_t *agent_p, creature_is_a2 is_a2_p);

/**
 * Returns the next creature in the creature list within rect x1, y1, x2, y2 and is_a2 function returns true
 *
 * @param creature_p        pointer to previously returned creature from list 
 * @param x1                dungeon x1 position
 * @param y1                dungeon y1 position
 * @param x2                dungeon x2 position
 * @param y2                dungeon y2 position
 * @param agent_p           the agent creature 
 * @param is_a2_p           pointer to is_a2 function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_next_is_a2_within_rect(creature_t *creature_p, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_t *agent_p, creature_is_a2 is_a2_p);

/**
 * Returns the first creature in the creature list within square x +/- r, y +/- r and is_a2 function returns true
 * 
 * @param x1                dungeon x1 position
 * @param y1                dungeon y1 position
 * @param r                 range r. square is 2r
 * @param agent_p           the agent creature 
 * @param is_a2_p           pointer to is_a2 function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_first_is_a2_within_square(uint8_t x, uint8_t y, uint8_t r, creature_t *agent_p, creature_is_a2 is_a2_p);

/**
 * Returns the next creature in the creature list within square x +/- r, y +/- r and is_a2 function returns true
 *
 * @param creature_p        pointer to previously returned creature from list 
 * @param x1                dungeon x1 position
 * @param y1                dungeon y1 position
 * @param r                 range 2. square is 2r
 * @param agent_p           the agent creature 
 * @param is_a2_p           pointer to is_a2 function to test
 * @return *creature_t      pointer to next creature or 0 if no more creatures
 */
creature_t *creature_list_next_is_a2_within_square(creature_t *creature_p, uint8_t x, uint8_t y, uint8_t r, creature_t *agent_p, creature_is_a2 is_a2_p);

/**
 * All creatures take a turn
 * 
 */
void creature_list_update_all( void );

#endif
/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Item entity

 ***************************************************/

#ifndef ITEM_CREATURE_H 
    #define ITEM_CREATURE_H 

#include <inttypes.h>

#include "entity.h"

/***************************************************
 * public types
 ***************************************************/
typedef enum { RING } item_type_t;

typedef struct {
    uint8_t record;             /**< if 0  record is available for use or array index + 1 if in use. */

    entity_t    *entity_ptr;    /**< pointer back to entity */
    char        name[15];
    uint8_t     dummy;
    uint8_t     dummy2;
    uint8_t     dummy3;

} item_t;

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief Init items
 *
 * @return void
 */
void entity_item_init();

/**
 * @brief Returns an item of type i
 * 
 * @param i  item type
 * @return pointer to item
 */
item_t *entity_item_create(item_type_t item_type, uint8_t x, uint8_t y);

/**
 * @brief Prints item stat block to screen
 * 
 * TODO implement function
 * 
 * @param *item_ptr  pointer to creature
 * @return void
 */
void entity_item_draw_stat_block(const item_t *item_ptr);

/**
 * @brief Returns the first item at dungeon position x, y or NULL is no item
 * 
 * @param x position x
 * @param y position y
 * 
 * @return item_t 
 */
item_t *entity_item_first_at(uint8_t x, uint8_t y);

/**
 * @brief Returns next item at dungeon position.
 * 
 * Can be called repeatably to find all items at dungeon location
 * 
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @param item_ptr previously found item
 * @return next item at position or NULL
 */
item_t* entity_item_next_at(uint8_t x, uint8_t y, const item_t *item_ptr);

/**
 * @brief Returns the first item at location or NULL if no item
 * 
 * @param location  location
 * 
 * @return item_t 
 */
item_t *entity_item_first_at_location(entity_location_t location);

/**
 * @brief Returns the next item at location or NULL if no next item
 * 
 * @param location  location
 * @param item_ptr  previously found item
 * 
 * @return item_t   next item or NULL
 */
item_t* entity_item_next_at_location(entity_location_t location, const item_t *item_ptr);


/**
 * @brief Delete item and free item slot for use
 * 
 * Also frees the associated entity slot
 */ 
void entity_item_delete(item_t *item_ptr);

#endif
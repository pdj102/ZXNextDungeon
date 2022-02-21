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
 * @param *item_ptr  pointer to creature
 * @return void
 */
void entity_item_draw_stat_block(item_t *item_ptr);

/**
 * @brief Returns the first item at dungeon position x, y or NULL is no item
 * 
 * @param x position x
 * @param y position y
 * 
 * @return item_t 
 */
item_t *entity_item_at(uint8_t x, uint8_t y);

/**
 * @brief Delete item and free item slot for use
 * 
 * Also frees the associated entity slot
 */ 
void entity_item_delete(item_t *item_ptr);

#endif
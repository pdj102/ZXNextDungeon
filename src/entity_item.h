/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Item entity

 ***************************************************/

#ifndef ITEM_CREATURE_H 
    #define ITEM_CREATURE_H 

#include <inttypes.h>

/***************************************************
 * public types
 ***************************************************/
typedef enum {ring } item_type_t;

typedef struct {
    uint8_t tile;
    uint8_t tile_attr;
    uint8_t blocking; 
} item_t;

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Returns an item of type i
 * 
 * @param i  item type
 * @return pointer to item
 */
item_t *entity_item_create(item_type_t i);

/**
 * Prints item stat block to screen
 * 
 * @param *item_ptr  pointer to creature
 * @return void
 */
void entity_item_draw_stat_block(item_t *item_ptr);

/**
 * Move item
 */ 

/**
 * Delete item and free all memory
 */ 
void entity_item_delete(item_t *item_ptr);

#endif
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
typedef enum {
    weapon_melee_class,
    weapon_ranged_class,
    wand_class,
    armour_body_class,
    armour_head_class,
    ring_class,
    potion_class,
    food_class,
    scroll_class,
    book_class
} item_type_class_t;

typedef enum {

    // weapon_melee_class
    short_sword,
    long_sword,

    // weapon_ranged_class
    short_bow,
    long_bow,
    sling,

    // wand_class
    wand_magic_missile,

    // armour_body_class
    leather_armour,
    chain_mail_armour,

    // armor_head_class
    leather_helmet,
    metal_helmet,

    // ring_class
    ring_hp,
    ring_str,
    ring_ac,

    // potion_class
    red_potion,
    blue_potion
} items_t;

typedef enum {
    affect_none,
    affect_strength,
    affect_dexterity,
    affect_constitution,
    affect_wisdom,
    affect_charisma,
    affect_ac,
    affect_max_hp,
    affect_speed
} affect_t;


typedef struct {
    uint8_t             record;             /**< if 0  record is available for use or array index + 1 if in use. */

    entity_t            *entity_ptr;        /**< pointer back to entity */
    item_type_class_t   item_class;         /**< type of item class*/
    char                name[15];           /**< description */

    items_t             item_type;          /**< type of item */

    affect_t            affect;             /**< what ability does the item modify */
    uint8_t             affect_mod;         /**< what it the mod */
} entity_item_t;

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
 * @param item  item type
 * @return pointer to item
 */
entity_item_t *entity_item_create(items_t item, uint8_t x, uint8_t y);

/**
 * @brief Prints item stat block to screen
 * 
 * TODO implement function
 * 
 * @param *item_ptr  pointer to creature
 * @return void
 */
void entity_item_draw_stat_block(const entity_item_t *item_ptr);

/**
 * @brief Returns the first item at dungeon position x, y or NULL is no item
 * 
 * @param x position x
 * @param y position y
 * 
 * @return entity_item_t 
 */
entity_item_t *entity_item_first_at(uint8_t x, uint8_t y);

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
entity_item_t* entity_item_next_at(uint8_t x, uint8_t y, const entity_item_t *item_ptr);

/**
 * @brief Returns the first item at location or NULL if no item
 * 
 * @param location  location
 * 
 * @return item_t 
 */
entity_item_t *entity_item_first_at_location(entity_location_t location);

/**
 * @brief Returns the next item at location or NULL if no next item
 * 
 * @param location  location
 * @param item_ptr  previously found item
 * 
 * @return entity_item_t   next item or NULL
 */
entity_item_t* entity_item_next_at_location(entity_location_t location, const entity_item_t *item_ptr);


/**
 * @brief Delete item and free item slot for use
 * 
 * Also frees the associated entity slot
 */ 
void entity_item_delete(entity_item_t *item_ptr);

#endif
/***************************************************
 * Dungeon - ZX Spectrum Next 
 * @author Paul Johnson
 * 
 * @brief represents an item, effect or creature within the dungeon
 * 
 * The Entity type contains the common attributes of items, effects or creates within the dungeon e.g. x and y position, tile
 * 
 * Memory management 
 * Entites are stored within a fixed number of records within a dedicated 1k memory block at 0x2000
 * 
 * 
 ***************************************************/

#ifndef ENTITY_H 
    #define ENTITY_H 

#include <inttypes.h>

/***************************************************
 * types
 ***************************************************/

/**
 * @brief Enumeration of entity types
 * 
 */
typedef enum entity_type {item, effect, creature} entity_type_t;

/**
 * @brief Enumeration of entity location types
 * 
 */
typedef enum entity_location_type {dungeon, inventory} entity_location_t;

/**
 * @brief The entity contains the common attributes of creatures, effects and items
 * 
 * @struct entity 
 * 
 */
typedef struct entity {
    void *next;             /**< single linked list of entities. */
    uint8_t record;         /**< 0 if record is available for use or array index + 1 if in use. */

    entity_location_t location;       /**< location of the entity e.g. dungeon, player inventory etc */
    uint8_t x;              /**< dungeon x cord */
    uint8_t y;              /**< dungeon y cord */
    uint8_t tile;           /**< tile number */
    uint8_t tile_attr;      /**< tile attribute */

    uint8_t current_energy; /**< current energy */

    uint8_t blocking;       /**< 1 if blocks square or 0 if non blocking */

    entity_type_t type;     /**< entity type e.g. ITEM, EFFECT, CREATURE */
    void *ptr;              /**< pointer to creature, item or effect struct */
} entity_t;

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * @brief Initialises entity list. Must be called before using the entity_ functions
 * 
 * @return void
 */
void entity_init();

/**
 * @brief Create an entity
 * 
 * There are a fixed number of entity slots
 * 
 * @return pointer to new entity or NULL on error
 */
entity_t *entity_create();

/**
 * @brief Returns first entity in list 
 * 
  * @return entity_t first entity in list or NULL if list is empty
 */
entity_t *entity_front();

/**
 * @brief Move entity. Checks if square is not blocked before moving
 * 
 * @param entity_ptr entity pointer
 * @param dx move direction e.g. +1 or -1
 * @param dy move direction e.g. +1 or -1
 * @return 1 if move succesfull or 0 if blocked
 */
uint8_t entity_move(entity_t *entity_ptr, int8_t dx, int8_t dy);

/**
 * @brief Reduce entity energy level by effort
 * 
 * @param entity_ptr entity pointer
 * @param effort    amount to reduce energy level by
 * @return void
 */
void entity_reduce_energy(entity_t *entity_ptr, uint8_t effort);

/**
 * @brief Draws all entities whose location is dungeon onto the tilemap
 * 
 * @return void
 */
void entity_draw_all();

/**
 * @brief Is there a blocking entity at the dungeon position?
 * 
 * @param   x   dungeon x cord
 * @param   y   dungeon y cord
 * @return 1 = blocking 0 = not blocked
 */
uint8_t entity_is_blocking_at(uint8_t x, uint8_t y);

/**
 * @brief Returns first entity at dungeon position.
 * 
 * Call entity_next_at to find subsequent entities at the position
 * 
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @return entity at dungeon position or NULL
 */
entity_t *entity_first_at(uint8_t x, uint8_t y);

/**
 * @brief Returns next entity at dungeon position.
 * 
 * Can be called repeatably to find all entities at dungeon location
 * 
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @return next entity at position or NULL
 */
entity_t* entity_next_at(uint8_t x, uint8_t y, entity_t *entity_ptr);

/**
 * @brief Returns next entity in list
 * 
 * @param entity_ptr entity 
 * 
 * @return next entity
 */
entity_t *entity_next(entity_t *entity_ptr);

/**
 * @brief Delete entity and free entity slot for use
 * 
 * @param entity_ptr entity 
 * 
 * @return void
 */
void entity_delete(entity_t *entity_ptr);

#endif
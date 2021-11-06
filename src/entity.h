/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manage entities. An entity represents an item, effect or creature 

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
typedef enum {item, effect, creature} entity_type_t;

/**
 * @brief The entity contains the common attributes of creatures, effects and items
 * 
 * @struct entity 
 * 
 */
typedef struct entity {
    void *next;         // p_forward_list next
    uint8_t record;     // record number (first record is 1). 0 if record is available

    uint8_t x;
    uint8_t y; 
    uint8_t tile;
    uint8_t tile_attr;

    uint8_t current_energy;

    uint8_t blocking; 

    entity_type_t type;
    void *ptr;  // pointer to creature, item or effect 
} entity_t;

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises entity list. Must be called before using the entity_ functions
 * 
  * @return void
 */
void entity_init();

/**
 * Create an entity
 * 
 * @return pointer to new entity or NULL on error
 */
entity_t *entity_create();

/**
 * Returns first entity in list 
 * 
  * @return entity_t first entity in list or NULL if list is empty
 */
entity_t *entity_front();

/**
 * Move entity. Checks if square is not blocked before moving
 * 
 * @param entity_ptr entity pointer
 * @param dx move direction e.g. +1 or -1
 * @param dy move direction e.g. +1 or -1
 * @return 1 if move succesfull or 0 if blocked
 */
uint8_t entity_move(entity_t *entity_ptr, int8_t dx, int8_t dy);

/**
 * Reduce entity energy level by effort
 * 
 * @param entity_ptr entity pointer
 * @param effort    amount to reduce energy level by
 * @return void
 */
void entity_reduce_energy(entity_t *entity_ptr, uint8_t effort);

/**
 * Draws all entities onto the tilemap
 * 
  * @return void
 */
void entity_draw_all();

/**
 * Is there a blocking entity at the dungeon position?
 * 
 * @param   x   dungeon x cord
 * @param   y   dungeon y cord
 * @return 1 = blocking 0 = not blocked
 */
uint8_t entity_is_blocking_at(uint8_t x, uint8_t y);

/**
 * Returns first entity at dungeon position.
 * Call entity_next_at to find subsequent entities at the position
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @return entity at dungeon position or NULL
 */
entity_t *entity_first_at(uint8_t x, uint8_t y);

/**
 * Returns next entity at dungeon position.
 * Can be called repeatably to find all entities at dungeon location
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @return next entity at position or NULL
 */
entity_t* entity_next_at(uint8_t x, uint8_t y, entity_t *entity_ptr);

/**
 * Returns next entity in list
 * @param entity_ptr entity 
 * 
 * @return next entity
 */
entity_t *entity_next(entity_t *entity_ptr);

/**
 * Delete entity from list and frees up memory
 * @param entity_ptr entity 
 * 
 * @return void
 */
void entity_delete(entity_t *entity_ptr);

#endif
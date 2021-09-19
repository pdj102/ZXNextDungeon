/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manage entities. An entity represents an item, effect or creature 

 ***************************************************/

#ifndef ENTITY_H 
    #define ENTITY_H 

#include <inttypes.h>
#include "entity_creature.h"
#include "entity_item.h"

/***************************************************
 * types
 ***************************************************/
typedef enum {item, effect, creature} entity_type_t;

/*
typedef struct effect {
    uint8_t i;
} effect_t;
*/


typedef struct entity {
    void *next;     // p_forward_list next

    uint8_t x;
    uint8_t y; 
    uint8_t tile;

    uint8_t current_energy;

    uint8_t blocking; 

    entity_type_t type;
    creature_t *creature_ptr;
    item_t *item_ptr;    

} entity_t;


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises entity list. Entity list must be called before use
 * 
  * @return void
 */
void entity_init();

/**
 * Create an entity
 * 
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @param tile tile definition of entity
 * @param blocking 1=passable 0=unpassable
 * @param type creature or item
 * @param *creature_ptr pointer to creature struct 
 * @return *item_ptr pointer to item struct
 * 
 * @return pointer to new entity
 */
entity_t *entity_create(uint8_t x, uint8_t y, uint8_t tile, uint8_t blocking, entity_type_t type, creature_t *creature_ptr, item_t *item_ptr);

/**
 * Create a creature entity
 * 
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @param c_type Creature type
 * @return entity_ptr
 */
entity_t *entity_create_creature(uint8_t x, uint8_t y, creature_type_t c_type);

/**
 * Create a item entity
 * 
 * @param x dungeon x cord
 * @param y dungeon y cord
 * @param i_type Item type
 * @return entity_ptr 
 */
entity_t *entity_create_item(uint8_t x, uint8_t y, item_type_t i_type);

/**
 * Returns first entity in list
 * 
  * @return entity_t first entity in list
 */
entity_t *entity_front();

/**
 * Draws all entities on the tilemap
 * 
  * @return void
 */
void entity_draw_all();

/**
 * Is the dungeon position occupied by a unpassable entity?
 * 
  * @return 1=passable 0=unpassable
 */
uint8_t entity_passable(uint8_t y, uint8_t x);

/**
 * Returns entity if it is at dungeon position or next entity in list at dungeon position.
 * Can be called repeatably to find all entities at dungeon location
 * @param x dungeon x cord
 * @param y dungeon y cord
 * 
 * @return returns entity, or next entity in list, at dungeon location
 */
entity_t* entity_at(uint8_t y, uint8_t x, entity_t *entity_ptr);

/**
 * Returns next entity in list
 * @param entity_ptr entity 
 * 
 * @return next entity
 */
entity_t *entity_next(entity_t *entity_ptr);

/**
 * Removes entity from list and frees up memory
 * @param entity_ptr entity 
 * 
 * @return void
 */
void entity_delete(entity_t *entity_ptr);

#endif
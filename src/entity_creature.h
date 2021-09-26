/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Creature entity

 ***************************************************/

#ifndef ENTITY_CREATURE_H 
    #define ENTITY_CREATURE_H 

#include <inttypes.h>

/***************************************************
 * public types
 ***************************************************/
typedef enum {player, snake} creature_type_t;

typedef enum {asleep, attacking} creature_state_t;

typedef struct {
    uint8_t max_hp;
    uint8_t curr_hp;

    uint8_t ac;
    uint8_t dmg;

    uint8_t lvl;
    uint16_t exp;

    uint8_t speed;

    uint8_t tile;
    uint8_t tile_attr; 
    uint8_t blocking; 

    creature_state_t state;
} creature_t;

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Returns a creature of type e
 * 
 * @param e  creature type
 * @return pointer to creature
 */
creature_t *entity_creature_create(creature_type_t e);

/**
 * Prints creature stat block to screen
 * 
 * @param *c  pointer to creature
 * @return void
 */
void entity_creature_draw_stat_block(creature_t *c);

/**
 * Move creature
 */ 

/**
 * Delete creature and free all memory
 */ 
void entity_creature_delete(creature_t *creature_ptr);

#endif
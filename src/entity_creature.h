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


#endif
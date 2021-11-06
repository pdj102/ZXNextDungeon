/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Creature entity

 ***************************************************/

#ifndef ENTITY_CREATURE_H 
    #define ENTITY_CREATURE_H 

#include <inttypes.h>

#include "entity.h"
#include "dice.h"

/***************************************************
 * public types
 ***************************************************/

typedef enum {LARGE, MEDIUM, SMALL} creature_size_t;

typedef enum creature_types
{
    ANT, DOG, SNAKE,            // 0
    GIANT_RAT, GIANT_SPIDER,    // 1
    GOBLIN, SKELETON,           // 2
    ORC,                        // 3
    GHOUL,                      // 4
    PLAYER                      // Special
}
 creature_type_t;

typedef enum {ASLEEP, RESTING, WANDERING, ATTACKING} creature_state_t;

typedef enum {NONE, STRIKE, BITE, ARROW} attack_t;

typedef struct {

    // pointer back to entity
    entity_t    *entity_p;

    // Stat block
    char        name[10];
    char        creature[10];

    creature_size_t     size;
    creature_type_t     ctype;

    uint8_t     lvl;
    uint16_t    exp;
    uint16_t    nxt;

    uint8_t     str;
    uint8_t     inte;
    uint8_t     wis;
    uint8_t     dex;
    uint8_t     con;

    uint8_t     ac;
    
    uint8_t     max_hp;
    int8_t      curr_hp;

    uint8_t     dmg;
    dice_t      *dmg_die_p;

    uint8_t     speed;
    creature_state_t state;    

    // attacks
    attack_t    melee_attack_1;
    attack_t    melee_attack_2;
    attack_t    range_attack_1;
    attack_t    range_attack_2;

} creature_t;

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Creates and returns a creature of type creature_type_t
 * 
 * @param creature_type  creature type
 * @param x dungeon x position
 * @param y dungeon y position
 * @return pointer to creature or NULL if failed to create creature
 */
creature_t *entity_creature_create(creature_type_t creature_type, uint8_t x, uint8_t y);

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
uint8_t entity_creature_move_or_strike(creature_t *creature_ptr, int8_t dx, int8_t dy);


/**
 * Delete creature and free all memory
 */ 
void entity_creature_delete(creature_t *creature_ptr);

#endif
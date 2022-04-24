/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Creature entity

 ***************************************************/

#ifndef ENTITY_CREATURE_H 
    #define ENTITY_CREATURE_H 

#include <inttypes.h>

#include "entity.h"
#include "dice.h"

/***************************************************
 * public types
 ***************************************************/

typedef enum creature_size {LARGE, MEDIUM, SMALL} creature_size_t;

typedef enum creature_type
{
    ANT, DOG, SNAKE,            // 0
    GIANT_RAT, GIANT_SPIDER,    // 1
    GOBLIN, SKELETON,           // 2
    ORC,                        // 3
    GHOUL,                      // 4
    PLAYER                      // Special
}
 creature_type_t;

typedef enum creature_state_e {ASLEEP, RESTING, WANDERING, ATTACKING} creature_state_t;

typedef enum damage_kind_e {NONE, ACID, COLD, FIRE, LIGHTNING, POISON, SLASHING, BLUDGEON, PIERCING} damage_kind_t;

typedef struct {
    int8_t          proficiency_mod;
    damage_kind_t   damage_kind;
    dice_t          dmg_die;
} attack_t;



typedef struct {
    uint8_t record;         /**< if 0  record is available for use or array index + 1 if in use. */

    entity_t    *entity_ptr;    /**< pointer back to entity */

    // Stat block
    char        name[10];
    char        creature[10];

    creature_size_t     size;
    creature_type_t     ctype;

    uint8_t     lvl;
    uint16_t    exp;
    uint16_t    nxt;

    uint8_t     strength;
    uint8_t     dexterity;    
    uint8_t     constitution;    
    uint8_t     intelligence;
    uint8_t     wisdom;
    uint8_t     charisma;    

    uint8_t     ac;
    
    uint8_t     max_hp;
    int8_t      curr_hp;

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
 * @brief Init creatures
 *
 * @return void
 */
void entity_creature_init();

/**
 * @brief Creates and returns a creature of type creature_type
 * 
 * There are a fixed number of creature slots
 * 
 * @param creature_type  creature type
 * @param x dungeon x position
 * @param y dungeon y position
 * @return pointer to creature or NULL if failed to create creature
 */
creature_t *entity_creature_create(creature_type_t creature_type, uint8_t x, uint8_t y);


/**
 * @brief Returns the ability modifier for a given ability score
 * 
 * @param ability score
 * 
 * @return modifier
 */
int8_t ability_modifier(uint8_t ability);

/**
 * @brief Returns the first creature at dungeon position x, y or NULL is no creature
 * 
 * @param x position x
 * @param y position y
 * 
 * @return creature_t 
 */
creature_t *entity_creature_at(uint8_t x, uint8_t y);

/**
 * @brief Delete creature and free creature slot for use
 * 
 * Also frees the associated entity slot
 * 
 * @return void
 */ 
void entity_creature_delete(creature_t *creature_ptr);

#endif
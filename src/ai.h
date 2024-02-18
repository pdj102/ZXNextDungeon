/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The AI code

 ***************************************************/

#ifndef AI_H 
    #define AI_H 

// #include "globaldata_defines.h"

#include <stdint.h>

#include "creature.h"

#include "object.h"

/***************************************************
 * types
 ***************************************************/


typedef enum ai_state_s {
    NO_STATE,
    DEAD,
    SLEEPING, 
    AWAKE, 
    ATTACKING_MELEE, 
    ATTACKING_RANGED,
    ATTACKING_NO_TARGET,
    WANDERING,
    HUNTING,
    GUARDING, 
    FLEEING
} ai_state_t;


typedef struct ai_s
{
    creature_t              *creature_p;

    ai_state_t              state;

    struct creature_s      *target;

    uint8_t                 goto_target;
    uint8_t                 goto_x;
    uint8_t                 goto_y;

    uint8_t                 pathfind_page;
} ai_t;

// Typedef for is_a functions
typedef uint8_t (*creature_is_a2)(ai_t *, creature_t *);


/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Ai init
 * 
 * @return void
 */
void ai_init( ai_t *ai_p, creature_t *creature_p );

/**
 * Ai takes turn
 * 
 * @return void
 */
void ai_turn( ai_t *ai_p );

/**
 * Notify AI of attack by another creature
 * 
 * @return void
 */
void ai_is_attacked(ai_t *ai_p, creature_t *attacker_p);

/**
 * Returns base ai state of AI for object subtype
 * 
 * @return ai_state_t
 */
ai_state_t ai_base_state(object_subtype_e subtype);

#endif
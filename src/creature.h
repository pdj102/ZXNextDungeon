/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creatures

 ***************************************************/

#ifndef CREATURE_H 
    #define CREATURE_H 

#include <stdint.h>

#include "object.h"

#include "dice.h"

/***************************************************
 * types
 ***************************************************/



#define CONDITION_NONE              1 << 0
#define CONDITION_BLINDED           1 << 1
#define CONDITION_FRIGHTENED        1 << 2
#define CONDITION_GRAPPLED          1 << 3
#define CONDITION_INCAPACITATED     1 << 4
#define CONDITION_POISONED          1 << 5


typedef enum {AI, PLAYER } ai_or_player_e;

typedef enum {
    NO_DAMAGE, ACID, BLUDGEONGING, COLD, FIRE, FORCE, LIGHTNING, PIERCING, POSION, SLASHING
} damage_type_t;

typedef struct creature_attack_s
{
    dice_t                  damage_roll;
    damage_type_t           damage_type;
    int8_t                  attack_bonus;              /**< Calculated attack bonus */
    int8_t                  damage_bonus;              /**< Calculated damage bonus */
    uint8_t                 range;
} creature_attack_t;

extern struct ai_s;

typedef struct creature_s
{
    void                    *next;              /** creatures can be part of a list of creatures. Next pointer must be first 2 bytes in struct */
    uint8_t                 free;               /** 1 if creature slot is free */
    uint8_t                 index;              /** Creature index */
    object_t                *obj_p;             /** all creatures have an associated object */

    ai_or_player_e          ai_or_player;       /** player or AI */

    uint8_t                 max_hp;             /** max hp = base + any modifiers*/
    uint8_t                 hp;                 /** current hp */
    uint8_t                 ac;

    uint8_t                 speed;
    uint8_t                 energy;

    uint8_t                 str;
    uint8_t                 dex;
    uint8_t                 con;
    uint8_t                 inte;
    uint8_t                 wis;
    uint8_t                 cha;

    uint8_t                 exp;

    uint8_t                 max_mp;         /** max magic points = base + any modifiers*/
    uint8_t                 mp;             /** current magic points */

    creature_attack_t      melee;
    creature_attack_t      ranged;

    uint8_t                conditions;
        
} creature_t;

// Typedef for creature is_a functions
typedef uint8_t (*creature_is_a)(creature_t *);

/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the creature data structure. Must be called before using Creature module
 * 
 * @return void
 */
void creature_init( void );

/**
 * Find a free creature slot
 * 
 * @return   creature_t* pointer to a free creature slot or 0 if no free slot
 */
creature_t* creature_getfree( void );

/**
 * Mark a creature slot as free
 * 
 * NB creatures should be destroyed using creature_destroy()
 * 
 * @param   *creature_p  Creature to mark free
 */
void creature_free(creature_t *const creature_p);

/**
 * Creature turn
 * 
 * 
 * @param   *creature_p  
 */
void creature_turn(creature_t *const creature_p);


#endif
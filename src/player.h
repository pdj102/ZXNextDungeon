/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code

 ***************************************************/

#ifndef PLAYER_H 
    #define PLAYER_H 

#include "object.h"
#include "creature.h"

/***************************************************
 * types
 ***************************************************/
typedef struct player_s
{
    creature_t  *player_creature_p;     /**< pointer to player creature object */
    object_t    *melee_weapon;          /**< pointer to melee weapon */
    object_t    *ranged_weapon;         /**< pointer to melee weapon */
    object_t    *shield;                /**< pointer to shield */
    object_t    *armour;                /**< pointer to armour*/
    object_t    *ring_left;             /**< pointer to left hand ring*/
    object_t    *ring_right;            /**< pointer to right hand ring*/
} player_t;
/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Init the player
 *
 * @param creature_p pointer to the player's creature object
 * 
 * @return void
 */
void player_init(creature_t *creature_p);

/**
 * Player takes turn
 * 
 * @return void
 */
void player_turn( void );

#endif
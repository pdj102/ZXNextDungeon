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

typedef enum {
    NO_CLASS,
    CLERIC, 
    FIGHTER,
    WIZARD 
} player_class_t;

typedef struct player_s
{
    creature_t  *player_creature_p;     /**< pointer to player creature object */

    // player details
    player_class_t     class;
    uint8_t     level;
    uint8_t     xp;
    uint8_t     proficiency_bonus;

    // wielding
    object_t    *melee_weapon;          /**< pointer to melee weapon */
    object_t    *ranged_weapon;         /**< pointer to melee weapon */
    object_t    *shield;                /**< pointer to shield */
    object_t    *armour;                /**< pointer to armour*/
    object_t    *ring_left;             /**< pointer to left hand ring*/
    object_t    *ring_right;            /**< pointer to right hand ring*/

    // base stats
    uint8_t     base_speed;
    uint8_t     base_hp;                /**< base maximum hp */
    uint8_t     base_mp;                /**< base maximum mp */
    uint8_t     base_ac;
    uint8_t     base_str;
    uint8_t     base_dex;
    uint8_t     base_con;
    uint8_t     base_int;
    uint8_t     base_wis;
    uint8_t     base_cha;
    uint8_t     base_;

    // 

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
 * 
 * @return void
 */
void player_init( void );

/**
 * Player takes turn
 * 
 * @return void
 */
void player_turn( void );

#endif

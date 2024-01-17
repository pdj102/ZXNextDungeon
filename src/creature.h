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

typedef enum {PLAYER, AI} creature_class_e;

typedef enum {
    SLASH
} damage_type_t;

typedef struct creature_s
{
    void                    *next;              /**< creatures can be part of a list of creatures. Next pointer must be first 2 bytes in struct */
    uint8_t                 free;               /**< 1 if creature slot is free */
    object_t                *obj_p;             /** all creatures have an associated object */

    creature_class_e        creature_class;     /**< player or AI */

    uint8_t                 max_hp;             /**< max hp = base + any modifiers*/
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

    uint8_t                 max_magic;          /**< max magic points = base + any modifiers*/
    uint8_t                 magic;              /**< crrent magic points */

    uint8_t                 melee_modifier;
    dice_t                  melee_damage_roll;
    damage_type_t           melee_damage_type;

    uint8_t                 ranged_modifier;
    dice_t                  ranged_damage_roll;
    damage_type_t           ranged_damage_type;
    uint8_t                 range;
        
} creature_t;



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
 * Delete a creature 
 * 
 * NB creature's object needs to be deleted separately 
 * 
 * @param   *creature_p  Creature to destroy
 */
void creature_delete(creature_t *creature_p);

/**
 * Creature turn
 * 
 * 
 * @param   *creature_p  
 */
void creature_turn(creature_t *creature_p);


#endif
/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

 ***************************************************/

#ifndef CREATURE_CREATE_H 
    #define CREATURE_CREATE_H 

#include <stdint.h>

#include "creature.h"
#include "object.h"


/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Create a creature
 * 
 * Creates a creature based on the provided object. 
 * NB the object specifies the creature type to create
 *
 * @param obj_p* pointer to object
 *
 * @return pointer to created creature or NULL on failed to create
 */
creature_t* creature_create(object_t *obj_p);

void creature_create_reset_base_stats(creature_t *creature_p);

// TODO remove these functions as not needed
uint8_t creature_create_base_speed(object_subtype_e subtype);
uint8_t creature_create_base_hp(object_subtype_e subtype);
uint8_t creature_create_base_magic(object_subtype_e subtype);
uint8_t creature_create_base_ac(object_subtype_e subtype);
creature_attack_t creature_create_base_melee(object_subtype_e subtype);
uint8_t creature_create_base_str(object_subtype_e subtype);
uint8_t creature_create_base_dex(object_subtype_e subtype);
uint8_t creature_create_base_con(object_subtype_e subtype);
uint8_t creature_create_base_inte(object_subtype_e subtype);
uint8_t creature_create_base_wis(object_subtype_e subtype);
uint8_t creature_create_base_cha(object_subtype_e subtype);

#endif
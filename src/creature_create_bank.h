/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

    Banked code. Do not call directly        

 ***************************************************/

#ifndef CREATURE_CREATE_BANK_H 
    #define CREATURE_CREATE_BANK_H 

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
 * @param obj_subtype       Specify creature subtype to create
 *
 * @return pointer to created creature or NULL on failed to create
 */
creature_t* creature_create_b(object_subtype_e obj_subtype, uint8_t x, uint8_t y);

/**
 * Reset a creatures stats to their base score
 * 
 * Resets Max_HP, Max_MP, AC, Speed, Str, Dex, Con, Int, Wis, Cha, melee and ranged attacks
 * 
 * NB the creature's object specifies the creature type 
 *
 * @param *creature_p pointer to object
 *
 * @return void
 */

void creature_create_reset_base_stats_b(creature_t *creature_p);

uint8_t creature_create_base_speed_b(object_subtype_e subtype);
uint8_t creature_create_base_hp_b(object_subtype_e subtype);
uint8_t creature_create_base_magic_b(object_subtype_e subtype);
uint8_t creature_create_base_ac_b(object_subtype_e subtype);
creature_attack_t creature_create_base_melee_b(object_subtype_e subtype);
uint8_t creature_create_base_str_b(object_subtype_e subtype);
uint8_t creature_create_base_dex_b(object_subtype_e subtype);
uint8_t creature_create_base_con_b(object_subtype_e subtype);
uint8_t creature_create_base_inte_b(object_subtype_e subtype);
uint8_t creature_create_base_wis_b(object_subtype_e subtype);
uint8_t creature_create_base_cha_b(object_subtype_e subtype);
ai_state_t creature_create_base_ai_b(object_subtype_e subtype);

#endif
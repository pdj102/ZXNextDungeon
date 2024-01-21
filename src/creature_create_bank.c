/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

    Banked code. Do not call directly    

**************************************************/

#include "creature_create_bank.h"

#include <stdint.h>

#include "creature.h"
#include "creature_list.h"

#include "object.h"
#include "object_create.h"
#include "object_dungeon_list.h"

#include "text.h"

#include "globaldata_defines.h"         // ERROR_DEBUG

#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions
 ***************************************************/

// todo change this function to create the object as well
creature_t* creature_create_b(object_subtype_e obj_subtype, uint8_t x, uint8_t y)
{
    creature_t *creature_p;
    object_t *obj_p;

    // create an object
    if ( ! (obj_p = object_create(obj_subtype, x, y) ) )
    {
        #ifdef DEBUG_ERROR
            text_printf("ERROR: NO FREE OBJECT SLOT");
        #endif
        
        return 0;
    }

    // get a free creature slot
    if ( ! (creature_p = creature_getfree()) )
    {
        object_delete(obj_p);

        #ifdef DEBUG_ERROR
            text_printf("ERROR: NO FREE CREATURE SLOT");
        #endif

        return 0;
    }

    // Setup object
    obj_p->creature_p = creature_p;         // set object to point to creature
    object_dungeon_list_add(obj_p);         // add object to dungeon list of objects as all creatures are on the map

    // Setup creature common attributes
    creature_p->free = 0;
    creature_p->next = 0;
    creature_p->obj_p = obj_p;              // set creature to point to object
    creature_p->energy = 0;
    creature_p->creature_class = AI;    
    creature_list_add(creature_p);          // add creature to list of creatures

    // Setup creature specifics 
    creature_create_reset_base_stats_b(creature_p);

    // initialise hp and mp to max hp and mp
    creature_p->hp = creature_p->max_hp;
    creature_p->mp = creature_p->max_mp;

    // TODO Handle if x, y position is blocked

    return creature_p;
}

uint8_t creature_create_base_speed_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;    
      
    // BEAST
    case BEAST_SNAKE:
        return 10;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 1;    

    // UNDEAD          

    default:
        return 1;
    }
}

uint8_t creature_create_base_hp_b(object_subtype_e subtype)
{
    // TODO special base HP for player based on level
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 2;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 22;    

    // UNDEAD

    default:
        return 1;
    }
}

uint8_t creature_create_base_magic_b(object_subtype_e subtype)
{
    // TODO special base magic for player based on level
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 0;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 0;    

    // UNDEAD

    default:
        return 1;
    }
}

uint8_t creature_create_base_ac_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 13;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 0;    

    // UNDEAD

    default:
        return 1;
    }
}

uint8_t creature_create_base_str_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 2;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 3;    

    // UNDEAD

    default:
        return 1;
    }
}

uint8_t creature_create_base_dex_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 16;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 1;    

    // UNDEAD

    default:
        return 1;
    }
}

uint8_t creature_create_base_con_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 11;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 10;    

    // UNDEAD

    default:
        return 1;
    }
}

uint8_t creature_create_base_inte_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 1;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 1;    

    // UNDEAD

    default:
        return 1;        
    }
}

uint8_t creature_create_base_wis_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 10;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 3;    

    // UNDEAD

    default:
        return 1;    

    }
}

uint8_t creature_create_base_cha_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    case HUMANOID_HUMAN:
        return 10;   
      
    // BEAST
    case BEAST_SNAKE:
        return 3;

    // OOZE

    // PLANTS
    case PLANT_WITHERWEED:
        return 1;    

    // UNDEAD

    default:
        return 1;  
    }
}

creature_attack_t creature_create_base_melee_b(object_subtype_e subtype)
{
    creature_attack_t a;

    switch (subtype)
    {
    //HUMANOID        
    case HUMANOID_HUMAN:
        a.damage_type = BLUDGEONGING;
        a.damage_roll.n = 1;
        a.damage_roll.d = 6;
        a.damage_roll.mod = 0;
        a.attack_bonus = 0;
        return a;        
    // BEAST
    case BEAST_SNAKE:
        a.damage_type = PIERCING;
        a.damage_roll.n = 1;
        a.damage_roll.d = 4;
        a.damage_roll.mod = 0;
        a.attack_bonus = 5;
        return a;

    // OOZE
    
    // PLANT
    case PLANT_WITHERWEED:
        a.damage_type = PIERCING;
        a.damage_roll.n = 1;
        a.damage_roll.d = 4;
        a.damage_roll.mod = 0;
        a.attack_bonus = 2;
        return a;    

    // UNDEAD
    
    default:
        a.damage_type = NONE;
        a.damage_roll.n = 0;
        a.damage_roll.d = 0;
        a.damage_roll.mod = 0;
        a.attack_bonus = 0;
        return a;
    }
}

creature_attack_t creature_create_base_ranged_b(object_subtype_e subtype)
{
    creature_attack_t a;

    switch (subtype)
    {
    default:
        a.damage_type = NONE;
        a.damage_roll.n = 0;
        a.damage_roll.d = 0;
        a.damage_roll.mod = 0;
        a.attack_bonus = 0;
        return a;
    }
}




void creature_create_reset_base_stats_b(creature_t *creature_p)
{
    object_subtype_e subtype;
    subtype = creature_p->obj_p->subtype;

    creature_p->speed = creature_create_base_speed_b(subtype);
    creature_p->max_hp = creature_create_base_hp_b(subtype);
    creature_p->max_mp = creature_create_base_magic_b(subtype);
    creature_p->ac = creature_create_base_ac_b(subtype);

    creature_p->melee = creature_create_base_melee_b(subtype);
    creature_p->ranged = creature_create_base_ranged_b(subtype);

    creature_p->str = creature_create_base_str_b(subtype);
    creature_p->dex = creature_create_base_dex_b(subtype);
    creature_p->con = creature_create_base_con_b(subtype);
    creature_p->inte = creature_create_base_inte_b(subtype);
    creature_p->wis = creature_create_base_wis_b(subtype);
    creature_p->cha = creature_create_base_cha_b(subtype);
}



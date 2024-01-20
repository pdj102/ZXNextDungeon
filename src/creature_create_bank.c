/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

    Banked code. Do not call directly    

**************************************************/

#include "creature_create_bank.h"

#include <stdint.h>

#include "creature.h"
#include "object.h"

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

uint8_t creature_create_base_speed_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 10;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_hp_b(object_subtype_e subtype)
{
    // TODO special base HP for player based on level
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 2;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_magic_b(object_subtype_e subtype)
{
    // TODO special base magic for player based on level
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 0;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_ac_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 13;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_str_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 2;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_dex_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 16;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_con_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 11;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_inte_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 1;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_wis_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 10;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

uint8_t creature_create_base_cha_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    case BEAST_SNAKE:
        return 3;
    case HUMANOID_HUMAN:
        return 10;
    default:
        return 1;
    }
}

creature_attack_t creature_create_base_melee_b(object_subtype_e subtype)
{
    creature_attack_t a;

    switch (subtype)
    {
    case BEAST_SNAKE:
        a.damage_type = PIERCING;
        a.damage_roll.n = 1;
        a.damage_roll.d = 4;
        a.damage_roll.mod = 0;
        a.attack_bonus = 5;
        return a;
    case HUMANOID_HUMAN:
        a.damage_type = BLUDGEONGING;
        a.damage_roll.n = 1;
        a.damage_roll.d = 6;
        a.damage_roll.mod = 0;
        a.attack_bonus = 0;
        return a;
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


creature_t* creature_create_b(object_t *obj_p)
{
    creature_t *creature_p;
    object_subtype_e subtype;

    // get a free creature slot
    if ( ! (creature_p = creature_getfree()) )
    {
        return 0;
    }
    
    subtype = obj_p->subtype;

    // set common object attributes
    creature_p->free = 0;
    creature_p->next = 0;
    creature_p->obj_p = obj_p;
    creature_p->energy = 0;
    creature_p->creature_class = AI;

    creature_p->speed = creature_create_base_speed_b(subtype);
    creature_p->max_hp = creature_create_base_hp_b(subtype);
    creature_p->hp = creature_p->max_hp;
    creature_p->max_mp = creature_create_base_magic_b(subtype);
    creature_p->mp = creature_p->max_mp;
    creature_p->ac = creature_create_base_ac_b(subtype);

    creature_p->melee = creature_create_base_melee_b(subtype);
    creature_p->ranged = creature_create_base_ranged_b(subtype);

    creature_p->str = creature_create_base_str_b(subtype);
    creature_p->dex = creature_create_base_dex_b(subtype);
    creature_p->con = creature_create_base_con_b(subtype);
    creature_p->inte = creature_create_base_inte_b(subtype);
    creature_p->wis = creature_create_base_wis_b(subtype);
    creature_p->cha = creature_create_base_cha_b(subtype);
    
    /*
    switch (obj_p->subtype)
    {
    case HUMANOID_HUMAN:
        creature_p->speed = 10;
        creature_p->hp = 10;
        creature_p->ac = 10;

        creature_p->melee_damage_roll.n = 1;
        creature_p->melee_damage_roll.d = 6;
        creature_p->melee_damage_roll.mod = 0;
        creature_p->melee_modifier = 0;
        break;
    case BEAST_SNAKE:
        creature_p->speed = 5;
        creature_p->hp = 15;        
        creature_p->ac = 5;
        break;
    default:
        break;
    }
    */

    return creature_p;
}



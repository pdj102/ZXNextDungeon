/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creatures

**************************************************/


#include <adt/p_forward_list.h>
#include <stdint.h>

#include "creature.h"

#include "object.h"
#include "globaldata.h"

#include "text.h"

#include "player.h"

#define MAX_ENERGY  100

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

void object_free(object_t *obj_tofree);


/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void creature_init()
{
    for (uint8_t i = 0; i < MAX_CREATURE; i++)
    {
        globaldata.creatures[i].free = 1;
        globaldata.creatures[i].next = 0;
    }
}

void creature_turn(creature_t *creature_p)
{
    // Increase creature's energy by its speed. Clamp to MAX_ENERGY
    creature_p->energy = (creature_p->speed <= MAX_ENERGY - creature_p->energy ? creature_p->energy + creature_p->speed : MAX_ENERGY );

    if (creature_p->energy == MAX_ENERGY)
    {
        switch (creature_p->creature_class )
        {
        case AI:
            break;
        case PLAYER:
            player_turn();
            break;
        default:
            break;
        }
    }
}

// TO DO move into  bank code for creating creatures and create base data
creature_t* creature_create(object_t *obj_p)
{
    creature_t *creature_p;

    // get a free creature slot
    if ( ! (creature_p = creature_getfree()) )
    {
        return 0;
    }
    
    // set common object attributes
    creature_p->free = 0;
    creature_p->next = 0;
    creature_p->obj_p = obj_p;
    creature_p->energy = 0;
    creature_p->creature_class = AI;

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
        creature_p->hp = 5;        
        creature_p->ac = 5;
        break;
    default:
        break;
    }

    return creature_p;
}

creature_t* creature_getfree()
{
    for (uint8_t i = 0; i < MAX_CREATURE; i++)
    {
        if (globaldata.creatures[i].free)
        {
            return &globaldata.creatures[i];
        }
    }
    // no free creature slot
    return 0;
}

void creature_free(creature_t *creature_p)
{
       creature_p->free = 1;
}

void creature_delete(creature_t *creature_p)
{
    // free the object
    creature_free(creature_p);
}
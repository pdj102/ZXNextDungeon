/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creatures

**************************************************/

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "creature.h"

#include "object.h"
#include "globaldata.h"

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

    switch (obj_p->subtype)
    {
    case HUMANOID_HUMAN:
        creature_p->speed = 10;
        creature_p->hp = 10;
        creature_p->ac = 10;
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
        if (&globaldata.creatures[i].free)
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
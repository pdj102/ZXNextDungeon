/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Creature entity

 ***************************************************/
#include "entity_creature.h"

#include <inttypes.h>
#include <stdlib.h>

/***************************************************
 * private types
 ***************************************************/




/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/

/***************************************************
 * functions definitions
 ***************************************************/

/**
 * Create a creature
 * 
 * @param input1  description
 * @return void
 */
creature_t *entity_creature_create(creature_type_t e)
{
    creature_t *c = (creature_t *) malloc(sizeof(creature_t));

    switch (e)
    {
        case player :
            c->max_hp   = 8;
            c->curr_hp  = 8;
            c->ac       = 10;
            c->dmg      = 6;
            c->state    = attacking;
            break;
        case snake :
            c->max_hp   = 4;
            c->curr_hp  = 4;
            c->ac       = 4;
            c->dmg      = 2;
            c->state    = attacking;
    }

    return c;
}
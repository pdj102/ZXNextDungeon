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
#include "globaldata_defines.h"     // MAX_CREATURE

#include "text.h"

#include "player.h"

#include "ai.h"

#include "util.h"

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

void creature_init( void )
{
    for (uint8_t i = 0; i < MAX_CREATURE; i++)
    {
        globaldata.creatures[i].free = 1;
        globaldata.creatures[i].next = 0;
        globaldata.creatures[i].index = i;
    }
}

void creature_turn(creature_t *const creature_p)
{
    // Increase creature's energy by its speed. Clamp to MAX_ENERGY
    creature_p->energy = (creature_p->speed <= MAX_ENERGY - creature_p->energy ? creature_p->energy + creature_p->speed : MAX_ENERGY );

    if (creature_p->energy == MAX_ENERGY)
    {
        switch (creature_p->ai_or_player )
        {
        case AI:
            ai_turn(&globaldata.ai[creature_p->index]);
            break;
        case PLAYER:
            player_turn();
            break;
        default:
            break;
        }
    }
}

creature_t* creature_getfree( void )
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

void creature_free(creature_t *const creature_p)
{
    util_assert(creature_p->free != 1);      // assert creature is not already marked free
    util_assert(creature_p->next == 0);      // assert creature linked list pointer is NULL 

    // free the creature slot
    creature_p->free = 1;
}
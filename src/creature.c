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
    }
}

void creature_turn(creature_t *creature_p)
{
    // Increase creature's energy by its speed. Clamp to MAX_ENERGY
    creature_p->energy = (creature_p->speed <= MAX_ENERGY - creature_p->energy ? creature_p->energy + creature_p->speed : MAX_ENERGY );

    if (creature_p->energy == MAX_ENERGY)
    {
        switch (creature_p->ai_or_player )
        {
        case AI:
            ai_turn(creature_p);
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

void creature_free(creature_t *creature_p)
{
       creature_p->free = 1;
}

void creature_delete(creature_t *creature_p)
{
    #ifdef DEBUG_ERROR
        if (creature_p->obj_p->free != 1)
        {
            // Fatal error detected - creature object has not been deleted before deleting the creature
            text_printf("DEBUG: CREATURE OBJ NOT FREE\n");
        }
    #endif
    // free the creature slot
    creature_free(creature_p);
}
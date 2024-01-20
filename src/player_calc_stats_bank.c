/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Calculate player stats

    Apply modifiers, bonuses, effects etc to base stats

 ***************************************************/
#include "player_calc_stats_bank.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions 

#include "player.h"
#include "globaldata.h"

#include "creature_create.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/
void player_calc_stats_ring_b( object_t *obj_p);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void player_calc_stats_b( void )
{
    /* Sequence is 
        1) reset stats to base stats
        2) apply equipment modifiers
        3) apply effect modifiers
        4) calculate attack bonuses for melee and ranged

        TODO implement similar for creatures
        TODO implement special base case for player which increases with level progression
    */

    // 1. Reset stats to base stats
    creature_create_reset_base_stats(globaldata.player.player_creature_p);

    // 2. Apply equipment modifiers

    player_calc_stats_ring_b(globaldata.player.ring_left);
    player_calc_stats_ring_b(globaldata.player.ring_right);

    // 3. Apply effects modifiers (TODO move to creature code as this should apply to creatures too)
}

void player_calc_stats_ring_b( object_t *obj_p)
{
    if (obj_p == 0)
    {
        return;
    }

    switch (obj_p->subtype)
    {
    case RING_HP:
        globaldata.player.player_creature_p->max_hp += obj_p->attr_1;
        break;
    
    default:
        break;
    }
}

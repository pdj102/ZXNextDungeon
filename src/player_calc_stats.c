/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Calculate player stats

    Apply modifiers, bonuses, effects etc to base stats

 ***************************************************/
#include "player_calc_stats.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions 

#include "player_calc_stats_bank.h"


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

void player_calc_stats( void )
{
    /* Map Player code (bank 24) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 24);
    /* Call banked code */ 
    player_calc_stats_b();
}

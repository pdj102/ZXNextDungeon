/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Player code

 ***************************************************/
#include "player.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions 

#include "creature.h"
#include "player_bank.h"

#include "globaldata.h"


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

void player_init(creature_t *creature_p)
{
    /* Map Player code (bank 24) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 24);
    /* Call banked code */ 
    player_init_b(creature_p); 
}

void player_turn( void )
{
    /* Map Player code (bank 24) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 24);
    /* Call banked code */ 
    player_turn_b(); 
}

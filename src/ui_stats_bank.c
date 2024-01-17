/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Text token

    Banked code. Do not call directly

 ***************************************************/
#include "ui_stats_bank.h"

#include <stdint.h>

#include "globaldata.h"
#include "globaldata_defines.h"
#include "text.h"

#include "creature.h"
        

#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * private types 
 ***************************************************/

/***************************************************
 * private function prototypes - static
 ***************************************************/


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/

/***************************************************
 * functions definitions
 ***************************************************/

void ui_display_stats_b( void )
{
    text_select_win( WIN_STATS );

    text_printf("PLAYER STATS\n\n");

    text_printf("STR:%u\n", globaldata.player.player_creature_p->str);
    text_printf("DEX:%u\n", globaldata.player.player_creature_p->dex);
    text_printf("CON:%u\n", globaldata.player.player_creature_p->con);
    text_printf("INT:%u\n", globaldata.player.player_creature_p->inte);
    text_printf("WIS:%u\n", globaldata.player.player_creature_p->wis);
    text_printf("CHA:%u\n", globaldata.player.player_creature_p->cha);
    text_printf("\n");
    text_printf(" HP:%u (%u)\n", globaldata.player.player_creature_p->hp, globaldata.player.player_creature_p->max_hp);
    text_printf("MAG:%u (%u)\n", globaldata.player.player_creature_p->magic, globaldata.player.player_creature_p->max_magic);
    text_printf("\n");
    text_printf("SPD:%u\n", globaldata.player.player_creature_p->speed);

    text_select_win( WIN_MESSAGES );
}

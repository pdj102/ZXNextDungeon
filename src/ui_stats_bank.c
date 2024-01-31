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
#include "creature_create.h"
        

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

void ui_display_hp_mp_b( void )
{
    text_select_win( WIN_STATS );
    text_print_at(0, 1);

/*
    text_printf("HP:%u (%u)\n", (unsigned char) (globaldata.player.player_creature_p->hp), (unsigned char) (globaldata.player.player_creature_p->max_hp));
    text_printf("MP:%u (%u)\n", (unsigned char) (globaldata.player.player_creature_p->mp), (unsigned char) (globaldata.player.player_creature_p->max_mp));
*/


    text_printf("HP:%u ", globaldata.player.player_creature_p->hp);
    text_printf("(%u)\n", globaldata.player.player_creature_p->max_hp);
    text_printf("MP:%u ", globaldata.player.player_creature_p->mp);
    text_printf("(%u)\n", globaldata.player.player_creature_p->max_mp);

    text_select_win( WIN_MESSAGES );
}    

void ui_display_stats_b( void )
{
    const object_subtype_e t = globaldata.player.player_creature_p->obj_p->subtype;

    text_select_win( WIN_STATS );
    text_print_at(0, 4);

    text_printf("Class: %u\n", globaldata.player.class);
    text_printf("Level: %u\n", globaldata.player.level);
    text_printf("XP: %u\n\n", globaldata.player.xp);
    
    text_printf("AC:%u\n", globaldata.player.player_creature_p->ac);
    text_printf("SPEED:%u\n", globaldata.player.player_creature_p->speed);

    text_printf("\n");
    text_printf("Melee:%u", globaldata.player.player_creature_p->melee.damage_roll.n);
    text_printf("D%u", globaldata.player.player_creature_p->melee.damage_roll.d);
    text_printf("+%u\n", globaldata.player.player_creature_p->melee.damage_roll.mod);
    text_printf("Bonus:%u\n", globaldata.player.player_creature_p->melee.attack_bonus);

    text_printf("Ranged:%u", globaldata.player.player_creature_p->ranged.damage_roll.n);
    text_printf("D%u", globaldata.player.player_creature_p->ranged.damage_roll.d);
    text_printf("+%u\n", globaldata.player.player_creature_p->ranged.damage_roll.mod);
    text_printf("Bonus:%u\n\n", globaldata.player.player_creature_p->ranged.attack_bonus);

    text_printf("STR:%u", globaldata.player.player_creature_p->str);
    text_printf("(%u)\n", creature_create_base_str(t));
    text_printf("DEX:%u", globaldata.player.player_creature_p->dex);
    text_printf("(%u)\n", creature_create_base_dex(t));
    text_printf("CON:%u", globaldata.player.player_creature_p->con);
    text_printf("(%u)\n", creature_create_base_con(t));
    text_printf("INT:%u", globaldata.player.player_creature_p->inte);
    text_printf("(%u)\n", creature_create_base_inte(t));
    text_printf("WIS:%u", globaldata.player.player_creature_p->wis);
    text_printf("(%u)\n", creature_create_base_wis(t));
    text_printf("CHA:%u", globaldata.player.player_creature_p->cha);
    text_printf("(%u)\n", creature_create_base_cha(t));

    text_select_win( WIN_MESSAGES );    

    text_select_win( WIN_MESSAGES );    
}

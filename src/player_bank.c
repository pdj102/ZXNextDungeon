/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Player code

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>
#include <input.h>              // Functions for Reading Keyboards, Joysticks and Mice
#include <ctype.h>              // character classification e.g. toupper() 

#include "player.h"
#include "player_open_bank.h"
#include "player_close_bank.h"
#include "player_pickup_bank.h"
#include "player_quaff_bank.h"
#include "player_drop_bank.h"
#include "player_strike_bank.h"
#include "player_inventory_bank.h"
#include "player_equipment_bank.h"
#include "player_move_bank.h"
#include "player_wield_bank.h"
#include "player_takeoff_bank.h"

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"

#include "object_dungeon_list.h"

#include "creature.h"
#include "creature_create.h"


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

void player_init_b( void )
{
    creature_t *creature_p;

    // Create a level 1 humanoid crreature
    creature_p = creature_create(HUMANOID_HUMAN, 5, 5);

    // Change from AI to player
    creature_p->ai_or_player = PLAYER;

    // Set global data player to point to this creature
    globaldata.player.player_creature_p = creature_p;

    // Set player name to 'you' 
    globaldata.player.player_creature_p->obj_p->name_token = 111;

    // Set player details
    globaldata.player.class = FIGHTER;
    globaldata.player.level = 1;
    globaldata.player.xp = 0;
    globaldata.player.proficiency_bonus = 2;

    // Set the player base stats based on the humanoid creature
    globaldata.player.base_speed = creature_p->speed;
    globaldata.player.base_ac = creature_p->ac;
    globaldata.player.base_hp = creature_p->hp;
    globaldata.player.base_mp = creature_p->mp;
    globaldata.player.base_str = creature_p->str;
    globaldata.player.base_dex = creature_p->dex;
    globaldata.player.base_con = creature_p->con;
    globaldata.player.base_int = creature_p->inte;
    globaldata.player.base_wis = creature_p->wis;
    globaldata.player.base_cha = creature_p->cha;

}

void player_turn_b( void )
{

    unsigned int key;

    // while ((key = in_Inkey()) == 0) ;   // loop while no key pressed
    // in_WaitForNoKey();    // wait no key
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key    

    switch(toupper(key)) {
        
        case 54:  // down
            player_move_b(0, 1);
            break;
        case 55:  // up
            player_move_b(0, -1);
            break;

        case 53:  // left
            player_move_b(-1, 0);
            break;

        case 56:  // right
            player_move_b(1, 0);
            break;

        case 'O':  // open
            player_open_b();
            break;

        case 'C':  // close
            player_close_b();
            break;            

        case 'P':  // pickup - get
            player_pickup_b();
            break;

        case 'D':  // drop
            player_drop_b();
            break;

        case 'A':  // strike
            player_strike_b();
            break;                            

        case 'I':  // list inventory
            player_inventory_list_b();
            break;

        case 'Q':  // show inventory
            player_quaff_b();
            break;      

        case 'W':  // wield
            player_wield_b();
            break;

        case 'E':  // list equipped
            player_equipment_list_b();
            break;

        case 'T':  // take off
            player_takeoff_b();
            break;                                     

        case '1':
            dungeonmap_scroll(-1, 0);
            break;
        case '2':
            dungeonmap_scroll(1, 0);
            break;
        case '3':
            dungeonmap_scroll(0, -1);
            break;
        case '0':
            dungeonmap_scroll(0, 1);
            break;
        default:
            // text_print_int8(24, 20, key);
            break;
    }
}

uint8_t get_dir_or_cancel_b(int8_t *dx, int8_t *dy)
{
    unsigned int key;

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key   

    switch (toupper(key))
    {

    case 54: // down
        *dx = 0;
        *dy = 1;
        return 1;

    case 55: // up
        *dx = 0;
        *dy = -1;
        return 1;

    case 53: // left
        *dx = -1;
        *dy = 0;
        return 1;

    case 56: // right
        *dx = 1;
        *dy = 0;
        return 1;

    default:
        return 0;
    }
}



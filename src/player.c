/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    <Module description>

 ***************************************************/
#include "player.h"

#include <stdint.h>             // standard names for ints with no ambiguity 
#include <input.h>
#include <ctype.h>              // character classification e.g. toupper() 
#include <stddef.h>             // NULL
#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions

#include "entity_creature.h"
#include "entity_creature_move.h"
#include "entity_creature_pickup.h"
#include "dungeon_map.h"
#include "ai_pathfind.h"

#include "player_inventory.h"

#include "messages.h"
#include "text.h"

/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * public variables
 ***************************************************/
creature_t *creature_player_ptr;
entity_t *entity_player_ptr;

uint8_t     player_base_strength;
uint8_t     player_base_dexterity;    
uint8_t     player_base_constitution;    
uint8_t     player_base_intelligence;
uint8_t     player_base_wisdom;
uint8_t     player_base_charisma;

uint8_t     player_base_ac;
    
uint8_t     player_base_max_hp;
int8_t      player_base_curr_hp;

uint8_t     player_base_speed;

/***************************************************
 * private variables - static
 ***************************************************/




/***************************************************
 * functions definitions
 ***************************************************/


void player_create(uint8_t x, uint8_t y)
{
    creature_player_ptr = entity_creature_create(PLAYER, x, y);
    entity_player_ptr = creature_player_ptr->entity_ptr;

    player_base_strength = creature_player_ptr->strength;
    player_base_constitution = creature_player_ptr->constitution;
    player_base_dexterity = creature_player_ptr->dexterity;    
    player_base_intelligence = creature_player_ptr->intelligence;    
    player_base_wisdom = creature_player_ptr->wisdom;
    player_base_charisma = creature_player_ptr->charisma;

    player_base_ac = creature_player_ptr->ac;
    player_base_max_hp = creature_player_ptr->max_hp;
    player_base_curr_hp = creature_player_ptr->curr_hp;
    player_base_speed = creature_player_ptr->speed;
}

void player_turn()
{
    unsigned char key;

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    switch(toupper(key)) {
        case 54:    //down
            entity_creature_move_or_strike(creature_player_ptr, 0, 1);
            ai_pathfind(entity_player_ptr->x, entity_player_ptr->y);  
            break;
        case 55:    //up
            entity_creature_move_or_strike(creature_player_ptr, 0, -1);
            ai_pathfind(entity_player_ptr->x, entity_player_ptr->y);             
            break;
        case 53:    //left
            entity_creature_move_or_strike(creature_player_ptr, -1, 0);       
            ai_pathfind(entity_player_ptr->x, entity_player_ptr->y);             
            break;
        case 56:    //right
            entity_creature_move_or_strike(creature_player_ptr, 1, 0);          
            ai_pathfind(entity_player_ptr->x, entity_player_ptr->y);             
            break;
        case 'I':
            player_inventory_display(creature_player_ptr);
            break;
        
        case 'P':
            entity_creature_pickup(creature_player_ptr);
            break;

        case 'W':
            player_inventory_wear(creature_player_ptr);         
            break;

        case 'T':
            player_inventory_takeoff(creature_player_ptr);  
            break;

        case 'D':
            player_inventory_drop(creature_player_ptr);
            break;                      

        case '1':
            dungeon_map_scroll(-1, 0);
            dungeon_map_draw();
            entity_draw_all();    
            break;
        case '2':
            dungeon_map_scroll(1, 0);
            dungeon_map_draw();
            entity_draw_all(); 
            break;
        case '3':
            dungeon_map_scroll(0, -1);
            dungeon_map_draw();
            entity_draw_all(); 
            break;
        case '0':
            dungeon_map_scroll(0, 1);
            dungeon_map_draw();
            entity_draw_all(); 
            break;
        default:
            text_print_int8(24, 20, key);
            break;
    }
}

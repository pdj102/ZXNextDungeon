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

        case 'E':
            player_inventory_wear(creature_player_ptr);         
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

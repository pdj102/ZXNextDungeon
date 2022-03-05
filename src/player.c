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

#include "entity_creature.h"
#include "entity_creature_move.h"
#include "entity_creature_pickup.h"
#include "dungeon_map.h"
#include "ai_pathfind.h"
#include "messages.h"

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
 * private variables
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
        case 'S':
            entity_creature_move_or_strike(creature_player_ptr, 0, 1);
            ai_pathfind(creature_player_ptr->entity_ptr->x, creature_player_ptr->entity_ptr->y);  
            break;
        case 'W':
            entity_creature_move_or_strike(creature_player_ptr, 0, -1);
            ai_pathfind(creature_player_ptr->entity_ptr->x, creature_player_ptr->entity_ptr->y);             
            break;
        case 'A':
            entity_creature_move_or_strike(creature_player_ptr, -1, 0);
            ai_pathfind(creature_player_ptr->entity_ptr->x, creature_player_ptr->entity_ptr->y);             
            break;
        case 'D':
            entity_creature_move_or_strike(creature_player_ptr, 1, 0);
            ai_pathfind(creature_player_ptr->entity_ptr->x, creature_player_ptr->entity_ptr->y);             
            break;
        case 'P':
            entity_creature_pickup(creature_player_ptr);
            break;            
        case '4':
            dungeon_map_scroll(-1, 0);
            dungeon_map_draw();
            entity_draw_all();    
            break;
        case '6':
            dungeon_map_scroll(1, 0);
            dungeon_map_draw();
            entity_draw_all(); 
            break;
        case '8':
            dungeon_map_scroll(0, -1);
            dungeon_map_draw();
            entity_draw_all(); 
            break;
        case '2':
            dungeon_map_scroll(0, 1);
            dungeon_map_draw();
            entity_draw_all(); 
            break;                        
    }
}

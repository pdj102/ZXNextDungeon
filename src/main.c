/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <stdint.h>             // standard names for ints with no ambiguity 
#include <input.h>
#include <stdio.h>
#include <ctype.h>              // character classification e.g. toupper()
#include <stdbool.h>            // define true and false 

#include "entity.h"
#include "dungeon_map.h"
#include "tilemap.h"
#include "tile_defns.h"
#include "entity_creature.h"
#include "messages.h"

#define printAt(row, col)    printf("\x16%c%c", row, col)


/***************************************************
 * function prototypes
 ***************************************************/
void hit(uint8_t x, uint8_t y);


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * variables
 ***************************************************/
unsigned char key;

entity_t *entity_player_ptr;

creature_t *creature0;
creature_t *creature1;
creature_t *creature2;

item_t item1 = {1};


void print_dungeon()
{
    dungeon_map_draw();

    entity_draw_all();

    messages_display();
}

void init_game()
{
    dungeon_map_init();

    entity_init();
    
    tilemap_init();

    messages_init();

    entity_create_creature(11, 11, snake);
    entity_create_creature(2, 2, snake);
    entity_create_item(13, 13, ring);
    entity_player_ptr = entity_create_creature(5, 5, player);
 
}



void snake_turn(entity_t *entity_ptr)
{
    if (entity_ptr->creature_ptr->state == asleep ) {
        // do nothing
    }

    if (entity_ptr->creature_ptr->state == attacking ) {
        if (entity_ptr->y > entity_player_ptr->y) {
            if (entity_move_or_strike(entity_ptr, 0, -1)) return;
        }
        if (entity_ptr->y < entity_player_ptr->y) {
            if (entity_move_or_strike(entity_ptr, 0, 1)) return;
        }
        if (entity_ptr->x > entity_player_ptr->x) {
            if (entity_move_or_strike(entity_ptr, -1, 0)) return;
        }
        if (entity_ptr->x < entity_player_ptr->x) {
            if (entity_move_or_strike(entity_ptr, 1, 0)) return;
        }
    }
}

void player_turn()
{
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    switch(toupper(key)) {
        case 'S':
            entity_move_or_strike(entity_player_ptr, 0, 1);
            break;
        case 'W':
            entity_move_or_strike(entity_player_ptr, 0, -1);
            break;
        case 'A':
            entity_move_or_strike(entity_player_ptr, -1, 0);
            break;
        case 'D':
            entity_move_or_strike(entity_player_ptr, 1, 0);
            break;
        case '4':
            dungeon_map_scroll(-1, 0);
            print_dungeon();            
            break;
        case '6':
            dungeon_map_scroll(1, 0);
            print_dungeon();
            break;
        case '8':
            dungeon_map_scroll(0, -1);
            print_dungeon();
            break;
        case '2':
            dungeon_map_scroll(0, 1);
            print_dungeon();
            break;                        
    }
}

void play_game()
{

    entity_t *entity_ptr = entity_front();


    // step through each entity
    while(entity_ptr)
    {
        // increment energy
        if (entity_ptr->current_energy < 10)
        {
            entity_ptr->current_energy++;
        }
        

        // enough energy to take a turn?
        // TODO change energy system so can current energy decreases each turn, can take action when current energy is 0 and the action adds to the current energy
        if (entity_ptr->current_energy >= 10) {
            if (entity_ptr == entity_player_ptr) {
                player_turn();
            } else if (entity_ptr->type == creature) {
                snake_turn(entity_ptr);
            }
        }
    entity_ptr = entity_next(entity_ptr);
    }
}

 

int main()
{
    uint8_t b = 1;

    init_game();

    print_dungeon();

    while(entity_player_ptr) {
        play_game();
        entity_draw_all();
        entity_creature_draw_stat_block(entity_player_ptr->creature_ptr);

        zx_border(b);
        b = b==1 ? 0 : 1;
    };  
    return 0;
}

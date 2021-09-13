/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <stdio.h> 
#include <stdint.h>             // standard names for ints with no ambiguity 
#include <input.h>
#include <ctype.h>              // character classification e.g. toupper()
#include <stdbool.h>            // define true and false 

#include "entity.h"
#include "dungeon_map.h"


/***************************************************
 * function prototypes
 ***************************************************/
void hit(uint8_t y, uint8_t x);


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * variables
 ***************************************************/
unsigned char key;

entity_t *entity_player_ptr;


// Define some macros to make use of tty_z88dk control codes
// Program must be compiled with a CRT that supports tty_z88dk e.g. -startup=1
#define printInk(k)          printf("\x10%c", '0'+(k))
#define printPaper(k)        printf("\x11%c", '0'+(k))
#define printAt(row, col)    printf("\x16%c%c", (col)+1, (row)+1)

void print_dungeon()
{
    dungeon_map_print();

    entity_print();

}

void init_game()
{
    // init

    dungeon_map_init();

    entity_init();
    entity_player_ptr = entity_player();
 
}

// returns TRUE (1) if dungeon tile is empty
bool is_square_empty(uint8_t y, uint8_t x)
{
    // Is dungeon square passable
    if (!dungeon_map_passable(y, x)) {
        return false;
    }

    if(!entity_passable(y, x)) {
        return false;
    }
    return true;
}

uint8_t move(entity_t *entity_ptr, int8_t dy, int8_t dx)
{
    if (is_square_empty(entity_ptr->y+dy, entity_ptr->x+dx)) {
        // redraw dungeon tile
        dungeon_map_print_tile(entity_ptr->y, entity_ptr->x);
        entity_ptr->y +=dy;
        entity_ptr->x +=dx;
        entity_ptr->current_energy = 0;
        return 1;
    }
    else 
    {
        hit(entity_ptr->y+dy, entity_ptr->x+dx);
        entity_ptr->current_energy = 0;
    }
    return 0;
}

void hit(uint8_t y, uint8_t x)
{
    entity_t *entity_ptr;
    entity_ptr = entity_at(y, x);

    if (entity_ptr == NULL) return;

    if (entity_ptr->type == creature) {
        entity_ptr->creature_ptr->hp--;
        if (entity_ptr->creature_ptr->hp <= 0 )
        {
            entity_ptr->c = 'x';
            entity_remove(entity_ptr);
        }
    }

}

void snake_turn(entity_t *entity_ptr)
{
    if (entity_ptr->creature_ptr->state == asleep ) {
        // do nothing
    }

    if (entity_ptr->creature_ptr->state == attacking ) {
        if (entity_ptr->y > entity_player_ptr->y) {
            if (move(entity_ptr, -1, 0)) return;
        }
        if (entity_ptr->y < entity_player_ptr->y) {
            if (move(entity_ptr, 1, 0)) return;
        }
        if (entity_ptr->x > entity_player_ptr->x) {
            if (move(entity_ptr, 0, -1)) return;
        }
        if (entity_ptr->x < entity_player_ptr->x) {
            if (move(entity_ptr, 0, 1)) return;
        }
    }
}

void player_turn()
{
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    switch(toupper(key)) {
        case 'S':
            move(entity_player_ptr, 1, 0);
            break;
        case 'W':
            move(entity_player_ptr, -1, 0);
            break;
        case 'A':
            move(entity_player_ptr, 0, -1);
            break;
        case 'D':
            move(entity_player_ptr, 0, 1);
            break;
        case '4':
            dungeon_map_scroll(0, -1);
            print_dungeon();            
            break;
        case '6':
            dungeon_map_scroll(0, 1);
            print_dungeon();
            break;
        case '8':
            dungeon_map_scroll(-1, 0);
            print_dungeon();
            break;
        case '2':
            dungeon_map_scroll(1, 0);
            print_dungeon();
            break;                        
    }
}

void play_game()
{

    entity_t *entity_ptr;

    // player entity is front of the entity list
    entity_ptr = entity_player_ptr;

    // step through each entity
    while(entity_ptr)
    {
        // increment energy
        entity_ptr->current_energy++;

        // enough energy to take a turn?
        if (entity_ptr->current_energy >= entity_ptr->turn_energy) {
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

    while(1) {
        play_game();
        entity_print();

        zx_border(b);
        b = b==1 ? 0 : 1;
    };  
    return 0;
}

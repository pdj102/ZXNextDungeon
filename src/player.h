/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    The player 

 ***************************************************/

#ifndef PLAYER_H 
    #define PLAYER_H 


#include <stdint.h>             // standard names for ints with no ambiguity 
   

#include "entity_creature.h"

/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations - extern
 ***************************************************/

extern creature_t *creature_player_ptr;
extern entity_t *entity_player_ptr;

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Create the player 
 * 
 * @param x dungeon x position
 * @param y dungeon y position
 * @return void
 */
void player_create(uint8_t x, uint8_t y);


/**
 * Players turn
 * 
 * @return void
 */
void player_turn();

#endif
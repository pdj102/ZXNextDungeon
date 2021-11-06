/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    The player 

 ***************************************************/

#ifndef ENTITY_PLAYER_H 
    #define ENTITY_PLAYER_H 

#include <stdint.h>             // standard names for ints with no ambiguity 
   

#include "entity_creature.h"

/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations - extern
 ***************************************************/

extern creature_t *player_ptr;

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
void entity_player_create(uint8_t x, uint8_t y);


#endif
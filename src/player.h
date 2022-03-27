/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    The player 

 ***************************************************/

#ifndef PLAYER_H 
    #define PLAYER_H 


#include <stdint.h>             // standard names for ints with no ambiguity 
   
#include "entity_item.h"
#include "entity_creature.h"

/***************************************************
 * public types
 ***************************************************/


/***************************************************
 * public variable declarations 
 ***************************************************/

extern creature_t *creature_player_ptr;
extern entity_t *entity_player_ptr;

extern uint8_t     player_base_strength;
extern uint8_t     player_base_dexterity;    
extern uint8_t     player_base_constitution;    
extern uint8_t     player_base_intelligence;
extern uint8_t     player_base_wisdom;
extern uint8_t     player_base_charisma;

extern uint8_t     player_base_ac;
    
extern uint8_t     player_base_max_hp;
extern int8_t      player_base_curr_hp;

extern uint8_t     player_base_speed;


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
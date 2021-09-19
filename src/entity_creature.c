/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Creature entity

 ***************************************************/
#include "entity_creature.h"

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

#include "tile_defns.h"

#define printAt(row, col)    printf("\x16%c%c", row, col)

/***************************************************
 * private types
 ***************************************************/




/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/

/***************************************************
 * function definitions
 ***************************************************/


creature_t *entity_creature_create(creature_type_t e)
{
    creature_t *c = (creature_t *) malloc(sizeof(creature_t));

    switch (e)
    {
        case player :
            c->max_hp   = 8;
            c->curr_hp  = 8;

            c->ac       = 10;

            c->lvl      = 1;
            c->exp      = 0;

            c->speed    = 5;

            c->dmg      = 6;
            c->state    = attacking;

            c->tile     = TILE_PLAYER;
            c->blocking = 1;
    uint8_t blocking; 
            break;
        case snake :
            c->max_hp   = 4;
            c->curr_hp  = 4;
            c->ac       = 4;
            c->lvl      = 1;
            c->exp      = 0;
            c->speed    = 2;                        
            c->dmg      = 2;
            c->state    = attacking;

            c->tile     = TILE_SNAKE;
            c->blocking = 1;            
    }

    return c;
}

void entity_creature_draw_stat_block(creature_t *c)
{
    printAt(21, 1);
    printf("HP: %u (%u)", c->curr_hp, c->max_hp);
    printAt(21, 2);    
    printf("AC: %u", c->ac);
    printAt(21, 3);    
    printf("Exp: %u", c->exp);
    printAt(21, 4);    
    printf("Lvl: %u", c->lvl);
    printAt(21, 5);
    printf("Speed: %u", c->speed);
}

void entity_creature_delete(creature_t *creature_ptr)
{
    free(creature_ptr);
}
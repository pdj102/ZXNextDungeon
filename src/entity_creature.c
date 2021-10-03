/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Creature entity

 ***************************************************/
#include "entity_creature.h"

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tile_defns.h"
#include "dice.h"

#define printAt(col, row)    printf("\x16%c%c", col, row)

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
            strcpy(c->name, "PAUL");
            strcpy(c->creature, "HUMAN");

            c->lvl      = 1;
            c->exp      = 0;
            c->nxt      = 100;

            c->str      = 12;
            c->inte      = 12;
            c->wis      = 12;
            c->dex      = 12;
            c->con      = 12;

            c->ac       = 10;            

            c->max_hp   = 8;
            c->curr_hp  = 8;

            c->dmg_die_p   = dice_1d6_p;

            c->speed    = 5;

            c->state    = attacking;

            c->tile     = TILE_PLAYER;
            c->tile_attr = 0b00010000; // palette offset 1
            c->blocking = 1;
            break;
        case snake :
            strcpy(c->name, "SNAKE");
            strcpy(c->creature, "SNAKE");
            c->lvl      = 1;
            c->exp      = 0;
            c->nxt      = 100;

            c->str      = 5;
            c->inte     = 5;
            c->wis      = 5;
            c->dex      = 5;
            c->con      = 5;

            c->ac       = 4;            

            c->max_hp   = 4;
            c->curr_hp  = 4;

            c->dmg_die_p    = dice_1d2_p;

            c->speed    = 2;

            c->state    = attacking;

            c->tile     = TILE_SNAKE;
            c->tile_attr = 0b00100000; // palette offset 2
            c->blocking = 1;            
    }

    return c;
}

void entity_creature_draw_stat_block(creature_t *c)
{
    printAt(21, 1);
    printf("%s", c->name);
    printAt(21, 2);
    printf("%s", c->creature);
    printAt(21, 3);
    printf("LEVEL  %u", c->lvl);
    printAt(21, 4);
    printf("EXP    %u", c->exp);

    printAt(21, 6);
    printf("STR:   %2u", c->str);
    printAt(21, 7);
    printf("INT:   %2u", c->inte);
    printAt(21, 8);
    printf("WIS:   %2u", c->wis);
    printAt(21, 9);
    printf("DEX:   %2u", c->dex);
    printAt(21, 10);
    printf("CON:   %2u", c->con);

    printAt(21, 12);
    printf("AC:    %u", c->ac);
    printAt(21, 13);    
    printf("HP: %2u/ %2u", c->curr_hp, c->max_hp);

    printAt(21, 14);
    printf("SPEED: %2u", c->speed);
}

void entity_creature_delete(creature_t *creature_ptr)
{
    free(creature_ptr);
}  
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

#include "entity.h"
#include "tile_defns.h"
#include "dice.h"
#include "text.h"

//#define printAt(col, row)    printf("\x16%c%c", col, row)

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


creature_t *entity_creature_create(creature_type_t creature_type, uint8_t x, uint8_t y)
{
    creature_t *c = (creature_t *) malloc(sizeof(creature_t)); 

    entity_t *e = entity_create();

    c->entity_p = e;

    e->type      = creature;
    e->ptr = (void*)c;
    e->current_energy = 0;   
    e->x = x;
    e->y = y;
    e->blocking = 1;    

    switch (creature_type)
    {
        case PLAYER :
            strcpy(c->name, "PAUL");
            strcpy(c->creature, "HUMAN");

            c->size = MEDIUM; 
             
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

            c->state    = ATTACKING;



        
            e->tile     = TILE_PLAYER;
            e->tile_attr = 0b00010000; // palette offset 1

            break;
        case SNAKE :
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

            c->state    = ATTACKING;

            //c->entity = entity_p;

            e->tile     = TILE_SNAKE;
            e->tile_attr = 0b00100000; // palette offset 2
           
    }

    // create entity

    return c;
}

void entity_creature_draw_stat_block(creature_t *c)
{
    char s[] = "25500";

    text_print(24, 0, c->name);
    text_print(24, 1, c->creature);
    text_print(24, 2, "LEVEL");
    text_print(24, 3, "EXP");

    text_print(24, 5, "STR:");
    text_print(24, 6, "INT:");
    text_print(24, 7, "WIS:");
    text_print(24, 8, "DEX:");
    text_print(24, 9, "CON:");

    text_print(24, 11, "AC:");
    text_print(24, 12, "HP:");

    text_print(24, 13, "SPEED:");

    itoa(c->lvl, s, 10);
    text_print(30, 2, s);

    itoa(c->exp, s, 10);
    text_print(30, 3, s);

    itoa(c->str, s, 10);
    text_print(30, 5, s);
    itoa(c->inte, s, 10);
    text_print(30, 6, s);
    itoa(c->wis, s, 10);
    text_print(30, 7, s);
    itoa(c->dex, s, 10);
    text_print(30, 8, s);
    itoa(c->con, s, 10);
    text_print(30, 9, s);
    
    itoa(c->ac, s, 10);
    text_print(30, 11, s);
    itoa(c->curr_hp, s, 10);
    text_print(30, 12, s);

    itoa(c->speed, s, 10);
    text_print(30, 13, s);

    /*
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
    */
}

void entity_creature_turn(creature_t *creature_ptr)
{
    if (creature_ptr->state == asleep ) {
        // do nothing
    }

    if (creature_ptr->state == attacking ) {
        if (creature_ptr->entity_ptr->y > entity_player_ptr->y) {
            if (entity_creature_move_or_strike(entity_ptr, 0, -1)) return;
        }
        if (creature_ptr->entity_ptr->y < entity_player_ptr->y) {
            if (entity__creature_move_or_strike(entity_ptr, 0, 1)) return;
        }
        if (creature_ptr->entity_ptr->x > entity_player_ptr->x) {
            if (entity__creature_move_or_strike(entity_ptr, -1, 0)) return;
        }
        if (creature_ptr->entity_ptr->x < entity_player_ptr->x) {
            if (entity__creature_move_or_strike(entity_ptr, 1, 0)) return;
        }
    }
}

uint8_t entity_creature_move_or_strike(creature_t *creature_ptr, int8_t dx, int8_t dy)
{
    return 1;
}

void entity_creature_delete(creature_t *creature_ptr)
{
    free(creature_ptr);
}  
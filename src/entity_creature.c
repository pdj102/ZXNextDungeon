/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    Creature entity

 ***************************************************/
#include "entity_creature.h"

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "entity.h"
#include "entity_player.h"
#include "tile_defns.h"
#include "dice.h"
#include "text.h"
#include "messages.h"
#include "memory_map.h"

#define DEBUG 


/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/
// Pointer to base memory address for entities
static creature_t *entity_creature_base_ptr;

// Ensure sizeof(entity_t) * max_entity_records fits within allocated memory!
static uint8_t max_entity_creature_records; 

/***************************************************
 * function definitions
 ***************************************************/

void entity_creature_init()
{
    // creatures are stored in memory at CREATURE_BASE address
    entity_creature_base_ptr = (creature_t *)CREATURE_BASE;

    // set max number of entities 
    max_entity_creature_records = CREATURE_SIZE / sizeof(creature_t);

    #ifdef DEBUG
    messages_print_s_uint8("MAX CREATURE: ",max_entity_creature_records);
    #endif

     for(uint8_t n = 0; n < max_entity_creature_records; n++)
    {
        entity_creature_base_ptr[n].record = 0;
    }
}

creature_t *entity_creature_new()
{
   // Find a free creature record 
    for(uint8_t n = 0; n < max_entity_creature_records; n++)
    {
        if (entity_creature_base_ptr[n].record == 0 )
        {
            entity_creature_base_ptr[n].record = n + 1; // mark record as in use
            return &entity_creature_base_ptr[n];
        }
    }
    messages_print("FAILED TO CREATE CREATURE");
    return NULL;

}

creature_t *entity_creature_create(creature_type_t creature_type, uint8_t x, uint8_t y)
{
    creature_t *c; 

    entity_t *e = entity_create();
    if (e == NULL) 
    {
        // Failed to create entity
        return NULL;
    }

    c = entity_creature_new();
    if (c == NULL)
    {
        // Failed to create creature
        return NULL;
    }

    c->entity_ptr = e;

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

            c->size = SMALL; 

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

            e->tile     = TILE_SNAKE;
            e->tile_attr = 0b00100000; // palette offset 2      
    }

    // create entity
    return c;
}

void entity_creature_draw_stat_block(creature_t *creature_ptr)
{
    char s[] = "25500";     // string buffer for converting numbers to strings

    text_print(24, 0, creature_ptr->name);
    text_print(24, 1, creature_ptr->creature);
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

    itoa(creature_ptr->lvl, s, 10);
    text_print(30, 2, s);

    itoa(creature_ptr->exp, s, 10);
    text_print(30, 3, s);

    itoa(creature_ptr->str, s, 10);
    text_print(30, 5, s);
    itoa(creature_ptr->inte, s, 10);
    text_print(30, 6, s);
    itoa(creature_ptr->wis, s, 10);
    text_print(30, 7, s);
    itoa(creature_ptr->dex, s, 10);
    text_print(30, 8, s);
    itoa(creature_ptr->con, s, 10);
    text_print(30, 9, s);
    
    itoa(creature_ptr->ac, s, 10);
    text_print(30, 11, s);
    itoa(creature_ptr->curr_hp, s, 10);
    text_print(30, 12, s);

    itoa(creature_ptr->speed, s, 10);
    text_print(30, 13, s);
}

void entity_creature_turn(creature_t *creature_ptr)
{
    if (creature_ptr->state == ASLEEP ) {
        // do nothing
    }

    if (creature_ptr->state == ATTACKING ) {
        if (creature_ptr->entity_ptr->y > entity_player_ptr->y) {
            if (entity_creature_move_or_strike(creature_ptr, 0, -1)) return;
        }
        if (creature_ptr->entity_ptr->y < entity_player_ptr->y) {
            if (entity_creature_move_or_strike(creature_ptr, 0, 1)) return;
        }
        if (creature_ptr->entity_ptr->x > entity_player_ptr->x) {
            if (entity_creature_move_or_strike(creature_ptr, -1, 0)) return;
        }
        if (creature_ptr->entity_ptr->x < entity_player_ptr->x) {
            if (entity_creature_move_or_strike(creature_ptr, 1, 0)) return;
        }
    }
}

uint8_t entity_creature_move_or_strike(creature_t *creature_ptr, int8_t dx, int8_t dy)
{
    if (entity_creature_move(creature_ptr, dx, dy))
    {
        // succeeded in moving 
        return 1;
    }
    // try striking instead
    return (entity_creature_strike(creature_ptr, dx, dy));
}

uint8_t entity_creature_move(creature_t *creature_ptr, int8_t dx, int8_t dy)
{
    uint8_t effort;

    if(entity_move(creature_ptr->entity_ptr, dx, dy))
    {
        // decrease entity energy by 10 - speed
        effort = (10 - creature_ptr->speed);
        entity_reduce_energy(creature_ptr->entity_ptr, effort);
        //messages_print("decrease energy");
        return 1;
    }
    return 0;
}

creature_t *entity_creature_at(uint8_t x, uint8_t y)
{
    entity_t *target_entity_ptr = entity_first_at( x, y);

    while(target_entity_ptr != NULL)
    {
        if (target_entity_ptr->type == creature)
        {
            return (creature_t *)target_entity_ptr->ptr;
        }
        target_entity_ptr = entity_next_at( x, y, target_entity_ptr );
    }
    return NULL;
}

uint8_t entity_creature_strike(creature_t *attacker_creature_ptr, int8_t dx, int8_t dy)
{
    uint8_t attack_roll;
    uint8_t dmg_roll;

    char message[40];

    creature_t *target_creature_ptr;
  
    target_creature_ptr = entity_creature_at( attacker_creature_ptr->entity_ptr->x+dx, attacker_creature_ptr->entity_ptr->y+dy );

    if (target_creature_ptr == NULL)
    {
        // no creature to strike at
        return 0;
    }

    // Attempt strike on creature

    // decrease energy by speed
    attacker_creature_ptr->entity_ptr->current_energy = (10 - attacker_creature_ptr->speed);

    // attack roll
    attack_roll = dice_roll_1d20();

    // 012345678901234567890123456789
    // AAAAAAAAAA STRIKES TTTTTTTTTT
    sprintf(message, "%s STRIKES %s", attacker_creature_ptr->name, target_creature_ptr->name);
    messages_print(message);

    // Sucessful hit?
    if (attack_roll > target_creature_ptr->ac)
    {
        // todo roll for damage
        dmg_roll = dice_roll(attacker_creature_ptr->dmg_die_p);
        target_creature_ptr->curr_hp -= dmg_roll;

        // 012345678901234567890123456789
        // DD points damage
        sprintf(message, "%u POINTS DAMAGE", dmg_roll);
        messages_print(message);

        // Is target dead?
        if (target_creature_ptr->curr_hp <= 0)
        {
            // 012345678901234567890123456789
            // TTTTTTTTTT is killed!
            sprintf(message, "%s IS KILLED!", target_creature_ptr->name);
            messages_print(message);

            entity_creature_delete(target_creature_ptr);
        }
        else
        {
            // todo entity_event_hit();
        }
    }
    else
    {
        // Miss!
        sprintf(message, "%s MISSES", attacker_creature_ptr->name);
        messages_print(message);
    }
    return 1;
}

void entity_creature_delete(creature_t *creature_ptr)
{
    entity_delete(creature_ptr->entity_ptr);
    
    creature_ptr->record = 0;   // mark record as free
}  
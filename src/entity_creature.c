/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    Creature entity

 ***************************************************/
#include "entity_creature.h"

#include "entity_creature_move.h"

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>     // strcpy()

#include "entity.h"
#include "player.h"
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
    messages_println("FAILED TO CREATE CREATURE");
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
    e->location = dungeon;    
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

            c->strength      = 12;
            c->dexerity      = 12;            
            c->constitution      = 12;
            c->intelligence      = 12;
            c->wisdom      = 12;
            c->charisma      = 12;

            c->ac       = 10;            

            c->max_hp   = 8;
            c->curr_hp  = 8;

            c->melee_attack_1.damage_kind = SLASHING;
            c->melee_attack_1.proficiency_mod = 2;
            c->melee_attack_1.dmg_die.n = 1;
            c->melee_attack_1.dmg_die.d = 6;
            c->melee_attack_1.dmg_die.modifier = 0;

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

            c->strength         = 10;
            c->dexerity         = 5;            
            c->constitution     = 12;
            c->intelligence     = 1;            
            c->wisdom           = 10;
            c->charisma         = 3;

            c->ac       = 4;            

            c->max_hp   = 4;
            c->curr_hp  = 4;

            c->melee_attack_1.damage_kind = SLASHING;
            c->melee_attack_1.proficiency_mod = 2;            
            c->melee_attack_1.dmg_die.n = 1;
            c->melee_attack_1.dmg_die.d = 4;
            c->melee_attack_1.dmg_die.modifier = 0;

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
    text_print(24, 10, "CHA:");    

    text_print(24, 11, "AC:");
    text_print(24, 12, "HP:");

    text_print(24, 13, "SPEED:");

    itoa(creature_ptr->lvl, s, 10);
    text_print(30, 2, s);

    itoa(creature_ptr->exp, s, 10);
    text_print(30, 3, s);

    itoa(creature_ptr->strength, s, 10);
    text_print(30, 5, s);
    itoa(creature_ptr->intelligence, s, 10);
    text_print(30, 6, s);
    itoa(creature_ptr->wisdom, s, 10);
    text_print(30, 7, s);
    itoa(creature_ptr->dexerity, s, 10);
    text_print(30, 8, s);
    itoa(creature_ptr->constitution, s, 10);
    text_print(30, 9, s);
    itoa(creature_ptr->charisma, s, 10);
    text_print(30, 10, s);    
    
    itoa(creature_ptr->ac, s, 10);
    text_print(30, 11, s);
    itoa(creature_ptr->curr_hp, s, 10);
    text_print(30, 12, s);

    itoa(creature_ptr->speed, s, 10);
    text_print(30, 13, s);
}



int8_t ability_modifier(uint8_t ability)
{
    switch (ability)
    {
    case 0 :
    case 1 :
        return -5;
        break;
    case 2 :
    case 3 :
        return -4;
        break;
    case 4 :
    case 5 :
        return -3;
        break;
    case 6 :
    case 7 :
        return -2;
        break;
    case 8 :
    case 9 :
        return -1;
        break;
    case 10 :
    case 11 :
        return 0;
        break;
    case 12 :
    case 13 :
        return 1;
        break;
    case 14 :
    case 15 :
        return 2;
        break;
    case 16 :
    case 17 :
        return 3;
        break;
    case 18 :
    case 19 :
        return 4;
        break;
    default:
        return 4;
        break;
    }
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



void entity_creature_delete(creature_t *creature_ptr)
{
    entity_delete(creature_ptr->entity_ptr);
    
    creature_ptr->record = 0;   // mark record as free
}  
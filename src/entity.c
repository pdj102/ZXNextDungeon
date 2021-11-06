/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manage entities. An entity represents an item, effect or creature

    Provides functions that can be used on any type of entity.
    Entity type specific functions are provided in specific module e.g. entity_creature

 ***************************************************/
#include "entity.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <adt/p_forward_list.h> // linked list
#include <stdio.h>
#include <stdlib.h>

#include "dungeon_map.h"
#include "dice.h"
#include "messages.h"


/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/


/***************************************************
 * private variables
 ***************************************************/
// Single linked list of all entities
static p_forward_list_t entities;

// Pointer to base memory address for entities
static entity_t *entity_base_ptr;

const uint8_t max_entity_records = 40;          // Ensure sizeof(entity_t) * max_entity_records fits within allocated memory!

/***************************************************
 * function definitions
 ***************************************************/

void entity_init()
{
    // Map bank 17 into ZX Spectrum 8k MMU slot 1
    ZXN_WRITE_REG(0x51, 17);    // Map 8k bank 16 into 8k slot 0

    p_forward_list_init(&entities);      // init entities p_forward_list

    entity_base_ptr = (entity_t *)0x2000;    // entities are stored starting at address 0x2000

     for(uint8_t n = 0; n < max_entity_records; n++)
    {
        entity_base_ptr[n].record = 0;
    }
}


entity_t *entity_create()
{
    //entity_t *entity_ptr = (entity_t *) malloc(sizeof(entity_t));
    
    // Find a free entity record 
    for(uint8_t n = 0; n < max_entity_records; n++)
    {
        if (entity_base_ptr[n].record == 0 )
        {
            entity_base_ptr[n].record = n + 1; // mark record as in use
            entity_t *entity_ptr = &entity_base_ptr[n];
            p_forward_list_push_front(&entities, entity_ptr);
            return entity_ptr;
        }
    }
    messages_print("FAILED TO CREATE ENTITY");
    return NULL;
}

void entity_delete(entity_t *entity_ptr)
{
    dungeon_map_draw_tile(entity_ptr->x, entity_ptr->y);

    p_forward_list_remove(&entities, entity_ptr);

    entity_ptr->record = 0;      // mark record as free
}

entity_t *entity_front()
{
    return p_forward_list_front(&entities);
}

entity_t *entity_next(entity_t *entity_ptr)
{
    return p_forward_list_next(entity_ptr);
}


uint8_t entity_move(entity_t *entity_ptr, int8_t dx, int8_t dy)
{
    if (!dungeon_map_is_blocked(entity_ptr->x+dx, entity_ptr->y+dy)) {
        // redraw dungeon tile
        dungeon_map_draw_tile(entity_ptr->x, entity_ptr->y);
        entity_ptr->y +=dy;
        entity_ptr->x +=dx;
        return 1;
    }
    return 0;
}

void entity_reduce_energy(entity_t *entity_ptr, uint8_t effort)
{
    if (entity_ptr->current_energy < effort)
    {
        entity_ptr->current_energy = 0;
        return;
    }
    entity_ptr->current_energy = entity_ptr->current_energy - effort;
}

void entity_draw_all()
{
    entity_t *entity_ptr;

    // print entities
    for (entity_ptr = entity_front(); entity_ptr; entity_ptr = entity_next(entity_ptr))
    {
        dungeon_map_draw_entity(entity_ptr->x, entity_ptr->y, entity_ptr->tile, entity_ptr->tile_attr);
    }
}

uint8_t entity_is_blocking_at(uint8_t x, uint8_t y)
{
    entity_t *entity_ptr = entity_front();

    while (entity_ptr)
    {
        if (entity_ptr->y == y && entity_ptr->x == x && entity_ptr->blocking == 1) {
            return 1;   // found a blocking entity
        }
        entity_ptr = entity_next(entity_ptr);
    }
    // no blocking entity
    return 0;   
}

entity_t *entity_first_at(uint8_t x, uint8_t y)
{
    entity_t *entity_ptr = entity_front();

    while (entity_ptr)
    {
        if (entity_ptr->x == x && entity_ptr->y == y) {
            return entity_ptr;  // found entity at x y
        }
        entity_ptr = entity_next(entity_ptr);
    }
    return NULL; 
}

entity_t* entity_next_at(uint8_t x, uint8_t y, entity_t *entity_ptr)
{
    while( entity_ptr = entity_next(entity_ptr) )
    {
        if (entity_ptr->x == x && entity_ptr->y == y) {
            return entity_ptr;
        }
        entity_ptr = entity_next(entity_ptr);
    }
    return NULL;
}



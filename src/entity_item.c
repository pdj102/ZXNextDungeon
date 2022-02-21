/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Item entity

 ***************************************************/
#include "entity_item.h"

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>     // strcpy()

#include "tile_defns.h"

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
static item_t *entity_item_base_ptr;

// Ensure sizeof(entity_t) * max_entity_records fits within allocated memory!
static uint8_t max_entity_item_records; 

/***************************************************
 * function definitions
 ***************************************************/


void entity_item_init()
{
    // items are stored in memory at ITEM_BASE address
    entity_item_base_ptr = (item_t *)ITEM_BASE;

    // set max number of entities 
     max_entity_item_records = ITEM_SIZE / sizeof(item_t);
    // max_entity_item_records = 16;

    #ifdef DEBUG
    messages_print_s_uint8("MAX ITEMS: ",max_entity_item_records);
    #endif

    for(uint8_t n = 0; n < max_entity_item_records; n++)
    {
        entity_item_base_ptr[n].record = 0;
    }
}

item_t *entity_item_new()
{
   // Find a free item record 
    for(uint8_t n = 0; n < max_entity_item_records; n++)
    {
        if (entity_item_base_ptr[n].record == 0 )
        {
            entity_item_base_ptr[n].record = n + 1; // mark record as in use
            return &entity_item_base_ptr[n];
        }
    }
    messages_println("FAILED TO CREATE ITEM");
    return NULL;

}

item_t *entity_item_create(item_type_t item_type, uint8_t x, uint8_t y)
{
    item_t *i; 

    entity_t *e = entity_create();
    if (e == NULL) 
    {
        // Failed to create entity
        return NULL;
    }

    i = entity_item_new();
    if (i == NULL)
    {
        // Failed to create item
        return NULL;
    }

    i->entity_ptr = e;

    e->type      = item;
    e->ptr = (void*)i;
    e->current_energy = 0;   
    e->location = dungeon;
    e->x = x;
    e->y = y;
    e->blocking = 0;      

    switch (item_type)
    {
        case RING :
            strcpy(i->name, "RING");
            e->tile     = TILE_POTION;
            e->tile_attr = 0b01000000; // palette offset 2

        break;
    }

    return i;
}


item_t *entity_item_at(uint8_t x, uint8_t y)
{
    entity_t *target_entity_ptr = entity_first_at( x, y);

    while(target_entity_ptr != NULL)
    {
        if (target_entity_ptr->type == item)
        {
            return (item_t *)target_entity_ptr->ptr;
        }
      
        target_entity_ptr = entity_next_at( x, y, target_entity_ptr );
    }
    return NULL;
}

void entity_item_delete(item_t *item_ptr)
{
    entity_delete(item_ptr->entity_ptr);
    
    item_ptr->record = 0;   // mark record as free
}
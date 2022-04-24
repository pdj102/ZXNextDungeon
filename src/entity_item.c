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

#include "tilemap_tile_defns.h"
#include "palette.h"    // palette defs

#include "entity_creature.h"    // damage_kind_t    TODO refactor

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
 * private variables - static
 ***************************************************/
// Pointer to base memory address for entities
static entity_item_t *entity_item_base_ptr;

// Ensure sizeof(entity_t) * max_entity_records fits within allocated memory!
static uint8_t max_entity_item_records;

// Some handy items
// TDO move items[] and item creation into banked code

static const item_t items[] =
{
    {weapon_melee_class, short_sword, "SHORT SWORD", {TILE_SHORT_SWORD, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},  10, 2,      0,  {1, 6, 0}, SLASHING,  affect_none, 0},
    {weapon_melee_class, long_sword, "LONG SWORD", {TILE_LONG_SWORD, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},     15, 3,      0,  {1, 8, 0}, SLASHING,  affect_none, 0},

    {weapon_ranged_class, short_bow, "SHORT BOW", {TILE_LONG_BOW, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},        25, 2,      0,  {1, 6, 0}, PIERCING,  affect_none, 0},
    {weapon_ranged_class, long_bow, "LONG BOW", {TILE_LONG_BOW, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},          50, 2,      0,  {1, 8, 0}, PIERCING,  affect_none, 0},
    {weapon_ranged_class, sling, "SLING", {TILE_SLING, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},                   1, 0,       0,  {1, 4, 0}, BLUDGEON, affect_none, 0},

    {wand_class, wand_magic_missile, "MAGIC MISSILE", {TILE_POTION, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},      1000, 1,    0,  {1, 6, 0}, FIRE,    affect_none, 0},

    {armour_body_class, leather_armour, "LEATHER", {TILE_LEATHER_ARMOUR, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED}, 10, 10,     11, {0, 0, 0}, NONE,    affect_none, 0},
    {armour_body_class, chain_mail_armour, "CHAIN", {TILE_METAL_ARMOUR, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},  50, 20,     13, {0, 0, 0}, NONE,    affect_none, 0},   

    {armour_head_class, leather_helmet, "LEATHER", {TILE_HELMET, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},         5,  2,      0,  {0, 0, 0}, NONE,    affect_ac, 1},
    {armour_head_class, metal_helmet, "METAL", {TILE_HELMET, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},             10,  2,     0,  {0, 0, 0}, NONE,    affect_ac, 2},

    {armour_shield_class, leather_shield, "LEATHER", {TILE_SHIELD, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},       5,  2,      0,  {0, 0, 0}, NONE,    affect_ac, 1},
    {armour_shield_class, metal_shield, "METAL", {TILE_SHIELD, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},           10,  2,     0,  {0, 0, 0}, NONE,    affect_ac, 2},

    {ring_class, ring_hp, "RING HP", {TILE_RING, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_BLUE},                        500,  1,    0,  {0, 0, 0}, NONE,    affect_max_hp, 2}, 
    {ring_class, ring_str, "RING STR", {TILE_RING, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_BLUE},                      500,  1,    0,  {0, 0, 0}, NONE,    affect_strength, 2},
    {ring_class, ring_ac, "RING AC", {TILE_RING, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_BLUE},                        500,  1,    0,  {0, 0, 0}, NONE,    affect_ac, 2},

    {potion_class, red_potion, "RED POTION", {TILE_POTION, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_RED},               10, 1,      0,  {0,0,0,}, NONE,     affect_none, 0},
    {potion_class, blue_potion, "BLUE POTION", {TILE_POTION, NO_MIRROR | NO_ROTATE | PALETTE_ITEM_BLUE},            10, 1,    0,    {0,0,0,}, NONE,     affect_none,0},

};

/***************************************************
 * function definitions
 ***************************************************/


void entity_item_init()
{
    // items are stored in memory at ITEM_BASE address
    entity_item_base_ptr = (entity_item_t *)ITEM_BASE;

    // set max number of entities 
     max_entity_item_records = ITEM_SIZE / sizeof(entity_item_t);
    // max_entity_item_records = 16;

    #ifdef DEBUG
    messages_print_s_uint8("MAX ITEMS: ",max_entity_item_records);
    #endif

    for(uint8_t n = 0; n < max_entity_item_records; n++)
    {
        entity_item_base_ptr[n].record = 0;
    }
}

entity_item_t *entity_item_new()
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

entity_item_t *entity_item_create(items_t item, uint8_t x, uint8_t y)
{
    entity_item_t *i; 

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

    e->type      = entity_type_item;
    e->ptr = (void*)i;
    e->current_energy = 0;   
    e->location = dungeon;
    e->x = x;
    e->y = y;
    e->blocking = 0;

    i->item = items[item];

    e->tilemap_tile =i->item.tile;

/*
    i->item_class = items[item].item_class;
    i->item_type = items[item].item_type;
    i->affect = items[item].affect;
    i->affect_mod = items[item].affect_mod;   
    strcpy(i->name, items[item].name);
    e->tilemap_tile = items[item].tile;
*/
    return i;
}


entity_item_t *entity_item_first_at(uint8_t x, uint8_t y)
{
    entity_t *entity_ptr = entity_first_at( x, y);



    while(entity_ptr != NULL)
    {
        if (entity_ptr->type == entity_type_item)
        {
            return (entity_item_t *)entity_ptr->ptr;
        }
      
        entity_ptr = entity_next_at( x, y, entity_ptr );
    }
    return NULL;
}

entity_item_t* entity_item_next_at(uint8_t x, uint8_t y, const entity_item_t *item_ptr)
{
    entity_t *entity_ptr = item_ptr->entity_ptr;

    while( entity_ptr = entity_next_at(x, y, entity_ptr) )
    {
        if (entity_ptr->type == entity_type_item)
        {
            return (entity_item_t *)entity_ptr->ptr;
        }
    }
    return NULL;    
}

entity_item_t *entity_item_first_at_location(entity_location_t location)
{
    entity_t *entity_ptr = entity_first_at_location(location);

    while(entity_ptr != NULL)
    {
        if (entity_ptr->type == entity_type_item)
        {
            return (entity_item_t *)entity_ptr->ptr;
        }
      
        entity_ptr = entity_next_at_location( location, entity_ptr );
    }
    return NULL;
}

entity_item_t* entity_item_next_at_location(entity_location_t location, const entity_item_t *item_ptr)
{
    entity_t *entity_ptr = item_ptr->entity_ptr;

    while( entity_ptr = entity_next_at_location(location, entity_ptr) )
    {
        if (entity_ptr->type == entity_type_item)
        {
            return (entity_item_t *)entity_ptr->ptr;
        }
    }
    return NULL;    
}

entity_item_t *entity_item_get_nth_at_location(uint8_t index, entity_location_t location)
{
    uint8_t i = 1;    
    entity_item_t *item_ptr;

    item_ptr = entity_item_first_at_location(location);

    while (i < index)
    {
        i++;
        item_ptr = entity_item_next_at_location(location, item_ptr);

        if (item_ptr == NULL)
        {   
            messages_println("ERROR");  
            /* no such item - return */
            return NULL;
        }
    }
    return item_ptr;
}

void entity_item_delete(entity_item_t *item_ptr)
{
    entity_delete(item_ptr->entity_ptr);
    
    item_ptr->record = 0;   // mark record as free
}
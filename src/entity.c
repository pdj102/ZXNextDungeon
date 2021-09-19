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
#include "entity_creature.h"
#include "entity_item.h"


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

/***************************************************
 * function definitions
 ***************************************************/

void entity_init()
{
    p_forward_list_init(&entities);      // init entities p_forward_list
}

entity_t *entity_create_creature(uint8_t x, uint8_t y, creature_type_t c_type)
{
    entity_t *entity_ptr;
    //TODO validate inputs

    //TODO check for NULL
    // create creature
    creature_t *creature_ptr = entity_creature_create(c_type);

    // create entity of type creature
    entity_ptr = entity_create(x, y, creature_ptr->tile, creature_ptr->blocking, creature, creature_ptr, NULL);
    
    return entity_ptr;
}

entity_t *entity_create_item(uint8_t x, uint8_t y, item_type_t i_type)
{
    entity_t *entity_ptr;
    //TODO validate inputs

    //TODO check for NULL
    // create item
    item_t *item_ptr = entity_item_create(i_type);

    // create entity of type item
    entity_ptr = entity_create(x, y, item_ptr->tile, item_ptr->blocking, item, NULL, item_ptr);
    
    return entity_ptr;
}

entity_t *entity_create(uint8_t x, uint8_t y, uint8_t tile, uint8_t blocking, entity_type_t type, creature_t *creature_ptr, item_t *item_ptr)
{
    //TODO validate inputs

    entity_t *entity_ptr = (entity_t *) malloc(sizeof(entity_t));
    //TODO check for NULL

    entity_ptr->x = x;
    entity_ptr->y = y;
    entity_ptr->tile=tile;
    entity_ptr->blocking=blocking;
    entity_ptr->type = type;
    entity_ptr->creature_ptr = creature_ptr;
    entity_ptr->item_ptr = item_ptr;

    entity_ptr->current_energy = 0;

    p_forward_list_push_front(&entities, entity_ptr);

    return entity_ptr;
}

void entity_delete_entity(entity_t *entity_ptr)
{
    entity_delete(entity_ptr);

    if (entity_ptr->creature_ptr)
    {
        entity_creature_delete(entity_ptr->creature_ptr);
        entity_ptr->creature_ptr = NULL;
    }

    if (entity_ptr->item_ptr)
    {
        //entity_item_delete(entity_ptr->item_ptr);
        entity_ptr->item_ptr = NULL;
    }
    free(entity_ptr);
}

entity_t *entity_front()
{
    return p_forward_list_front(&entities);
}

entity_t *entity_next(entity_t *entity_ptr)
{
    return p_forward_list_next(entity_ptr);
}

void entity_draw_all()
{
    entity_t *entity_ptr;

    // print entities
    for (entity_ptr = p_forward_list_front(&entities); entity_ptr; entity_ptr = p_forward_list_next(entity_ptr))
    {
        dungeon_map_draw_entity(entity_ptr->x, entity_ptr->y, entity_ptr->tile);
    }
}

uint8_t entity_passable(uint8_t y, uint8_t x)
{
    entity_t *entity_ptr;

    // Does a unpassable entity occupy square
    for (entity_ptr = p_forward_list_front(&entities); entity_ptr; entity_ptr = p_forward_list_next(entity_ptr))
    {
        if (entity_ptr->y == y && entity_ptr->x == x && entity_ptr->blocking == 1) {
            return 0;
        }
    }
    return 1;
}

entity_t* entity_at(uint8_t y, uint8_t x, entity_t *entity_ptr)
{
    while( entity_ptr)
    {
        if (entity_ptr->x == x && entity_ptr->y == y) {
            return entity_ptr;
        }
        entity_ptr = entity_next(entity_ptr);
    }
    return NULL;
}

void entity_delete(entity_t *entity_ptr)
{
    p_forward_list_remove(&entities, entity_ptr);
}


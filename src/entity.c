/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/
#include "entity.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <adt/p_forward_list.h> // linked list
#include <stdio.h>

#include "dungeon_map.h"

#define printAt(row, col)    printf("\x16%c%c", (col)+1, (row)+1)

/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/

static p_forward_list_t entities;

creature_t creature1 = {8, asleep};
creature_t creature2 = {8, attacking};

item_t item1 = {1};

entity_t entity1 = {NULL, 5,5,  '@', 0,10,  1, creature, NULL       ,NULL };
entity_t entity2 = {NULL, 2,2,  's', 0,20,  1, creature, &creature1 ,NULL};
entity_t entity3 = {NULL, 11,11,'s', 0,20,  1, creature, &creature2 ,NULL};
entity_t entity4 = {NULL, 13,13,'r', 0,20,  0, item,    NULL,       &item1};

/***************************************************
 * functions
 ***************************************************/

void entity_init()
{
    p_forward_list_init(&entities);      // init entities p_forward_list

    p_forward_list_push_front(&entities,&entity4);    
    p_forward_list_push_front(&entities,&entity3);
    p_forward_list_push_front(&entities,&entity2);    
    p_forward_list_push_front(&entities,&entity1);  // player first in list
}

void entity_print()
{
    entity_t *entity_ptr;

    // print entities
    for (entity_ptr = p_forward_list_front(&entities); entity_ptr; entity_ptr = p_forward_list_next(entity_ptr))
    {
        dungeon_map_print_entity(entity_ptr->y, entity_ptr->x, entity_ptr->c);
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

entity_t *entity_player()
{
    return p_forward_list_front(&entities);
}

entity_t *entity_next(entity_t *entity_ptr)
{
    return p_forward_list_next(entity_ptr);
}

entity_t* entity_at(uint8_t y, uint8_t x)
{
    entity_t *entity_ptr;

    for (entity_ptr = p_forward_list_front(&entities); entity_ptr; entity_ptr = p_forward_list_next(entity_ptr))
    {
        if (entity_ptr->y == y && entity_ptr->x == x) {
            return entity_ptr;
        }
    }
    return NULL;
}

void entity_remove(entity_t *entity_ptr)
{
    p_forward_list_remove(&entities, entity_ptr);
}


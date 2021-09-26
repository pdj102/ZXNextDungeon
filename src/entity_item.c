/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Creature entity

 ***************************************************/
#include "entity_item.h"

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


item_t *entity_item_create(item_type_t i)
{
    // TODO check for NULL
    item_t *item_ptr = (item_t *) malloc(sizeof(item_t));

    switch (i)
    {
        case ring :
            item_ptr->tile     = TILE_RING;
            item_ptr->tile_attr = 0b00010000;
            item_ptr->blocking = 0;
            break;
    }

    return item_ptr;
}

void entity_item_draw_stat_block(item_t *item_ptr)
{
    printAt(21, 1);
    printf("ITEM:");
}

void entity_item_delete(item_t *item_ptr)
{
    free(item_ptr);
}
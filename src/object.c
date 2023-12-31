/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

**************************************************/

#include <arch/zxn.h>   // ZX Spectrum Next architecture specific functions
#include <stdio.h>

#include "object.h"
#include "globaldata.h"
#include "tilemap.h"
#include "dungeonmap.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

// helper pointer to the global object data array
object_t *const objects = &globaldata.objects[0];


/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions
 ***************************************************/

void object_init()
{
    objects[0].free = 0;
    objects[0].tilemap_tile.tile_attr = 0;
    objects[0].tilemap_tile.tile_id = 33;
    objects[0].x = 5;
    objects[0].y = 5;
    objects[0].blocking = 0;
}

void object_test()
{
    object_move(&objects[0], objects[0].x+1, objects[0].y);
}

void object_move(object_t *obj, uint8_t x, uint8_t y)
{
    if (!blocked(x, y))
    {
        obj->x = x;
        obj->y = y;
    }
}

void object_move_nochecks(object_t *obj, uint8_t x, uint8_t y)
{
    obj->x = x;
    obj->y = y;
}

uint8_t blocked(uint8_t dungeon_x, uint8_t dungeon_y)
{
    // check if dungeon map is blocked
    if (dungeonmap_tile_is_blocked(dungeon_x, dungeon_y))
    {
        return 1;
    }
    // to do check if blocked by any objects
    return 0;
}

void object_drawall()
{
    dungeonmap_draw_single_tile(objects[0].x, objects[0].y, &objects[0].tilemap_tile);
}


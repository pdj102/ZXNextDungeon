/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon map

 ***************************************************/
#include "dungeonmap.h"

#include <stdint.h>

#include "globaldata.h"
#include "tilemap.h"
#include "tile_defns.h"

/***************************************************
 * types
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

// helper pointer to the global dungeon map data 
static dungeonmap_t *const dungeonmap = &globaldata.dungeonmap;


/***************************************************
 * functions
 ***************************************************/

void dungeonmap_init( void )
{
    // Set view window
    dungeonmap_setwindow(0, 0, 24, 24);    
}

void dungeonmap_scroll(int8_t dx, int8_t dy )
{
    int8_t tmp_x;
    int8_t tmp_y;

    tmp_x = dungeonmap->window_x + dx;
    tmp_y = dungeonmap->window_y + dy;

    if (tmp_x < 0)  
    {
        dungeonmap->window_x = 0;
    }
    else if (tmp_x > DUNGEONMAP_WIDTH - dungeonmap->window_w)
    {
        dungeonmap->window_x = DUNGEONMAP_WIDTH - dungeonmap->window_w;
    }
    else
    {
        dungeonmap->window_x = tmp_x;
    }

    if (tmp_y < 0)  
    {
        dungeonmap->window_y = 0;
    }
    else if (tmp_y >= DUNGEONMAP_HEIGHT - dungeonmap->window_h)
    {
        dungeonmap->window_y = DUNGEONMAP_HEIGHT - dungeonmap->window_h;
    }
    else
    {
        dungeonmap->window_y = tmp_y;
    }       
}

void dungeonmap_setwindow(uint8_t y, uint8_t x, uint8_t h, uint8_t w)
{
    dungeonmap->window_y = y;
    dungeonmap->window_x = x;
    dungeonmap->window_h = h;
    dungeonmap->window_w = w;
}

void dungeonmap_draw( void )
{
    uint8_t dungeon_y = dungeonmap->window_y;
    uint8_t dungeon_x = dungeonmap->window_x;

    for (uint8_t screen_y = 0; screen_y < dungeonmap->window_h ; screen_y++) {
        for (uint8_t screen_x = 0; screen_x < dungeonmap->window_w; screen_x++) {
            tilemap_set_tile(screen_x, screen_y, &(dungeonmap->map[dungeon_x][dungeon_y].tilemap_tile));
            dungeon_x++;
        }
        dungeon_x = dungeonmap->window_x;
        dungeon_y++;
    }
}

void dungeonmap_draw_single_tile(uint8_t dungeon_x, uint8_t dungeon_y, const tilemap_tile_t *tile)
{
    uint8_t screen_x;
    uint8_t screen_y;

    // check tile is within viewable area
    if (    (dungeon_y >= dungeonmap->window_y && dungeon_y < dungeonmap->window_y + dungeonmap->window_h) && 
            (dungeon_x >= dungeonmap->window_x && dungeon_x < dungeonmap->window_x + dungeonmap->window_w) )
    {
        screen_x = dungeon_x - dungeonmap->window_x;
        screen_y = dungeon_y - dungeonmap->window_y;

        tilemap_set_tile(screen_x, screen_y, tile);
    }
}

uint8_t dungeonmap_tile_is_blocked(uint8_t dungeon_x, uint8_t dungeon_y) 
{
    // NB no test for dungeon map limits. Assumes the map has a blocking outer wall
    return dungeonmap->map[dungeon_x][dungeon_y].flags & (FLAG_BLOCKIKNG);
}
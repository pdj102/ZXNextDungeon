/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/
#include "dungeon_map.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <stdio.h> 

#include "tilemap.h"
#include "tilemap_tile_defns.h"
#include "entity.h"


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/

// window is the moveable area within the dungeon selected for display
uint8_t window_y = 0;
uint8_t window_x = 0;
uint8_t window_h = 24;
uint8_t window_w = 24;

/***************************************************
 * functions
 ***************************************************/

void dungeon_map_scroll(int8_t dx, int8_t dy )
{
    int8_t tmp_x;
    int8_t tmp_y;

    tmp_x = window_x + dx;
    tmp_y = window_y + dy;

    if (tmp_x < 0)  
    {
        window_x = 0;
    }
    else if (tmp_x > DUNGEON_MAP_WIDTH - window_w)
    {
        window_x = DUNGEON_MAP_WIDTH - window_w;
    }
    else
    {
        window_x = tmp_x;
    }

    if (tmp_y < 0)  
    {
        window_y = 0;
    }
    else if (tmp_y >= DUNGEON_MAP_HEIGHT - window_h)
    {
        window_y = DUNGEON_MAP_HEIGHT - window_h;
    }
    else
    {
        window_y = tmp_y;
    }       
}

void dungeon_map_init()
{
    // Map dungeon map data (bank 16) into ZX Spectrum 8k MMU slot 0
    ZXN_WRITE_REG(0x50, 16);    

    // dungeon_map is defined in dungeon_map_data.asm Bank 16 
    
}

void dungeon_map_draw()
{
    uint8_t dungeon_y = window_y;
    uint8_t dungeon_x = window_x;

    for (uint8_t screen_y = 0; screen_y < window_h ; screen_y++) {
        for (uint8_t screen_x = 0; screen_x < window_w; screen_x++) {
            tilemap_set_tile(screen_x, screen_y, &(dungeon_map[dungeon_x][dungeon_y].tilemap_tile));
            dungeon_x++;
        }
        dungeon_x = window_x;
        dungeon_y++;
    }
}

void dungeon_map_draw_tile(uint8_t dungeon_x, uint8_t dungeon_y)
{
    // check tile is within viewable area
    if ( (dungeon_y >= window_y && dungeon_y < window_y + window_h) && (dungeon_x >= window_x && dungeon_x < window_x+window_w) )
    {
        uint8_t screen_x = dungeon_x - window_x;
        uint8_t screen_y = dungeon_y - window_y;

        tilemap_set_tile(screen_x, screen_y, &(dungeon_map[dungeon_x][dungeon_y].tilemap_tile));
    }
}

void dungeon_map_draw_entity(uint8_t dungeon_x, uint8_t dungeon_y, const tilemap_tile_t *tile)
{
    // check tile is within viewable area
    if ( (dungeon_y >= window_y && dungeon_y < window_y + window_h) && (dungeon_x >= window_x && dungeon_x < window_x+window_w) )
    {
        dungeon_x = dungeon_x - window_x;
        dungeon_y = dungeon_y - window_y;

        tilemap_set_tile(dungeon_x, dungeon_y, tile);
    }
}

uint8_t dungeon_map_tile_passable(uint8_t dungeon_x, uint8_t dungeon_y) 
{
    switch( dungeon_map[dungeon_x][dungeon_y].tile ) 
    {
        case FLOOR: 
            return 1;
        default:
            return 0;
    }
}

uint8_t dungeon_map_is_blocked(uint8_t dungeon_x, uint8_t dungeon_y)
{
    // Is dungeon square blocked
    if (!dungeon_map_tile_passable(dungeon_x, dungeon_y)) {
        return 1;
    }

    if(entity_is_blocking_at(dungeon_x, dungeon_y)) {
        return 1;
    }
    return 0;
}   
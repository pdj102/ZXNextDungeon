/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/
#include "dungeon_map.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <stdio.h> 

#include "tilemap.h"
#include "tile_defns.h"
#include "entity.h"

#define DUNGEON_MAP_WIDTH   40
#define DUNGEON_MAP_HEIGHT  40

#define DUNGEON_MAP_TILE_FLOOR  0
#define DUNGEON_MAP_TILE_WALL   1


/***************************************************
 * types
 ***************************************************/
typedef struct
{
    uint8_t tile;
    uint8_t tile_attr;
    uint8_t t;
} dungeon_tile_t;

/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/
dungeon_tile_t dungeon_tiles[] =
{
    {TILE_FLOOR_1, 0b00000000, DUNGEON_MAP_TILE_FLOOR}, // DUNGEON_TILE_FLOOR
    {TILE_WALL_1, 0b00000000, DUNGEON_MAP_TILE_WALL},   // DUNGEON_TILE_WALL_1
    {TILE_CEILING, 0b00000000, DUNGEON_MAP_TILE_WALL}   // DUNGEON_TILE_CEILING
};

// dungeon map [x][y] [0][0] top left
dungeon_tile_t dungeon_map[DUNGEON_MAP_WIDTH][DUNGEON_MAP_HEIGHT];

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

void fill(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, uint8_t tile)
{
    // TODO check bounds
    for (uint8_t y = dungeon_y; y < dungeon_h+dungeon_y; y++ ) {
        for (uint8_t x = dungeon_x; x < dungeon_w+dungeon_x; x++)
            dungeon_map[x][y] = dungeon_tiles[tile];
    }
}

void create_room(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h)
{
    fill(dungeon_x, dungeon_y, dungeon_w, dungeon_h, DUNGEON_TILE_FLOOR_1);
    // fill(dungeon_x, dungeon_y-1 ,dungeon_w, 1, DUNGEON_TILE_WALL_1);
}

void dungeon_map_embelish_walls() {
    // scan from the bottom to top. 
    // Do not scan row 0 as some rules write to the row-1 
    // Do not scan column 0 as some rules write to column-1

    // add walls first
    for (uint8_t y = DUNGEON_MAP_HEIGHT; y > 0 ; y-- ) {
        for (uint8_t x = 1; x < DUNGEON_MAP_WIDTH - 1; x++)
        {
            // brick wall - if tile is a wall with floor in row below 
            if( (dungeon_map[x][y].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x][y+1].tile == DUNGEON_MAP_TILE_FLOOR) )
            {
                dungeon_map[x][y].tile = TILE_WALL_1;
            }
        }
    }

    // add blue lines
    for (uint8_t y = DUNGEON_MAP_HEIGHT - 1; y > 0 ; y-- ) {
        for (uint8_t x = 1; x < DUNGEON_MAP_WIDTH - 1; x++)
        {
            if ( dungeon_map[x][y].t == DUNGEON_MAP_TILE_WALL ) 
            {
                // bottom blue line - if tile is wall with floor in the row below 
                if ( dungeon_map[x][y+1].t == DUNGEON_MAP_TILE_FLOOR )
                {
                    dungeon_map[x][y].tile = TILE_3_3; //bottom blue line
                }
                // top blue line - if tile is wall with floor in row above 
                if ( dungeon_map[x][y-1].t == DUNGEON_MAP_TILE_FLOOR )
                {
                    dungeon_map[x][y].tile = TILE_3_1; //top blue line
                }
                // right blue line - if tile is wall with floor to the right 
                if (dungeon_map[x+1][y].t == DUNGEON_MAP_TILE_FLOOR ) 
                {
                    dungeon_map[x][y].tile = TILE_4_1; // right blue line
                }
                // left blue line - if tile is wall with floor to the left 
                if (dungeon_map[x-1][y].t == DUNGEON_MAP_TILE_FLOOR ) 
                {
                    dungeon_map[x][y].tile = TILE_4_3; // left blue line
                }
                // small top right corner - if tile is wall, tile above is wall, tile to right is wall and tile diagonally up/right is floor
                if ( (dungeon_map[x][y-1].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x+1][y].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x+1][y-1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                    dungeon_map[x][y].tile = TILE_6_1; // top right corner
                }
                // small top left corner - if tile is wall, tile above is wall, tile to left is wall and tile diagonally up/left is floor
                if ( (dungeon_map[x][y-1].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x-1][y].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x-1][y-1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                    dungeon_map[x][y].tile = TILE_6_3; // top left corner
                }
                // small bottom right corner - if tile is wall, tile below is wall, tile to right is wall and tile diagonally right/down is floor
                if ( (dungeon_map[x][y+1].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x+1][y].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x+1][y+1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                    dungeon_map[x][y].tile = TILE_5_0; // bottom right corner
                }
                // small bottom left corner - if tile is wall, tile below is wall, tile to left is wall and tile diagonally left/down is floor
                if ( (dungeon_map[x][y+1].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x-1][y].t == DUNGEON_MAP_TILE_WALL) && (dungeon_map[x-1][y+1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                   dungeon_map[x][y].tile = TILE_6_0; // bottom left corner
                }
                //  top right corner - if tile is wall, tile to left is floor, tile below is floor 
                if ( (dungeon_map[x-1][y].t == DUNGEON_MAP_TILE_FLOOR) && (dungeon_map[x][y+1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                   dungeon_map[x][y].tile = TILE_3_2; // top right  corner
                }
                //  top left corner - if tile is wall, tile to right is floor, tile below is floor 
                if ( (dungeon_map[x+1][y].t == DUNGEON_MAP_TILE_FLOOR) && (dungeon_map[x][y+1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                   dungeon_map[x][y].tile = TILE_4_2; // top left corner
                }
                //  bottom right corner - if tile is wall, tile to left is floor, tile above is floor 
                if ( (dungeon_map[x-1][y].t == DUNGEON_MAP_TILE_FLOOR) && (dungeon_map[x][y-1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                   dungeon_map[x][y].tile = TILE_3_0; // bottom right corner
                }
                //  bottom left corner - if tile is wall, tile to right is floor, tile above is floor 
                if ( (dungeon_map[x+1][y].t == DUNGEON_MAP_TILE_FLOOR) && (dungeon_map[x][y-1].t == DUNGEON_MAP_TILE_FLOOR) )
                {
                   dungeon_map[x][y].tile = TILE_4_0; // bottom left corner
                }                
            }
        }
    }   
}

void dungeon_map_init()
{
    fill(0, 0, DUNGEON_MAP_WIDTH, DUNGEON_MAP_HEIGHT, DUNGEON_TILE_CEILING);

    create_room(2, 2, 7, 5);
    create_room(10, 10, 4, 5);
    create_room(20, 2, 7, 5);
    create_room(3, 17, 5, 5);

    fill(9, 4, 3, 1, DUNGEON_TILE_FLOOR_1);
    fill(12, 4, 1, 6, DUNGEON_TILE_FLOOR_1);
    fill(12, 4, 8, 1, DUNGEON_TILE_FLOOR_1);
    fill(4, 7, 1, 10, DUNGEON_TILE_FLOOR_1);    

    dungeon_map_embelish_walls();
}

void dungeon_map_draw()
{
    // NB window_y + h and window_x + w must not go beyond map edge
    uint8_t dungeon_y = window_y;
    uint8_t dungeon_x = window_x;

    for (uint8_t screen_y = 0; screen_y < window_h ; screen_y++) {
        for (uint8_t screen_x = 0; screen_x < window_w; screen_x++) {
            tilemap_set_tile(screen_x, screen_y, dungeon_map[dungeon_x][dungeon_y].tile, dungeon_map[dungeon_x][dungeon_y].tile_attr);
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

        tilemap_set_tile(screen_x, screen_y, dungeon_map[dungeon_x][dungeon_y].tile, dungeon_map[dungeon_x][dungeon_y].tile_attr);
    }
}

void dungeon_map_draw_entity(uint8_t x, uint8_t y, uint8_t tile, uint8_t tile_attr)
{
    // check tile is within viewable area
    if ( (y >= window_y && y < window_y + window_h) && (x >= window_x && x < window_x+window_w) )
    {
        x = x - window_x;
        y = y - window_y;

        tilemap_set_tile(x, y, tile, tile_attr);
    }
}

uint8_t dungeon_map_tile_passable(uint8_t x, uint8_t y) 
{
    switch( dungeon_map[x][y].t ) 
    {
        case DUNGEON_MAP_TILE_FLOOR: 
            return 1;
        default:
            return 0;
    }
}

// returns 1 if dungeon tile is empty
uint8_t dungeon_map_is_square_empty(uint8_t x, uint8_t y)
{
    // Is dungeon square passable
    if (!dungeon_map_tile_passable(x, y)) {
        return 0;
    }

    if(!entity_passable(y, x)) {
        return 0;
    }
    return 1;
}
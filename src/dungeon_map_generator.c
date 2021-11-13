/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Dungeon map generator 

 ***************************************************/
#include "dungeon_map_generator.h"

// #include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>           
// #include <stdio.h> 

#include "dungeon_map.h"
// #include "tilemap.h"         
#include "tile_defns.h"         // tile definitions e.g. TILE_FLOOR_1


#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/
// Some handy dungeon tiles



dungeon_tile_t dungeon_tiles[] =
{
    {TILE_FLOOR_1, 0b00000000, DUNGEON_MAP_TILE_FLOOR}, // DUNGEON_TILE_FLOOR
    {TILE_WALL_1, 0b00000000, DUNGEON_MAP_TILE_WALL},   // DUNGEON_TILE_WALL_1
    {TILE_CEILING, 0b00000000, DUNGEON_MAP_TILE_WALL}   // DUNGEON_TILE_CEILING
};


/***************************************************
 * functions
 ***************************************************/

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
    // the top row within any created room will be become a brick wall when dungeon_map_embelish_walls() is called so need to make the room taller than requested
    fill(dungeon_x, dungeon_y-1, dungeon_w, dungeon_h+1, DUNGEON_MAP_TILE_FLOOR);
}

void dungeon_map_embelish_walls() {
    // scan from the bottom to top. 
    // Do not scan row 0 as some rules write to the row-1 
    // Do not scan column 0 as some rules write to column-1

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

    // add brick walls 
    for (uint8_t y = DUNGEON_MAP_HEIGHT; y > 0 ; y-- ) {
        for (uint8_t x = 1; x < DUNGEON_MAP_WIDTH - 1; x++)
        {
            // brick wall - if tile is floor with wall in row above
            if( (dungeon_map[x][y].t == DUNGEON_MAP_TILE_FLOOR) && (dungeon_map[x][y-1].t == DUNGEON_MAP_TILE_WALL) )
            {
                dungeon_map[x][y].tile = TILE_WALL_1;
                dungeon_map[x][y].t = DUNGEON_MAP_TILE_WALL;
            }
        }
    }
}

void dungeon_map_generate()
{
    // clear the dungeon map to all ceiling
    fill(0, 0, DUNGEON_MAP_WIDTH, DUNGEON_MAP_HEIGHT, DUNGEON_MAP_TILE_CEILING);

    // create rooms
    create_room(2, 3, 7, 5);
    create_room(10, 11, 4, 5);
    create_room(20, 3, 7, 5);
    create_room(3, 18, 5, 5);

    // create corridors
    create_room(9, 4, 3, 1);
    create_room(12, 5, 1, 6);
    create_room(12, 4, 8, 1);
    create_room(4, 7, 1, 10);

    dungeon_map_embelish_walls();
}
 
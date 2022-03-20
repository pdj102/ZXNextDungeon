/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Dungeon map generator 

    Banked code. Do not call directly       

 ***************************************************/
#include "dungeon_map_generator_bank.h"

#include <inttypes.h>           
#include <stdlib.h>             // rand()

#include "dungeon_map.h"
        
#include "tilemap_tile_defns.h"         // tile definitions e.g. TILE_FLOOR_1
#include "palette.h"


#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

void fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, uint8_t tile);
uint8_t is_empty_space_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h);
uint8_t create_room_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h);
void dungeon_map_embelish_walls_b();

/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/

extern const dungeon_tile_t tiles[];

/***************************************************
 * functions definitions
 ***************************************************/

void fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, uint8_t tile)
{
    // TODO check bounds
    for (uint8_t y = dungeon_y; y < dungeon_h+dungeon_y; y++ ) {
        for (uint8_t x = dungeon_x; x < dungeon_w+dungeon_x; x++)
            dungeon_map[x][y] = tiles[tile];
    }
}

uint8_t is_empty_space_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h)
{
    // TODO check bounds
    for (uint8_t y = dungeon_y; y < dungeon_h+dungeon_y; y++ ) {
        for (uint8_t x = dungeon_x; x < dungeon_w+dungeon_x; x++)
            if (dungeon_map[x][y].tile != WALL)
            {
                return 0;
            }
    }
    return 1;
}

uint8_t create_room_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h)
{
    fill_b(dungeon_x, dungeon_y, dungeon_w, dungeon_h, FLOOR);

    return 1;
}

void dungeon_map_embelish_walls_b()
{
    // scan from the bottom to top. 
    // Do not scan row 0 as some rules write to the row-1 
    // Do not scan column 0 as some rules write to column-1

    // add blue lines
    for (uint8_t y = DUNGEON_MAP_HEIGHT - 1; y > 0 ; y-- ) {
        for (uint8_t x = 1; x < DUNGEON_MAP_WIDTH - 1; x++)
        {
            if ( dungeon_map[x][y].tile == WALL ) 
            {
                // bottom blue line - if tile is wall with floor in the row below 
                if ( dungeon_map[x][y+1].tile == FLOOR )
                {
                    dungeon_map[x][y].tilemap_tile.tile_id = TILE_3_3; //bottom blue line
                }
                // top blue line - if tile is wall with floor in row above 
                if ( dungeon_map[x][y-1].tile == FLOOR )
                {
                    dungeon_map[x][y].tilemap_tile.tile_id = TILE_3_1; //top blue line
                }
                // right blue line - if tile is wall with floor to the right 
                if (dungeon_map[x+1][y].tile == FLOOR ) 
                {
                    dungeon_map[x][y].tilemap_tile.tile_id = TILE_4_1; // right blue line
                }
                // left blue line - if tile is wall with floor to the left 
                if (dungeon_map[x-1][y].tile == FLOOR ) 
                {
                    dungeon_map[x][y].tilemap_tile.tile_id = TILE_4_3; // left blue line
                }
                // small top right corner - if tile is wall, tile above is wall, tile to right is wall and tile diagonally up/right is floor
                if ( (dungeon_map[x][y-1].tile == WALL) && (dungeon_map[x+1][y].tile == WALL) && (dungeon_map[x+1][y-1].tile == FLOOR) )
                {
                    dungeon_map[x][y].tilemap_tile.tile_id = TILE_6_1; // top right corner
                }
                // small top left corner - if tile is wall, tile above is wall, tile to left is wall and tile diagonally up/left is floor
                if ( (dungeon_map[x][y-1].tile == WALL) && (dungeon_map[x-1][y].tile == WALL) && (dungeon_map[x-1][y-1].tile == FLOOR) )
                {
                    dungeon_map[x][y].tilemap_tile.tile_id = TILE_6_3; // top left corner
                }
                // small bottom right corner - if tile is wall, tile below is wall, tile to right is wall and tile diagonally right/down is floor
                if ( (dungeon_map[x][y+1].tile == WALL) && (dungeon_map[x+1][y].tile == WALL) && (dungeon_map[x+1][y+1].tile == FLOOR) )
                {
                    dungeon_map[x][y].tilemap_tile.tile_id = TILE_5_0; // bottom right corner
                }
                // small bottom left corner - if tile is wall, tile below is wall, tile to left is wall and tile diagonally left/down is floor
                if ( (dungeon_map[x][y+1].tile == WALL) && (dungeon_map[x-1][y].tile == WALL) && (dungeon_map[x-1][y+1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tilemap_tile.tile_id = TILE_6_0; // bottom left corner
                }
                //  top right corner - if tile is wall, tile to left is floor, tile below is floor 
                if ( (dungeon_map[x-1][y].tile == FLOOR) && (dungeon_map[x][y+1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tilemap_tile.tile_id = TILE_3_2; // top right  corner
                }
                //  top left corner - if tile is wall, tile to right is floor, tile below is floor 
                if ( (dungeon_map[x+1][y].tile == FLOOR) && (dungeon_map[x][y+1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tilemap_tile.tile_id = TILE_4_2; // top left corner
                }
                //  bottom right corner - if tile is wall, tile to left is floor, tile above is floor 
                if ( (dungeon_map[x-1][y].tile == FLOOR) && (dungeon_map[x][y-1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tilemap_tile.tile_id = TILE_3_0; // bottom right corner
                }
                //  bottom left corner - if tile is wall, tile to right is floor, tile above is floor 
                if ( (dungeon_map[x+1][y].tile == FLOOR) && (dungeon_map[x][y-1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tilemap_tile.tile_id = TILE_4_0; // bottom left corner
                }                
            }
        }
    }

    // add brick walls
    /* 
    for (uint8_t y = DUNGEON_MAP_HEIGHT - 1; y > 0 ; y-- ) {
        for (uint8_t x = 0; x < DUNGEON_MAP_WIDTH; x++)
        {
            // brick wall - if tile is floor with wall in row above
            if( (dungeon_map[x][y].tile == FLOOR) && (dungeon_map[x][y-1].tile == WALL) )
            {
                dungeon_map[x][y].tilemap_tile.tile_id = TILE_WALL_1;
                dungeon_map[x][y].tile = WALL;
            }
        }
    }
    */
}

// Assume dungeon map size is 40 * 40 tiles
// C
void dungeon_map_generate_b()
{
    
    uint8_t x, y;

    // clear the dungeon map to all ceiling
    fill_b(0, 0, DUNGEON_MAP_WIDTH, DUNGEON_MAP_HEIGHT, CEILING);

    // Create a 5 x 5 grid of rooms of size 8 x 8 tiles
    for (x = 0; x < 40; x+=8)
    {
        for (y = 0; y < 40; y+=8)
        {
            create_room_b(x+1, y+1, 6, 6);
        }
    }

    // add horizontal connecting corridors
    create_room_b(2, 4, 36, 1);
    create_room_b(2, 8+4, 36, 1);
    create_room_b(2, 16+4, 36, 1);
    create_room_b(2, 24+4, 36, 1);
    create_room_b(2, 32+4, 36, 1);

    // add vertical connecting corridors
    create_room_b(4, 2, 1, 36);
    create_room_b(8+4, 2, 1, 36);
    create_room_b(16+4, 2, 1, 36);
    create_room_b(24+4, 2, 1, 36);
    create_room_b(32+4, 2, 1, 36);

   dungeon_map_embelish_walls_b();

}
/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Dungeon map generator 

 ***************************************************/
#include "dungeon_map_generator.h"

#include <inttypes.h>           
#include <stdlib.h>             // rand()

#include "dungeon_map.h"
        
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

dungeon_tile_t tiles[] =
{
    {TILE_FLOOR_1, 0b00000000, FLOOR}, // tile_FLOOR
    {TILE_WALL_1, 0b00000000, WALL},   // tile_WALL_1
    {TILE_CEILING, 0b00000000, WALL}   // tile_CEILING
};


/***************************************************
 * functions
 ***************************************************/

void fill(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, uint8_t tile)
{
    // TODO check bounds
    for (uint8_t y = dungeon_y; y < dungeon_h+dungeon_y; y++ ) {
        for (uint8_t x = dungeon_x; x < dungeon_w+dungeon_x; x++)
            dungeon_map[x][y] = tiles[tile];
    }
}

uint8_t is_empty_space(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h)
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

uint8_t create_room(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h)
{
    fill(dungeon_x, dungeon_y, dungeon_w, dungeon_h, FLOOR);

    return 1;
}

void dungeon_map_embelish_walls() {
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
                    dungeon_map[x][y].tile_defn_graphic = TILE_3_3; //bottom blue line
                }
                // top blue line - if tile is wall with floor in row above 
                if ( dungeon_map[x][y-1].tile == FLOOR )
                {
                    dungeon_map[x][y].tile_defn_graphic = TILE_3_1; //top blue line
                }
                // right blue line - if tile is wall with floor to the right 
                if (dungeon_map[x+1][y].tile == FLOOR ) 
                {
                    dungeon_map[x][y].tile_defn_graphic = TILE_4_1; // right blue line
                }
                // left blue line - if tile is wall with floor to the left 
                if (dungeon_map[x-1][y].tile == FLOOR ) 
                {
                    dungeon_map[x][y].tile_defn_graphic = TILE_4_3; // left blue line
                }
                // small top right corner - if tile is wall, tile above is wall, tile to right is wall and tile diagonally up/right is floor
                if ( (dungeon_map[x][y-1].tile == WALL) && (dungeon_map[x+1][y].tile == WALL) && (dungeon_map[x+1][y-1].tile == FLOOR) )
                {
                    dungeon_map[x][y].tile_defn_graphic = TILE_6_1; // top right corner
                }
                // small top left corner - if tile is wall, tile above is wall, tile to left is wall and tile diagonally up/left is floor
                if ( (dungeon_map[x][y-1].tile == WALL) && (dungeon_map[x-1][y].tile == WALL) && (dungeon_map[x-1][y-1].tile == FLOOR) )
                {
                    dungeon_map[x][y].tile_defn_graphic = TILE_6_3; // top left corner
                }
                // small bottom right corner - if tile is wall, tile below is wall, tile to right is wall and tile diagonally right/down is floor
                if ( (dungeon_map[x][y+1].tile == WALL) && (dungeon_map[x+1][y].tile == WALL) && (dungeon_map[x+1][y+1].tile == FLOOR) )
                {
                    dungeon_map[x][y].tile_defn_graphic = TILE_5_0; // bottom right corner
                }
                // small bottom left corner - if tile is wall, tile below is wall, tile to left is wall and tile diagonally left/down is floor
                if ( (dungeon_map[x][y+1].tile == WALL) && (dungeon_map[x-1][y].tile == WALL) && (dungeon_map[x-1][y+1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tile_defn_graphic = TILE_6_0; // bottom left corner
                }
                //  top right corner - if tile is wall, tile to left is floor, tile below is floor 
                if ( (dungeon_map[x-1][y].tile == FLOOR) && (dungeon_map[x][y+1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tile_defn_graphic = TILE_3_2; // top right  corner
                }
                //  top left corner - if tile is wall, tile to right is floor, tile below is floor 
                if ( (dungeon_map[x+1][y].tile == FLOOR) && (dungeon_map[x][y+1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tile_defn_graphic = TILE_4_2; // top left corner
                }
                //  bottom right corner - if tile is wall, tile to left is floor, tile above is floor 
                if ( (dungeon_map[x-1][y].tile == FLOOR) && (dungeon_map[x][y-1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tile_defn_graphic = TILE_3_0; // bottom right corner
                }
                //  bottom left corner - if tile is wall, tile to right is floor, tile above is floor 
                if ( (dungeon_map[x+1][y].tile == FLOOR) && (dungeon_map[x][y-1].tile == FLOOR) )
                {
                   dungeon_map[x][y].tile_defn_graphic = TILE_4_0; // bottom left corner
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
                dungeon_map[x][y].tile_defn_graphic = TILE_WALL_1;
                dungeon_map[x][y].tile = WALL;
            }
        }
    }
    */
}

// Assume dungeon map size is 40 * 40 tiles
// C
void dungeon_map_generate()
{
    
    uint8_t x, y;

    /*
    uint8_t x2, y2, w2, h2;
    uint8_t max_rooms = 5;
    uint8_t max_tries = 30;
    uint8_t n = 0;
    uint8_t room = 0;
    */

    // clear the dungeon map to all ceiling
    fill(0, 0, DUNGEON_MAP_WIDTH, DUNGEON_MAP_HEIGHT, CEILING);

    for (x = 0; x < 40; x+=8)
    {
        for (y = 0; y < 40; y+=8)
        {
            create_room(x+1, y+1, 6, 6);
        }
    }
    create_room(7, 4, 2, 1);
/*
    while(n < max_tries || room < max_rooms)
    {
        w1 = 3 + (rand() % 10);
        h1 = 3 + (rand() % 10);
        x1 = 2 + (rand() % (DUNGEON_MAP_WIDTH - 3 - w1) );
        y1 = 2 + (rand() % (DUNGEON_MAP_HEIGHT - 3 - h1) );

        if (create_room(x1, y1, w1, h1))
        {
            room++;
        };

        n++;
    }    
*/

   dungeon_map_embelish_walls();

}

/*
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
    
    
    */

    /*
   for (x = 0; x < 40; x+= 10)
   {
       for (y = 0; y < 40; y+= 10)
       {
           // max width and height 8, min = 3
           w = 3 + (rand() % 6);
           h = 3 + (rand() % 6);

           // room-off set 
           room_x = rand() % (9 - w);
           room_y = rand() % (9 - h);

           
           create_room(x+room_x+1, y+room_y+1, w, h);
       }
   }
   */
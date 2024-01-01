/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon map generator

    Banked code. Do not call directly     

 ***************************************************/

#include <inttypes.h>           
#include <stdlib.h>             // rand()

#include "dungeonmap_generator_bank.h"

#include "dungeonmap.h"
        

#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * private types 
 ***************************************************/

/***************************************************
 * private function prototypes - static
 ***************************************************/

static void fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, dungeonmap_tile_type_e tile);

static void create_room_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h);


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/


/***************************************************
 * functions definitions
 ***************************************************/

static void fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, dungeonmap_tile_type_e tile)
{
    // TODO check bounds
    for (uint8_t y = dungeon_y; y < dungeon_h+dungeon_y; y++ ) {
        for (uint8_t x = dungeon_x; x < dungeon_w+dungeon_x; x++)
            dungeonmap_set_tile(x, y, tile);
    }
}


static void create_room_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h)
{
    fill_b(dungeon_x, dungeon_y, dungeon_w, dungeon_h, FLOOR);

}

// Assume dungeon map size is 40 * 40 tiles
// C
void dungeonmap_generate_b()
{
    
    uint8_t x, y;

    // clear the dungeon map to all ceiling
    fill_b(0, 0, DUNGEONMAP_WIDTH, DUNGEONMAP_HEIGHT, BRICKWALL);

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

}
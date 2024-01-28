/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon map generator

    Banked code. Do not call directly     

 ***************************************************/

#include <stdint.h>           
#include <stdlib.h>             // rand()

#include "dungeonmap_generator_bank.h"

#include "dungeonmap.h"
#include "globaldata.h"
        

#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * private types 
 ***************************************************/

/***************************************************
 * private function prototypes - static
 ***************************************************/

static void fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, dungeonmap_tile_type_e tile);

static void create_room_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h);

static void dungeonmap_set_tile_b(uint8_t dungeon_x, uint8_t dungeon_y, dungeonmap_tile_type_e tile_type);


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/


/***************************************************
 * functions definitions
 ***************************************************/

static void fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, dungeonmap_tile_type_e tile)
{
    uint8_t x2 = dungeon_w + dungeon_x;
    uint8_t y2 = dungeon_h + dungeon_y;

    // TODO check bounds
    for (uint8_t y = dungeon_y; y < y2; y++ ) {
        for (uint8_t x = dungeon_x; x < x2; x++)
            dungeonmap_set_tile_b(x, y, tile);
    }
}

static void create_room_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h)
{
    fill_b(dungeon_x, dungeon_y, dungeon_w, dungeon_h, FLOOR);
}

static void dungeonmap_set_tile_b(uint8_t dungeon_x, uint8_t dungeon_y, dungeonmap_tile_type_e tile_type)
{
    dungeonmap_tile_t *const m = &(globaldata.dungeonmap.map[dungeon_x][dungeon_y]);

    m->tile = tile_type;

    switch (tile_type)
    {
    case FLOOR:
        m->tilemap_tile.tile_attr = PALETTE_PURPLE;
        m->tilemap_tile.tile_id = 1;
        m->flags &= ~(FLAG_BLOCKIKNG);
        break;
    case BRICKWALL:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 4;
        m->flags |= FLAG_BLOCKIKNG;
        break;
    case SOLIDWALL:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 3;
        m->flags |= FLAG_BLOCKIKNG;
        break;
    default:
        m->tilemap_tile.tile_attr = 0;
        m->tilemap_tile.tile_id = 0;
        m->flags |= FLAG_BLOCKIKNG;
        break;
    }
}


void dungeonmap_generate_b( void )
{
    uint8_t x, y;

    // clear the dungeon map to all ceiling
    fill_b(0, 0, DUNGEONMAP_WIDTH, DUNGEONMAP_HEIGHT, BRICKWALL);

    // Assuming dungeon map size is 40 * 40 tiles
    // Create a 5 x 5 grid of rooms of size 8 x 8 tiles
    for (x = 0; x < DUNGEONMAP_WIDTH; x+=8)
    {
        for (y = 0; y < DUNGEONMAP_HEIGHT; y+=8)
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


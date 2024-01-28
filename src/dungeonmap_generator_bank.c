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

static void rect_fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, dungeonmap_tile_type_e tile);

static void rect_b(uint8_t x1, uint8_t y1, uint8_t w, uint8_t h, dungeonmap_tile_type_e tile);

static void line_horizontal_b(uint8_t x1, uint8_t y1, uint8_t x2, dungeonmap_tile_type_e tile);
static void line_vertical_b(uint8_t x1, uint8_t y1, uint8_t y2, dungeonmap_tile_type_e tile);
static void line_horizontal_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_tile_type_e tile_type);
static void line_vertical_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_tile_type_e tile_type);

static void create_room_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h);



static void dungeonmap_set_tile_b(uint8_t dungeon_x, uint8_t dungeon_y, dungeonmap_tile_type_e tile_type);


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/


/***************************************************
 * functions definitions
 ***************************************************/

static void rect_fill_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_tile_type_e tile)
{
    uint8_t x, y;

    // TODO check bounds
    for (y = y1; y <= y2; y++ ) {
        for (x = x1; x <= x2; x++)
            dungeonmap_set_tile_b(x, y, tile);
    }
}

static void rect_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_tile_type_e tile)
{
    uint8_t x, y;

    // TODO check bounds

    //top and bottom lines
    for (x = x1; x <= x2; x++ )
    {
            dungeonmap_set_tile_b(x, y1, tile);
            dungeonmap_set_tile_b(x, y2, tile);
    }
    // left and right lines
    
    for (y = y1; y <= y2; y++ )
    {
            dungeonmap_set_tile_b(x1, y, tile);
            dungeonmap_set_tile_b(x2, y, tile);
    }
    
}

static void line_horizontal_b(uint8_t x1, uint8_t y1, uint8_t x2, dungeonmap_tile_type_e tile)
{
    uint8_t x;

    if ( x1 > x2 ) 
    {
        x = x1;
        x1 = x2;
        x2 = x;
    }

    // TODO check bounds
    for (x = x1; x <= x2; x++ )
    {
            dungeonmap_set_tile_b(x, y1, tile);
    }

}

static void line_vertical_b(uint8_t x1, uint8_t y1, uint8_t y2, dungeonmap_tile_type_e tile)
{
    uint8_t y;

    if ( y1 > y2 ) 
    {
        y = y1;
        y1 = y2;
        y2 = y;
    }

    // TODO check bounds
    for (y = y1; y <= y2; y++ )
    {
            dungeonmap_set_tile_b(x1, y, tile);
    }

}




/**
 * @brief Create a line running horizontally (left to right or right to left) with an elbow
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2
 * @param tile_type 
 */
static void line_horizontal_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_tile_type_e tile_type)
{
    uint8_t x_mid;
    uint8_t ty, tx;

    // switch coords so corridor runs left to right
    if ( x1 > x2 ) 
    {
        tx = x1;    ty = x1;
        x1 = x2;    y1 = y2;    
        x2 = tx;    y2 = ty;
    }    

    x_mid = x1 + ((x2 - x1) / 2);
    // y_mid = y1 + ((y2 - y1) / 2);

    line_horizontal_b(x1, y1, x_mid, tile_type);
    line_vertical_b(x_mid, y1, y2, tile_type);
    line_horizontal_b(x_mid, y2, x2, tile_type);
}

/**
 * @brief Create a line running vertically (top to bottom or bottom to top) with an elbow
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 * @param tile_type
 */
static void line_vertical_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_tile_type_e tile_type)
{
    uint8_t y_mid;
    uint8_t ty, tx;

    // switch coords so corridor runs top to bottom
    if ( y1 > y2 ) 
    {
        tx = x1;    ty = x1;
        x1 = x2;    y1 = y2;    
        x2 = tx;    y2 = ty;
    }    

    // x_mid = x1 + ((x2 - x1) / 2);
    y_mid = y1 + ((y2 - y1) / 2);

    line_vertical_b(x1, y1, y_mid, tile_type);
    line_horizontal_b(x1, y_mid, x2, tile_type);
    line_vertical_b(x2, y_mid, y2, tile_type);    

}

static void create_horizontal_corridor_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    uint8_t x_mid;
    uint8_t ty, tx;

    // switch coords so corridor runs left to right
    if ( x1 > x2 ) 
    {
        tx = x1;    ty = x1;
        x1 = x2;    y1 = y2;    
        x2 = tx;    y2 = ty;
    }    
    
    x_mid = x1 + ((x2 - x1) / 2);
    
    // top wall
    line_horizontal_b(x1, y1 - 1, x_mid + 1, STONEWALL);
    line_vertical_b(x_mid + 1, y1 - 1, y2 - 1, STONEWALL);
    line_horizontal_b(x_mid + 1, y2 - 1, x2, STONEWALL);

    // corridor
    line_horizontal_b(x1, y1, x_mid, FLOOR);
    line_vertical_b(x_mid, y1, y2, FLOOR);
    line_horizontal_b(x_mid, y2, x2, FLOOR);

    // top wall
    line_horizontal_b(x1, y1 + 1, x_mid - 1, STONEWALL);
    line_vertical_b(x_mid - 1, y1 + 1, y2 + 1, STONEWALL);
    line_horizontal_b(x_mid - 1, y2 + 1, x2, STONEWALL);    
}

static void create_vertical_corridor_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    uint8_t y_mid;
    uint8_t ty, tx;

    // switch coords so corridor runs top to bottom
    if ( y1 > y2 ) 
    {
        tx = x1;    ty = x1;
        x1 = x2;    y1 = y2;    
        x2 = tx;    y2 = ty;
    }    

    // x_mid = x1 + ((x2 - x1) / 2);
    y_mid = y1 + ((y2 - y1) / 2);

    // left wall
    line_vertical_b(x1 - 1,     y1,     y_mid - 1,      STONEWALL);
    line_horizontal_b(x1 - 1,   y_mid - 1,  x2 - 1,     STONEWALL);
    line_vertical_b(x2 - 1,     y_mid - 1,  y2,         STONEWALL);    

    // floor wall
    line_vertical_b(x1,     y1,     y_mid,  FLOOR);
    line_horizontal_b(x1,   y_mid,  x2,     FLOOR);
    line_vertical_b(x2,     y_mid,  y2,     FLOOR);

    // right wall
    line_vertical_b(x1 + 1,     y1,         y_mid + 1,      STONEWALL);
    line_horizontal_b(x1 + 1,   y_mid + 1,  x2 + 1,     STONEWALL);
    line_vertical_b(x2 + 1,     y_mid + 1,  y2,         STONEWALL);            
}

static void create_room_b(uint8_t x1, uint8_t y1, uint8_t dungeon_w, uint8_t dungeon_h)
{
    uint8_t x2 = x1 + dungeon_w - 1;
    uint8_t y2 = y1 + dungeon_h - 1;

    rect_fill_b(x1, y1, x2, y2, FLOOR);
    // line_horizontal_b(x1, y1 + 1, x2, BRICKWALL);
    rect_b(x1, y1, x2, y2, STONEWALL);
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
    case ROCK:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 0;
        m->flags |= FLAG_BLOCKIKNG;
        break;        
    case BRICKWALL:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 4;
        m->flags |= FLAG_BLOCKIKNG;
        break;
    case BRICKWALL_END:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 3;
        m->flags |= FLAG_BLOCKIKNG;
        break;        
    case STONEWALL:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 3;
        m->flags |= FLAG_BLOCKIKNG;
        break;
    case STONEWALL_END:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 2;
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
    rect_fill_b(0, 0, DUNGEONMAP_WIDTH - 1, DUNGEONMAP_HEIGHT - 1, ROCK);

    // Assuming dungeon map size is 40 * 40 tiles
    // Create a 5 x 5 grid of rooms of size 8 x 8 tiles
    for (x = 0; x < DUNGEONMAP_WIDTH - 1; x+=10)
    {
        for (y = 0; y < DUNGEONMAP_HEIGHT - 1; y+=10)
        {
            create_room_b(x, y, 8, 8);
        }
    }

    create_horizontal_corridor_b(7, 3, 10, 4);
    create_horizontal_corridor_b(7, 13, 10, 13);
    create_vertical_corridor_b(4, 7, 1, 10);
    
    
    //    create_corridor_running_horizontal_b(6, 3, 8, 5);



/*
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
*/
}


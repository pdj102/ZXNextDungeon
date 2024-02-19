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

static void create_room_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);



static void dungeonmap_set_tile_b(uint8_t dungeon_x, uint8_t dungeon_y, dungeonmap_tile_type_e tile_type);


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/
struct room_s
{
    uint8_t x1;
    uint8_t x2;
    uint8_t y1;
    uint8_t y2;
    uint8_t split;
};

#define MAX_NODES 31

extern struct room_s room_nodes[];

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

static void create_room_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
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
        m->flags = DGN_FLAG_FLOOR;
        break;
    case ROCK:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 0;
        m->flags = DGN_FLAG_WALL;
        break;        
    case BRICKWALL:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 4;
        m->flags = DGN_FLAG_WALL;
        break;
    case BRICKWALL_END:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 3;
        m->flags = DGN_FLAG_WALL;
        break;        
    case STONEWALL:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 3;
        m->flags = DGN_FLAG_WALL;
        break;
    case STONEWALL_END:
        m->tilemap_tile.tile_attr = PALETTE_ORANGE;
        m->tilemap_tile.tile_id = 2;
        m->flags = DGN_FLAG_WALL;
        break;        
    default:
        m->tilemap_tile.tile_attr = 0;
        m->tilemap_tile.tile_id = 0;
        m->flags = DGN_FLAG_BLK_ALL;
        break;
    }
}

/**
 * @brief Create a rooms binary space partition object
 * 
 * @param max_r maximum number of nodes in the binary tree e.g. 1, 3, 7, 15, 31
 */
void create_rooms_binary_space_partition( uint8_t max_r )
{
    uint8_t half_w, half_h;
    uint8_t r = 1;
    uint8_t slice;

    // Set node 1 (root of the binary tree) to the size of the dungeon
    room_nodes[r].x1 = 0;
    room_nodes[r].y1 = 0;    
    room_nodes[r].x2 = DUNGEONMAP_WIDTH - 1;
    room_nodes[r].y2 = DUNGEONMAP_HEIGHT - 1;

    // 2*r is left child node and 2*r+1 is right child node
    while (r <= max_r)
    {
        // start by setting both child nodes to same size as parent node
        room_nodes[2*r].x1 = room_nodes[r].x1;
        room_nodes[2*r].y1 = room_nodes[r].y1;
        room_nodes[2*r].x2 = room_nodes[r].x2;
        room_nodes[2*r].y2 = room_nodes[r].y2;

        room_nodes[(2*r)+1].x1 = room_nodes[r].x1;
        room_nodes[(2*r)+1].y1 = room_nodes[r].y1;
        room_nodes[(2*r)+1].x2 = room_nodes[r].x2;
        room_nodes[(2*r)+1].y2 = room_nodes[r].y2;    

        // Slice horizontally or vertically to create child rooms
        slice = rand() % 2;
        if (slice == 1)
        {
            // slice horizontally  
            // calculate the half the height. NB add 1 to calculate height correctly, if y1 = 10 and y2 = 19 height is 20
            half_h = (room_nodes[r].y2 + 1 - room_nodes[r].y1) / 2;

            // make left child node top half
            room_nodes[2*r].y2 = room_nodes[r].y1 + half_h;

            // make right child node bottom half
            room_nodes[(2*r)+1].y1 = room_nodes[r].y1 + half_h;            
        }
        else
        {
            // slide vertically
            // calculate the half the width. NB add 1 to calculate width correctly, if x1 = 0 and x2 = 9 width is 10
            half_w = (room_nodes[r].x2 + 1 - room_nodes[r].x1) / 2;

            // make left child node left half 
            room_nodes[2*r].x2 = room_nodes[r].x1 + half_w;

            // make right child node right half
            room_nodes[(2*r)+1].x1 = room_nodes[r].x1 + half_w;                      

        }
        // remember which way we sliced
        room_nodes[r].split = slice;

        text_printf("r:%u, x1:%u y1:%u x2:%u y2:%u\n", (unsigned char)r, (unsigned char)room_nodes[r].x1, (unsigned char)room_nodes[r].y1, (unsigned char)room_nodes[r].x2, (unsigned char)room_nodes[r].y2);
        r++;
        
    }
}

void dungeonmap_generate_b( void )
{

    uint8_t r;

    // set the seed for the pseudo random number generator (for now generate a repeatable dungeon)
    srand(0);

    // clear the dungeon map to all rock
    rect_fill_b(0, 0, DUNGEONMAP_WIDTH - 1, DUNGEONMAP_HEIGHT - 1, ROCK);

    // populate the rooms list. 
    create_rooms_binary_space_partition( 15 );

    // add the rooms to the dungeon map
    // leaf nodes are second half of the array
    r = (MAX_NODES + 1) / 2;
    while (r <= MAX_NODES)
    {
        create_room_b(room_nodes[r].x1, room_nodes[r].y1, room_nodes[r].x2, room_nodes[r].y2);    
        r++;
    }

    // add corridors - children of layer 4 nodes 
    
    for (r = 8; r <=15; r++)
    {
        if (room_nodes[r].split == 1)
        {
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, FLOOR);
        }
    }

    // add corridors - children of layer 3 nodes 
    for (r = 4; r <=7; r++)
    {
        if (room_nodes[r].split == 1)
        {
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, FLOOR);
        }
    } 
    

    // add corridors - children of layer 2 nodes 
    for (r = 2; r <=3; r++)
    {
        if (room_nodes[r].split == 1)
        {
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, FLOOR);
        }
    }        

    // add corridors - children of layer 1 node
    for (r = 1; r <=1; r++)
    {
        if (room_nodes[r].split == 1)
        {
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, FLOOR);
        }
    }        


}



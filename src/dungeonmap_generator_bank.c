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
#include "dungeonmap_terrain.h"

#include "globaldata.h"
        

#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * private types 
 ***************************************************/

/***************************************************
 * private function prototypes - static
 ***************************************************/

static void rect_fill_b(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, dungeonmap_terrain_type_t terrain_id);

static void rect_b(uint8_t x1, uint8_t y1, uint8_t w, uint8_t h, dungeonmap_terrain_type_t terrain_id);

static void line_horizontal_b(uint8_t x1, uint8_t y1, uint8_t x2, dungeonmap_terrain_type_t terrain_id);
static void line_vertical_b(uint8_t x1, uint8_t y1, uint8_t y2, dungeonmap_terrain_type_t terrain_id);
static void line_horizontal_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_terrain_type_t terrain_id);
static void line_vertical_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_terrain_type_t terrain_id);

static void create_room_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

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

static void rect_fill_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_terrain_type_t terrain_id)
{
    uint8_t x, y;

    // TODO check bounds
    for (y = y1; y <= y2; y++ ) {
        for (x = x1; x <= x2; x++)
            dungeonmap_set_tile(x, y, terrain_id);
    }
}

static void rect_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_terrain_type_t terrain_id)
{
    uint8_t x, y;

    // TODO check bounds

    //top and bottom lines
    for (x = x1; x <= x2; x++ )
    {
            dungeonmap_set_tile(x, y1, terrain_id);
            dungeonmap_set_tile(x, y2, terrain_id);
    }
    // left and right lines
    
    for (y = y1; y <= y2; y++ )
    {
            dungeonmap_set_tile(x1, y, terrain_id);
            dungeonmap_set_tile(x2, y, terrain_id);
    }
    
}

static void line_horizontal_b(uint8_t x1, uint8_t y1, uint8_t x2, dungeonmap_terrain_type_t terrain_id)
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
            dungeonmap_set_tile(x, y1, terrain_id);
    }

}

static void line_vertical_b(uint8_t x1, uint8_t y1, uint8_t y2, dungeonmap_terrain_type_t terrain_id)
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
            dungeonmap_set_tile(x1, y, terrain_id);
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
static void line_horizontal_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_terrain_type_t terrain_id)
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

    line_horizontal_b(x1, y1, x_mid, terrain_id);
    line_vertical_b(x_mid, y1, y2, terrain_id);
    line_horizontal_b(x_mid, y2, x2, terrain_id);
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
static void line_vertical_right_angle_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, dungeonmap_terrain_type_t terrain_id)
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

    line_vertical_b(x1, y1, y_mid, terrain_id);
    line_horizontal_b(x1, y_mid, x2, terrain_id);
    line_vertical_b(x2, y_mid, y2, terrain_id);    

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
    line_horizontal_b(x1, y1 - 1, x_mid + 1, TERRAIN_STONEWALL);
    line_vertical_b(x_mid + 1, y1 - 1, y2 - 1, TERRAIN_STONEWALL);
    line_horizontal_b(x_mid + 1, y2 - 1, x2, TERRAIN_STONEWALL);

    // corridor
    line_horizontal_b(x1, y1, x_mid, TERRAIN_FLOOR);
    line_vertical_b(x_mid, y1, y2, TERRAIN_FLOOR);
    line_horizontal_b(x_mid, y2, x2, TERRAIN_FLOOR);

    // top wall
    line_horizontal_b(x1, y1 + 1, x_mid - 1, TERRAIN_STONEWALL);
    line_vertical_b(x_mid - 1, y1 + 1, y2 + 1, TERRAIN_STONEWALL);
    line_horizontal_b(x_mid - 1, y2 + 1, x2, TERRAIN_STONEWALL);    
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
    line_vertical_b(x1 - 1,     y1,     y_mid - 1,      TERRAIN_STONEWALL);
    line_horizontal_b(x1 - 1,   y_mid - 1,  x2 - 1,     TERRAIN_STONEWALL);
    line_vertical_b(x2 - 1,     y_mid - 1,  y2,         TERRAIN_STONEWALL);    

    // floor wall
    line_vertical_b(x1,     y1,     y_mid,  TERRAIN_FLOOR);
    line_horizontal_b(x1,   y_mid,  x2,     TERRAIN_FLOOR);
    line_vertical_b(x2,     y_mid,  y2,     TERRAIN_FLOOR);

    // right wall
    line_vertical_b(x1 + 1,     y1,         y_mid + 1,      TERRAIN_STONEWALL);
    line_horizontal_b(x1 + 1,   y_mid + 1,  x2 + 1,     TERRAIN_STONEWALL);
    line_vertical_b(x2 + 1,     y_mid + 1,  y2,         TERRAIN_STONEWALL);            
}

static void create_room_b(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    rect_fill_b(x1, y1, x2, y2, TERRAIN_FLOOR);
    // line_horizontal_b(x1, y1 + 1, x2, BRICKWALL);
    rect_b(x1, y1, x2, y2, TERRAIN_STONEWALL);
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
    rect_fill_b(0, 0, DUNGEONMAP_WIDTH - 1, DUNGEONMAP_HEIGHT - 1, TERRAIN_ROCK);

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
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, TERRAIN_FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, TERRAIN_FLOOR);
        }
    }

    // add corridors - children of layer 3 nodes 
    for (r = 4; r <=7; r++)
    {
        if (room_nodes[r].split == 1)
        {
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, TERRAIN_FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, TERRAIN_FLOOR);
        }
    } 
    

    // add corridors - children of layer 2 nodes 
    for (r = 2; r <=3; r++)
    {
        if (room_nodes[r].split == 1)
        {
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, TERRAIN_FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, TERRAIN_FLOOR);
        }
    }        

    // add corridors - children of layer 1 node
    for (r = 1; r <=1; r++)
    {
        if (room_nodes[r].split == 1)
        {
            
            line_vertical_b(room_nodes[2*r].x1 + 2, room_nodes[2*r].y2, room_nodes[(2*r)+1].y1, TERRAIN_FLOOR);            
        }
        else
        {
            line_horizontal_b(room_nodes[2*r].x2, room_nodes[2*r].y1 + 2, room_nodes[(2*r)+1].x1, TERRAIN_FLOOR);
        }
    }        


}



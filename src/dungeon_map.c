/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/
#include "dungeon_map.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <stdio.h> 


#define printAt(row, col)    printf("\x16%c%c", (col)+1, (row)+1)

#define DUNGEON_MAP_WIDTH   40
#define DUNGEON_MAP_HEIGHT  40

/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/


// dungeon map [y][x] [0][0] top left
char dungeon_map[DUNGEON_MAP_HEIGHT][DUNGEON_MAP_WIDTH];

uint8_t ys = 0;
uint8_t xs = 0;
uint8_t h = 20;
uint8_t w = 20;

/***************************************************
 * functions
 ***************************************************/

void dungeon_map_scroll(int8_t dy, int8_t dx )
{
    // TO DO check bounds
    ys += dy;
    xs += dx;
}

void fill(uint8_t ys, uint8_t xs, uint8_t h, uint8_t w, char c)
{
    // TO DO check bounds
    for (uint8_t y = ys; y < h+ys; y++ ) {
        for (uint8_t x = xs; x < w+xs; x++)
            dungeon_map[y][x] = c;
    }
}

void dungeon_map_init()
{
    fill(0, 0, DUNGEON_MAP_HEIGHT, DUNGEON_MAP_WIDTH, '#');
    fill(2, 2, 5, 7, '.');
    fill(10, 10, 5, 4, '.');

    fill(4, 9, 1, 3, '.');
    fill(4, 12, 6, 1, '.');    
}

void dungeon_map_print()
{
    // NB ys + h and xs + w must not go beyond map edge
    uint8_t dy = ys;
    uint8_t dx = xs;

    for (uint8_t y = 0; y < h ; y++) {
        for (uint8_t x = 0; x < w; x++) {
            printAt(y,x);
            printf("%c", dungeon_map[dy][dx]);
            dx++;
        }
        dx = xs;
        dy++;
    }
}

void dungeon_map_print_tile(uint8_t dy, uint8_t dx)
{
    // check tile is within viewable area
    if ( (dy >= ys && dy < ys + h) && (dx >= xs && dx < xs+w) )
    {
        uint8_t x = dx - xs;
        uint8_t y = dy - ys;

        printAt(y,x);
        printf("%c", dungeon_map[dy][dx]);
    }
}

void dungeon_map_print_entity(uint8_t y, uint8_t x, char c)
{
    // check tile is within viewable area
    if ( (y >= ys && y < ys + h) && (x >= xs && x < xs+w) )
    {
        x = x - xs;
        y = y - ys;

        printAt(y,x);
        printf("%c", c);
    }
}

uint8_t dungeon_map_passable(uint8_t y, uint8_t x) 
{
    if (dungeon_map[y][x] == '#') {
        return 0;
    }
    return 1;
}

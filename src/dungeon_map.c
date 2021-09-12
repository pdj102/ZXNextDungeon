/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/
#include "dungeon_map.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <stdio.h> 


#define printAt(row, col)    printf("\x16%c%c", (col)+1, (row)+1)


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/

/* char dungeon_map[10][11] = // [y][x] [0][0] top left
{
    "##########",
    "#........#",
    "#........#",
    "#........#",
    "#........#",
    "#........#",
    "#........#",
    "#........#",
    "#........#",
    "##########"    
}; */

char dungeon_map[20][21];

/***************************************************
 * functions
 ***************************************************/

void fill(uint8_t ys, uint8_t xs, uint8_t h, uint8_t w, char c)
{
    for (uint8_t y = ys; y < h+ys; y++ ) {
        for (uint8_t x = xs; x < w+xs; x++)
            dungeon_map[y][x] = c;
    }
}

void dungeon_map_init()
{
    fill(0, 0, 20, 20, '#');
    fill(2, 2, 5, 7, '.');
    fill(10, 10, 5, 4, '.');

    fill(4, 9, 1, 3, '.');
    fill(4, 12, 6, 1, '.');    
}
void dungeon_map_print()
{
    for (uint8_t y = 0; y<20; y++) {
        for (uint8_t x = 0; x<20; x++) {
            printAt(y,x);
            printf("%c", dungeon_map[y][x]);
        }
    }
}

void dungeon_map_print_tile(uint8_t y, uint8_t x)
{
    printAt(y,x);
    printf("%c", dungeon_map[y][x]);
}

uint8_t dungeon_map_passable(uint8_t y, uint8_t x) 
{
    if (dungeon_map[y][x] == '#') {
        return 0;
    }
    return 1;
}

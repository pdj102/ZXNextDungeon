/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tileset text 

 ***************************************************/

#ifndef TEXT_H 
    #define TEXT_H 

#include <inttypes.h>

/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations - extern
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Print text on tilemap. No bounds checking
 * 
 * @param x  x position 0 - 39
 * @param y  y position 0 - 31
 * @param text[] text to print
 * @return void
 */
void text_print(uint8_t x, uint8_t y, char text[]);


#endif
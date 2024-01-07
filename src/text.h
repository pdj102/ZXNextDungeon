/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Functions to print to ZX Next tilemap

 ***************************************************/

#ifndef TEXT_H 
    #define TEXT_H 

#include <inttypes.h>

#include "tilemap.h"

/***************************************************
 * public types
 ***************************************************/

typedef struct 
{
    uint8_t                 x;
    uint8_t                 y;
    uint8_t                 w;
    uint8_t                 h;
    uint8_t                 c_x;
    uint8_t                 c_y;
    tilemap_tile_t          tile;  
} text_window_t;

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief Initialise text system. Must be called before using text
 * 
 * @return void
 */
void text_init();

/**
 * @brief Print text string on tilemap at cursor position
 * 
 * @param text[] text to print
 * @return void
 */
void text_print_string(const char text[]);

/**
 * @brief Print text string on tilemap at x, y
 * 
 * No check is made to confirm if x and y is within text window
 * 
 * @param x  x 
 * @param y  y 
 * @param text[] text to print
 * @return void
 */
void text_print_string_at(uint8_t x, uint8_t y, const char text[]);


/**
 * @brief Print uint8 on tilemap.
 * 
 * @param i  unit8 to print
 * @return void
 */
void text_print_uint8(uint8_t i);


/**
 * @brief Print int8 on tilemap.
 * 
 * @param i  int8 to print
 * @return void
 */
void text_print_int8(int8_t i);

/**
 * @brief Print uint16 on tilemap.
 * 
 * @param i  unit16 to print
 * @return void
 */
void text_print_uint16(uint16_t i);


/**
 * @brief Print int16 on tilemap.
 * 
 * @param i  int16 to print
 * @return void
 */
void text_print_int16(int16_t i);



#endif
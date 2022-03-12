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
 * @brief Print text string on tilemap. No bounds checking
 * 
 * @param x  x position 0 - 39
 * @param y  y position 0 - 31
 * @param text[] text to print
 * @return void
 */
void text_print_string(uint8_t x, uint8_t y, const char text[]);

/**
 * @brief Print char on tilemap.
 * 
 * @param x  x position 0 - 39
 * @param y  y position 0 - 31
 * @param text char to print
 * @return void
 */
void text_print_char(uint8_t x, uint8_t y, char text);

/**
 * @brief Print uint8 on tilemap.
 * 
 * @param x  x position 0 - 39
 * @param y  y position 0 - 31
 * @param i  unit8 to print
 * @return void
 */
void text_print_uint8(uint8_t x, uint8_t y, uint8_t i);


/**
 * @brief Print int8 on tilemap.
 * 
 * @param x  x position 0 - 39
 * @param y  y position 0 - 31
 * @param i  nit8 to print
 * @return void
 */
void text_print_int8(uint8_t x, uint8_t y, int8_t i);

/**
 * @brief Print uint16 on tilemap.
 * 
 * @param x  x position 0 - 39
 * @param y  y position 0 - 31
 * @param i  unit8 to print
 * @return void
 */
void text_print_uint16(uint8_t x, uint8_t y, uint16_t i);


/**
 * @brief Print int16 on tilemap.
 * 
 * @param x  x position 0 - 39
 * @param y  y position 0 - 31
 * @param i  nit8 to print
 * @return void
 */
void text_print_int16(uint8_t x, uint8_t y, int16_t i);

#endif
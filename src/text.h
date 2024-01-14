/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Functions to print to ZX Next tilemap

 ***************************************************/

#ifndef TEXT_H 
    #define TEXT_H 

#include <stdint.h>

#include "tilemap.h"

#define MAX_WINDOW 3

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

extern char object_base_data[];

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief Initialise text system. Must be called before using text
 * 
 * Initalises and selects window 0
 * 
 * @return void
 */
void text_init( void );

/**
 * @brief Initialise a text window. Sets window size, cursor position, default text tile attribute
 * 
 * @param window    window index
 * @param x         window top x position
 * @param y         window top y position
 * @param w         window w position
 * @param h         window h position
 * 
 * @return void
 */
void text_init_window(uint8_t window, uint8_t x, uint8_t y, uint8_t w, uint8_t h);

/**
 * @brief Select current active window
 * 
 * @param uint8_t    window index
 * 
 * @return void
 */
void text_select_win( uint8_t window);

/**
 * @brief Clear current window and return cursor to top left
 * 
 * @return void
 */
void text_cls( void );

/**
 * @brief Print a char on tilemap at cursor position in current window
 * 
 * Increments cursor position. 
 * 
 * If the end of the line is reached move to next line 
 * If bottom of window is reached scroll the text up
 * 
 * @param c     Char to print
 * @return void
 */
void text_putc(char c);

/**
 * @brief Print a formatted string on tilemap at cursor position in current window
 * 
 * Format tags
 *  %t   token string ID (uint_8t)
 *  %u   uint8_t
 *  %d   int8_t
 * 
 * @param *text text to print
 * @param ...   parameters   
 * 
 * @return void
 */
void text_printf(const char *text, ...);

/**
 * @brief Print text string to tilemap at cursor position in current window
 * 
 * Uses text_putc( void ) so will wrap with window 
 * 
 * @param text[] text to print
 * @return void
 */
void text_print_string(const char text[]);

/**
 * @brief Print text string on tilemap at x, y
 * 
 * No check is made to confirm if x and y is within text window in current window
 * 
 * @param x  x 
 * @param y  y 
 * @param text[] text to print
 * @return void
 */
void text_print_string_at(uint8_t x, uint8_t y, const char text[]);


/**
 * @brief Print uint8 to tilemap at cursor position in current window
 * 
 * @param i  unit8 to print
 * @return void
 */
void text_print_uint8(uint8_t i);


/**
 * @brief Print int8 to tilemap at cursor position in current window
 * 
 * @param i  int8 to print
 * @return void
 */
void text_print_int8(int8_t i);

/**
 * @brief Print uint16 to tilemap at cursor position in current window
 * 
 * @param i  unit16 to print
 * @return void
 */
void text_print_uint16(uint16_t i);


/**
 * @brief Print int16 to tilemap at cursor position in current window
 * 
 * @param i  int16 to print
 * @return void
 */
void text_print_int16(int16_t i);



#endif
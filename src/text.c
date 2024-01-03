/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Functions to print to ZX Next tilemap

 ***************************************************/
#include "text.h"

#include <string.h>     /* strlen() */
#include <stdlib.h>     /* itoa() */
#include <inttypes.h>

#include "globaldata.h"
#include "tilemap.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

// helper pointer to the global text window struct 
static text_window_t *const text_win = &globaldata.text_window;

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions definitions
 ***************************************************/

void text_init()
{
    text_win->x = 0;
    text_win->y = 0;
    text_win->w = 40;
    text_win->y = 32;
    text_win->c_x = 0;
    text_win->c_y = 0;
    text_win->tile.tile_attr = PALETTE_0;
}

void text_print_string(const char text[])
{
    uint8_t l = strlen(text);

    for (uint8_t i = 0; i < l; i++)
    {
        text_win->tile.tile_id = text[i];
        tilemap_set_tile(text_win->c_x, text_win->c_y, &text_win->tile );
        text_win->c_x++;
        if (text_win->c_x >= text_win->x + text_win->w)
        {
            text_win->c_x = text_win->x;
            text_win->c_y++;
            if (text_win->c_y >= text_win->y + text_win->h)
            {
                // TODO scroll
                text_win->c_y--;
            }
        }
    }
}

void text_print_string_at(uint8_t x, uint8_t y, const char text[])
{
    text_win->c_x = x;
    text_win->c_y = y;
    text_print_string(text);
}

void text_print_uint8(uint8_t x, uint8_t y, uint8_t i)
{
    char s[] = "   ";     // string buffer for converting numbers to strings e.g. 255
    
    itoa(i, s, 10);
    text_print_string_at(x, y, s);
}

void text_print_int8(uint8_t x, uint8_t y, int8_t i)
{
    char s[] = "    ";     // string buffer for converting numbers to strings e.g. -128
    
    itoa(i, s, 10);
    text_print_string_at(x, y, s);
}

void text_print_uint16(uint8_t x, uint8_t y, uint16_t i)
{
    char s[] = "65535";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string_at(x, y, s);
}

void text_print_int16(uint8_t x, uint8_t y, int16_t i)
{
    char s[] = "-32768";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string_at(x, y, s);
}

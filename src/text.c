/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Functions to print to ZX Next tilemap

 ***************************************************/
#include "text.h"

#include <string.h>     /* strlen() */
#include <stdlib.h>     /* itoa() */
#include <inttypes.h>
#include <stdarg.h>     /* variadic functions */

#include "globaldata.h"
#include "tilemap.h"
#include "text_token.h"

/***************************************************
 * private types
 ***************************************************/
// helper pointer to the global text window struct 
static text_window_t *const text_win = &globaldata.text_window;


/***************************************************
 * private function prototypes
 ***************************************************/

void text_scroll_up();

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions definitions
 ***************************************************/

void text_init()
{
    text_win->x = 0;
    text_win->y = 24;
    text_win->w = 40;
    text_win->h = 8;
    text_win->c_x = text_win->x;
    text_win->c_y = text_win->y;
    text_win->tile.tile_attr = PALETTE_0;
}

void text_putc(char c)
{
    // reached end of line?
    if (text_win->c_x >= text_win->x + text_win->w)
    {
        text_win->c_x = text_win->x;
        text_win->c_y++;
    }

    // gone pass bottom of window?
    if (text_win->c_y >= text_win->y + text_win->h)
    {
            text_scroll_up();
            text_win->c_y--;            
    }

    switch (c)
    {
    case 10:
        text_win->c_x = text_win->x;
        text_win->c_y++;
        break;
    default:
        text_win->tile.tile_id = c;
        tilemap_set_tile(text_win->c_x, text_win->c_y, &text_win->tile);
        text_win->c_x++;
    }
}

void text_printf(const char text[], ...)
{
    va_list ptr;
     va_start(ptr, text);

    uint8_t l = strlen(text);

    for (uint8_t i = 0; i < l; i++)
    {
        if (text[i] != '%')
        {
            text_putc(text[i]);
            continue;
        }

        i++;

        switch(text[i])
        {
            case 't':   // token string
            text_token_print( (uint8_t) va_arg(ptr, uint8_t) );
            break;

            case 'u':   // uint8_t
            text_print_uint8( (uint8_t) va_arg(ptr, uint8_t) );
            break;

            case 'd':   // int8_t
            text_print_int8( (int8_t) va_arg(ptr, int8_t) );
            break;

            default:
            text_putc('*');
        }
    }
    va_end(ptr);
}

void text_print_string(const char text[])
{
    uint8_t l = strlen(text);

    for (uint8_t i = 0; i < l; i++)
    {
            text_putc(text[i]);
    }
}

void text_scroll_up()
{
    uint8_t x, y;
    tilemap_tile_t blank;

    blank.tile_attr = 0;
    blank.tile_id = 32;

    for (y = text_win->y; y < text_win->y + text_win->h; y++)
    {
        for (x = text_win->x; x < text_win->x + text_win->w; x++)
        {
            tilemap_copy_tile(x, y + 1 , x, y );
        }
    }
    
    y = text_win->y + text_win->h - 1;
    for (x = text_win->x; x < text_win->x + text_win->w; x++)
    {
        tilemap_set_tile(x, y, &blank );
    }
}

void text_print_string_at(uint8_t x, uint8_t y, const char text[])
{
    text_win->c_x = x;
    text_win->c_y = y;
    text_print_string(text);
}

void text_print_uint8(uint8_t i)
{
    char s[] = "   ";     // string buffer for converting numbers to strings e.g. 255
    
    itoa(i, s, 10);
    text_print_string(s);
}

void text_print_int8(int8_t i)
{
    char s[] = "    ";     // string buffer for converting numbers to strings e.g. -128
    
    itoa(i, s, 10);
    text_print_string(s);
}

void text_print_uint16(uint16_t i)
{
    char s[] = "65535";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string(s);
}

void text_print_int16(int16_t i)
{
    char s[] = "-32768";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string(s);
}

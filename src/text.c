/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Functions to print to ZX Next tilemap

 ***************************************************/
#include "text.h"

#include <string.h>     /* strlen() */
#include <stdlib.h>     /* itoa() */
#include <stdint.h>
#include <stdio.h>

#include <stdarg.h>     /* variadic functions */

#include "globaldata.h"
#include "tilemap.h"
#include "text_token.h"

/***************************************************
 * private types
 ***************************************************/
// helper pointer to the global text window struct 
static text_window_t * text_win = &globaldata.text_windows[0];

tilemap_tile_t blank;

/***************************************************
 * private function prototypes
 ***************************************************/

void text_scroll_up( void );

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions definitions
 ***************************************************/

void text_init( void )
{
    text_init_window(0, 0, 0, 40, 32);  // tilmap is 40 x 32
}

void text_init_window(uint8_t window, uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
    text_select_win(window);

    text_win->x = x;
    text_win->y = y;
    text_win->w = w;
    text_win->h = h;
    text_win->c_x = text_win->x;
    text_win->c_y = text_win->y;
    text_win->tile.tile_attr = PALETTE_0;    
}

void text_select_win( uint8_t window)
{
    text_win = &globaldata.text_windows[window];    
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

void text_printf(const char *text, ...)
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

void text_cls( void )
{
    uint8_t x = 0;
    uint8_t y = 0;

    uint8_t x2 = text_win->x + text_win->w;
    uint8_t y2 = text_win->y + text_win->h;

    blank.tile_attr = text_win->tile.tile_attr;
    blank.tile_id = 32;

    tilemap_tile_t *p = &blank;

    for (y = text_win->y; y < y2 ; y++)
    {
        
        for (x = text_win->x; x < x2 ; x++)
        {
            tilemap_set_tile(x, y, p );
        }
    }    

}

void text_scroll_up( void )
{
    uint8_t x = 0;
    uint8_t y = 0;

    uint8_t x2 = text_win->x + text_win->w;
    uint8_t y2 = text_win->y + text_win->h;

    blank.tile_attr = text_win->tile.tile_attr;
    blank.tile_id = 32;

    tilemap_tile_t *p = &blank;

    for (y = text_win->y + 1; y < y2 ; y++)
    {
        
        for (x = text_win->x; x < x2 ; x++)
        {
            tilemap_copy_tile(x, y, x, y - 1);
        }
    }
    
    y = text_win->y + text_win->h - 1;
    for (x = text_win->x; x < x2 ; x++)
    {
        tilemap_set_tile(x, y, p );
    }
}

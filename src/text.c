/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tileset text 

 ***************************************************/
#include "text.h"

#include <string.h>     /* strlen() */
#include <stdlib.h>     /* itoa() */

#include "tilemap.h"
#include "palette.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

// offset into tileset for ASCII characters
uint8_t tile_map_offset = 36;  //36

/***************************************************
 * functions definitions
 ***************************************************/


void text_print_string(uint8_t x, uint8_t y, const char text[])
{
    uint8_t l = strlen(text);

    for (uint8_t i = 0; i < l; i++)
    {
        text_print_char(x, y, text[i]);
        x++;
    }
}

void text_print_char(uint8_t x, uint8_t y, char text)
{
    tilemap_set_tile2(x, y, text + tile_map_offset, NO_MIRROR | NO_ROTATE | PALETTE_DUNGEON );
}

void text_print_uint8(uint8_t x, uint8_t y, uint8_t i)
{
    char s[] = "255";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string(x, y, s);
}

void text_print_int8(uint8_t x, uint8_t y, int8_t i)
{
    char s[] = "-128";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string(x, y, s);
}

void text_print_uint16(uint8_t x, uint8_t y, uint16_t i)
{
    char s[] = "65535";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string(x, y, s);
}

void text_print_int16(uint8_t x, uint8_t y, int16_t i)
{
    char s[] = "-32768";     // string buffer for converting numbers to strings
    
    itoa(i, s, 10);
    text_print_string(x, y, s);
}
 
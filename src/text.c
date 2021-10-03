/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tileset text 

 ***************************************************/
#include "text.h"

#include "string.h"

#include "tilemap.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/

// offset into tileset for ASCII characters
uint8_t tile_map_offset = 36;

/***************************************************
 * functions definitions
 ***************************************************/


void text_print(uint8_t x, uint8_t y, char text[])
{
    uint8_t l = strlen(text);

    for (uint8_t i = 0; i < l; i++)
    {
        tilemap_set_tile(x, y, text[i] + tile_map_offset, 0);
        x++;
    }
}

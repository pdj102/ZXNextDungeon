/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tileset text 

 ***************************************************/
#include "text.h"

#include <string.h>     /* strlen() */

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


void text_print(uint8_t x, uint8_t y, char text[])
{
    uint8_t l = strlen(text);

    for (uint8_t i = 0; i < l; i++)
    {
        tilemap_set_tile2(x, y, text[i] + tile_map_offset, NO_MIRROR | NO_ROTATE | PALETTE_DUNGEON );
        x++;
    }
}
 
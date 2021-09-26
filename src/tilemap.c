/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manages ZX Next tilemap

 ***************************************************/
#include "tilemap.h"

#include <arch/zxn.h>

#include "palette.h"
#include "tile_defns.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/
uint8_t volatile * const tilemap_base_p = (uint8_t *) 0x6000;


/***************************************************
 * functions definitions
 ***************************************************/

void tilemap_init()
{
    // initialise palette
    palette_init();

    // initialise tile definitions 
    tile_defns_init();

    // 0x6E - Tilemap base address
    // sets the tilemap base address offset within bank 5 (bank 5 is at 0x4000)
    // The ULA screen is located 0x4000 - 0x5FFF (7 KiB) so setting tilemap base address to 0x6000 avoids it
    // If ULA screen is not required it could be turned off and the tilemap written at 0x4000
    // 0x6E is set with the MSB which represents an n x 256 byte offset. (0x6000 - 0x4000) / 0x100 = 32
    // 40 x 32 tilemap is 2,560 bytes
    ZXN_NEXTREG(0x6E, 32);


    // Set the tilemap to all transparent tiles
    tilemap_clear(TILE_TRANS);

    //0x6B Tilemap Control
    // Turn on the tilemap layer, 40x32, attributes enabled
    // bit 7    1 = enable tilemap
    // bit 6    = 0 for 40x32, 1 for 80x32
    // bit 5    = 1 to eliminate the attribute entry in the tilemap
    // bit 4    = palette select
    // bits 3-2 = Reserved set to 0
    // bit 1    = 1 to activate 512 tile mode
    // bit 0    = 1 to force tilemap on top of ULA    
    ZXN_WRITE_REG(0x6B, 0b10000000);
}

void tilemap_clear(uint8_t tile)
{
    uint8_t *p = tilemap_base_p;

    for (uint16_t s = 0; s < TILE_MAP_WIDTH * TILE_MAP_HEIGHT; s++) {
        *(p) = tile;
        *(p+1) = 0x0;
        p = p+2;
    }
}

// TODO check bounds
// TODO support tile attributes
void tilemap_set_tile(uint8_t x, uint8_t y, uint8_t tile, uint8_t tile_attr)
{
    uint16_t pos = ( (y * TILE_MAP_WIDTH) + x) * 2;
    uint8_t *p = tilemap_base_p + pos;

    *p = tile;
    *(p+1) = tile_attr;
}

// TODO check bounds
// TODO support tile attributes
void tilemap_set_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t tile, uint8_t tile_attr)
{

    uint16_t pos = (y * TILE_MAP_WIDTH) + x;
    uint8_t *p = tilemap_base_p + pos;
    uint8_t dx, dy;
    uint8_t next_row = (TILE_MAP_WIDTH - x) * 2;

    for(dy = 0; dy < h; dy++)
    {
        for(dx = 0; dx < w; dx++)
        {
            *p = tile;
            *(p+1) = tile_attr;    // bits 15-12 palette offset
            p = p + 2;
        }
    p += next_row; 
    }        
}
/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manages ZX Next tilemap

 ***************************************************/
#include "tilemap.h"

#include <arch/zxn.h>

#include "palette.h"
#include "tile_defns.h"

#include "memory_map.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/
uint8_t volatile * const tilemap_base_p = (uint8_t *) TILEMAP_BASE;

/***************************************************
 * functions definitions
 ***************************************************/

void tilemap_init()
{
     /* 0x68 - ULA Control
     *
     * bit 7    =  1 to disable ULA output
     * bit 6    = 0 to select the ULA colour for blending in SLU modes 6 & 7
     *          = 1 to select the ULA/tilemap mix for blending in SLU modes 6 & 7
     * bits 5-1 = Reserved must be 0
     * bit 0 = 1 to enable stencil mode when both the ULA and tilemap are enabled
     * 
     * Disable the ULA screen
     */
    ZXN_NEXTREG(0x68, 0b10000000);

    // initialise palette
    palette_init();

    // initialise tile definitions 
    tile_defns_init();

    /* 0x6E - Tilemap base address
    * Sets the tilemap base address offset within bank 5 
    * 
    * Bank 5 is located at 0x4000 - 0x7fff
    * The ULA screen is located 0x4000 - 0x5FFF (7 KiB) 
    * The ULA screen is not required and has been disabled so we can write the tilemap at 0x4000 
    * The tilemap is 40 * 32 tiles * 2 bytes per tile = 0xA00 (2,560) bytes 
    * 
    * 0x6E is set with the MSB which represents an n x 256 byte offset within bank 5
    * For example, to load the tilemap at 0x6000 the offset would be 32 decimal (0x6000 - 0x4000) / 0x100 = 0x20 (32)
    * 
    * Write the tilemap to 0x4000 - 0x49FF (offset 0 in bank 5)
    */
    ZXN_NEXTREG(0x6E, 0);


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
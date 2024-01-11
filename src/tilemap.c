/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief ZXNext tile definitions

**************************************************/

#include "tilemap.h"

#include <stdint.h>             /* standard names for ints with no ambiguity */
#include <arch/zxn.h>           /* ZXN_NEXTREG */

#include "memory.h"


/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/**
 * @brief Pointer to the base of the ZXnext tilemap 
 * 
 */
static uint8_t *tilemap_base_p = (uint8_t *) TILEMAP_BASE;



/***************************************************
 * functions
 ***************************************************/

void tilemap_init()
{
    /*
     * Set the ZXnext register for the base memory address of the tilemap
     *
     * 0x6E - Tilemap base address
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


    /* 
     * Turn on the zxNext tilemap layer - 40x32 mode with attributes enabled
     *
     * 0x6B Tilemap Contro
     * bit 7    = 1 to enable tilemap
     * bit 6    = 0 for 40x32, 1 for 80x32
     * bit 5    = 1 to eliminate the attribute entry in the tilemap
     * bit 4    = palette select
     * bits 3-2 = Reserved set to 0
     * bit 1    = 1 to activate 512 tile mode
     * bit 0    = 1 to force tilemap on top of ULA    
     */
    ZXN_WRITE_REG(0x6B, 0b10000000);

}

void tilemap_clear(const tilemap_tile_t *tile)
{
    uint8_t *p = tilemap_base_p;

    for (uint16_t s = 0; s < TILE_MAP_WIDTH * TILE_MAP_HEIGHT; s++) {
        *(p) = tile->tile_id;
        *(p+1) = tile->tile_attr;
        p = p+2;
    }
}

void tilemap_set_tile(uint8_t x, uint8_t y, const tilemap_tile_t *tile)
{
    /* TODO check bounds */
    uint16_t pos = ( (y * TILE_MAP_WIDTH) + x) * 2;
    uint8_t *p = tilemap_base_p + pos;

    *p = tile->tile_id;
    *(p+1) = tile->tile_attr;
}


void  tilemap_copy_tile(uint8_t fx, uint8_t fy, uint8_t tx, uint8_t ty)
{
    /* TODO check bounds */
    /* TODO a copy row version would be faster */
    uint16_t fpos = ( (fy * TILE_MAP_WIDTH) + fx) * 2;
    uint8_t *fp = tilemap_base_p + fpos;

    uint16_t tpos = ( (ty * TILE_MAP_WIDTH) + tx) * 2;
    uint8_t *tp = tilemap_base_p + tpos;    

    *tp = *fp; 
    *(tp+1) = *(fp+1);
}
/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Main game

**************************************************/

#include <arch/zxn.h>   // ZX Spectrum Next architecture specific functions
#include <stdio.h>

#include "tile_defns.h"
#include "palette.h"
#include "tilemap.h"
#include "dungeonmap.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions
 ***************************************************/

void init_game()
{
    /* set CPU speed 28MHz */
    ZXN_WRITE_REG(REG_TURBO_MODE, 0b00000011);

    /* disable RAM contention */
    ZXN_WRITE_REG(REG_PERIPHERAL_3, (ZXN_READ_REG(REG_PERIPHERAL_3) | RP3_DISABLE_CONTENTION));

    /*
     * Disable the ZXnext ULA screen
     *
     * 0x68     - ULA Control
     *
     * bit 7    = 1 to disable ULA output
     * bit 6    = 0 to select the ULA colour for blending in SLU modes 6 & 7
     *          = 1 to select the ULA/tilemap mix for blending in SLU modes 6 & 7
     * bits 5-1 = Reserved must be 0
     * bit 0    = 1 to enable stencil mode when both the ULA and tilemap are enabled
     *
     */
    ZXN_NEXTREG(0x68, 0b10000000);

    tile_defns_init();
    palette_init();
    tilemap_init();
    dungeonmap_init();

}

int main()
{
    zx_border(1);
    init_game();

    tilemap_tile_t blank = {1,0};
    tilemap_clear(&blank);

    tilemap_set_tile(1,1, &blank);
    blank.tile_id = 2;
    tilemap_set_tile(2,1, &blank);
    blank.tile_id = 3;
    tilemap_set_tile(3,1, &blank);
    blank.tile_id = 4;
    tilemap_set_tile(4,1, &blank);    
    blank.tile_id = 5;
    tilemap_set_tile(5,1, &blank);    
    
    

    while (1)
    {

    }
    return 0;
}
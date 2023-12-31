/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Memory routines

 ***************************************************/
#include "memory.h"

#include <arch/zxn.h>
#include <inttypes.h>


/***************************************************
 * private types
 ***************************************************/

// tile_palette is defined in palette_data.asm


/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/



/***************************************************
 * functions definitions
 ***************************************************/

void memory_init()
{
    // Map global data (bank 16) into ZX Spectrum 8k MMU slot 0
    ZXN_WRITE_REG(0x50, 16);
    // Map global data (bank 17) into ZX Spectrum 8k MMU slot 1
    ZXN_WRITE_REG(0x51, 17);    
}

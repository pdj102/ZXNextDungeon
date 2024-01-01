/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon map generator

 ***************************************************/
#include "dungeonmap_generator.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions     

#include "dungeonmap_generator_bank.h"

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
 * functions definitions
 ***************************************************/

void dungeonmap_generate()
{
    /* Map Dungeon Map Generator (bank 18) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 18);
    /* Call banked code */ 
    dungeonmap_generate_b(); 
}
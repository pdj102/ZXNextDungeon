/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - close

**************************************************/

#include <inttypes.h>
#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions   

#include "object_create.h"

#include "object.h"
#include "object_create_bank.h"


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


// TO DO move into  bank code for creating objects 
object_t* object_create(object_subtype_e subtype, uint8_t x, uint8_t y)
{
    /* Map Dungeon Map Generator (bank 20) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 20);
    /* Call banked code */ 
    return object_create_b(subtype, x, y);
}
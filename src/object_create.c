/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - close

**************************************************/

#include <stdint.h>
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

object_t* object_create(object_subtype_e subtype, uint8_t x, uint8_t y)
{
    uint8_t current_bank;
    object_t *o;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Object create (bank 20) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(20);    
    o = object_create_b(subtype, x, y);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return o;  
}
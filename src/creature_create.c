/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

**************************************************/

#include "creature_create.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions    

#include "creature_create_bank.h"
#include "object.h"

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

creature_t* creature_create(object_t *obj_p)
{
    /* Map Create Creature (bank 18) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 22);
    /* Call banked code */ 
    return creature_create_b(obj_p);     
}

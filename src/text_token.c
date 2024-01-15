/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Text token

**************************************************/

#include "text_token.h"

#include <stdint.h>
#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions   

#include "text_token_bank.h"


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

// TODO - the banked code text_token_print_b will be called by other banked code.
// Need to ensure the calling banked code is not swapped out on return 
// Solution? Record the current bank in the MMU slot before swapping out and then switch it back in before returning
// This would work becuase text_tolen_print_b does not call any other banked code and does not call itself
void text_token_print(uint16_t c)
{
    ZXN_WRITE_REG(0x57, 21);
    /* Call banked code */ 
    text_token_print_b(c);
}
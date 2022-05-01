/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief <Module description>

 ***************************************************/
#include "token.h"

#include <stdio.h>          // NULL
#include <arch/zxn.h>       // ZX Spectrum Next architecture specfic functions

#include "token_bank.h"

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

// extern void token_string_print_b(token_string_token_t *token_string, char *destination, uint8_t max);

void token_print(token_string_token_t *token_string, char *destination, uint8_t max)
{
     /* Map Token String (bank 21) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 21);  
    /* Call banked code */
    token_print_b(token_string, destination, max);
}



/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Text token

    Banked code. Do not call directly

 ***************************************************/
#include "text_token_bank.h"

#include <stdint.h>
#include <string.h>     /* strlen() */       

#include "text.h"
        

#pragma output CRT_ORG_CODE = 0xe000

/***************************************************
 * private types 
 ***************************************************/

/***************************************************
 * private function prototypes - static
 ***************************************************/


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/

/***************************************************
 * functions definitions
 ***************************************************/

void dummy(void)
{

}
void text_token_print_b(uint16_t c)
{
    char *text = &text_token_data[0] + (c * 25);

    uint8_t l = strlen(text);

    for (uint8_t i = 0; i < l; i++)
    {
        text_putc(text[i]);

    }
}
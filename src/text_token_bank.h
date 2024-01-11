/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Object base

    Banked code. Do not call directly     

 ***************************************************/

#ifndef TEXT_TOKEN_BANK_H 
    #define TEXT_TOKEN_BANK_H 

#include <stdint.h>

/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/

extern char text_token_data[];

/***************************************************
 * function prototypes
 ***************************************************/

void text_token_print_b(uint8_t c);

void dummy(void);

#endif
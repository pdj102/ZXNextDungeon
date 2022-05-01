/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief <Module description>

 ***************************************************/

#ifndef TOKEN_BANK_H 
    #define TOKEN_BANK_H 

#include <inttypes.h>

#include "token_type.h"

/***************************************************
 * public types
 ***************************************************/


/***************************************************
 * public variable declarations - extern
 ***************************************************/


/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief prints a token based string to *destination. Appends \0 to end of string
 * 
 * @param token_string Pointer to token based string (MUST NOT BE MEMORY THAT GETS DEBANKED)
 * @param destination Pointer to the destination to print the string
 * @param max Size of destination buffer including \0
 * 
 */
void token_print_b(token_string_token_t *token_string, char *destination, uint8_t max);

#endif
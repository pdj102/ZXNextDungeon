/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief <Module description>

 ***************************************************/

#ifndef TOKEN_STRING_H 
    #define TOKEN_STRING_H 

#include <inttypes.h>

#include "token_string_type.h"

/***************************************************
 * public types
 ***************************************************/
 

typedef enum token
{
    RED_TOKEN,
    BLUE_TOKEN,
    GREEN_TOKEN,
    WHITE_TOKEN,
    BLACK_TOKEN,
    GREY_TOKEN,
    COPPER_TOKEN,
    SILVER_TOKEN,
    GOLD_TOKEN,

    SMALL_TOKEN,
    MEDIUM_TOKEN,
    LARGE_TOKEN,

    SHORT_TOKEN,
    LONG_TOKEN,

    ANT_TOKEN,
    DOG_TOKEN,
    SNAKE_TOKEN,
    RAT_TOKEN,
    SPIDER_TOKEN,
    GOBLIN_TOKEN,
    SKELETON_TOKEN,
    ORC_TOKEN,
    GHOUL_TOKEN,

    SWORD_TOKEN,
    DAGGER_TOKEN,
    SLING_TOKEN,
    BOW_TOKEN,

    ARMOUR_TOKEN,
    HELMET_TOKEN,

    LEATHER_TOKEN,
    METAL_TOKEN,

    RING_TOKEN,

    POTION_TOKEN

} token_t;



/***************************************************
 * public variable declarations - extern
 ***************************************************/


/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief Calls banked code to print a token based string to *destination. Appends \0 to end of string
 * 
 * @param token_string Pointer to token based string (MUST NOT BE MEMORY THAT GETS DEBANKED)
 * @param destination Pointer to the destination to print the string
 * @param max Size of destination buffer including \0
 */
void token_string_print(token_string_token_t *token_string, char *destination, uint8_t max);


#endif
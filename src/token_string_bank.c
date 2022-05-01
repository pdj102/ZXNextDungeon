/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief <Module description>

 ***************************************************/
#include "token_string_bank.h"

#include <stdio.h>      // NULL

#pragma output CRT_ORG_CODE = 0xC000 



/***************************************************
 * private types
 ***************************************************/



/***************************************************
 * private function prototypes
 ***************************************************/

static char *token_string_to_b(token_string_token_t token);

/***************************************************
 * extern variables - extern
 ***************************************************/
extern char *strs;

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions 
 ***************************************************/
  

void token_string_print_b(token_string_token_t *token_string, char *destination, uint8_t max)
{
    char *string;

    uint8_t ts_pos = 0;



    if (token_string == NULL || destination == NULL || max == 0)
    {
        return;
    }


    while (*token_string != '\0')
    {
        string = token_string_to_b(*token_string);
        token_string++;

        if (string != NULL)
        {
            while( *string != '\0' && ts_pos < max - 1)
            {
                *destination = *string;
                string++;
                destination++;
                ts_pos++;
            }
        }
    }
    *destination = '\0';
}


static char *token_string_to_b(token_string_token_t token)
{
   // messages_print_s_uint8("TOKEN ", token);

    // TODO check token less than max token
    // return strs+=token;

    return strs;
}

/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Player code

 ***************************************************/
#include "player.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <input.h>              // Functions for Reading Keyboards, Joysticks and Mice
#include <ctype.h>              // character classification e.g. toupper() 

#include "dungeonmap.h"

/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void player_turn()
{
    unsigned char key;

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    switch(toupper(key)) {
        
        case '1':
            dungeonmap_scroll(-1, 0);
            dungeonmap_draw();
            break;
        case '2':
            dungeonmap_scroll(1, 0);
            dungeonmap_draw();
            break;
        case '3':
            dungeonmap_scroll(0, -1);
            dungeonmap_draw();
            break;
        case '0':
            dungeonmap_scroll(0, 1);
            dungeonmap_draw();
            break;
        default:
            // text_print_int8(24, 20, key);
            break;
    }
}

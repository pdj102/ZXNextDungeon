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
#include "object.h"
#include "object_action_move.h"
#include "object_action_open.h"
#include "object_action_close.h"
#include "object_action_pickup.h"

/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/

void open_or_close();
void pickup();

/***************************************************
 * private variables - static
 ***************************************************/
static object_t *player_obj_ptr;

/***************************************************
 * functions
 ***************************************************/

void player_init(object_t *obj_ptr)
{
    player_obj_ptr = obj_ptr;
}

void player_turn()
{
    unsigned char key;

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    switch(toupper(key)) {
        
        case 54:  // down
            object_action_move_by(player_obj_ptr, 0, 1);
            break;

        case 55:  // up
            object_action_move_by(player_obj_ptr, 0, -1);
            break;

        case 53:  // left
            object_action_move_by(player_obj_ptr, -1, 0);
            break;

        case 56:  // right
            object_action_move_by(player_obj_ptr, 1, 0);
            break;

        case 'O':  // open or close
            open_or_close();
            break;

        case 'P':  // pickup
            pickup();
            break;            

        case '1':
            dungeonmap_scroll(-1, 0);
            break;
        case '2':
            dungeonmap_scroll(1, 0);
            break;
        case '3':
            dungeonmap_scroll(0, -1);
            break;
        case '0':
            dungeonmap_scroll(0, 1);
            break;
        default:
            // text_print_int8(24, 20, key);
            break;
    }
}

uint8_t get_dir_or_cancel(int8_t *dx, int8_t *dy)
{
    unsigned char key;

    while ((key = in_inkey()) == 0)
        ;            // loop while no key pressed
    in_wait_nokey(); // wait no key

    switch (toupper(key))
    {

    case 54: // down
        *dx = 0;
        *dy = 1;
        return 1;

    case 55: // up
        *dx = 0;
        *dy = -1;
        return 1;

    case 53: // left
        *dx = -1;
        *dy = 0;
        return 1;

    case 56: // right
        *dx = 1;
        *dy = 0;
        return 1;

    default:
        return 0;
    }
}

void open_or_close()
{
    int8_t dx, dy;
    uint8_t x, y;

    object_t *obj_ptr;

    if (! (get_dir_or_cancel(&dx, &dy)) )
    {
        return;
    }

    x = player_obj_ptr->x + dx;
    y = player_obj_ptr->y + dy;

    if ( obj_ptr = object_action_open_findat(x, y) )
    {
        object_action_open(obj_ptr);
        return;
    }
    
    if ( obj_ptr = object_action_close_findat(x, y) )
    {
        object_action_close(obj_ptr);
        return;
    }
}

void pickup()
{
    object_t *obj_ptr;

    if ( obj_ptr = object_action_pickup_findat(player_obj_ptr->x, player_obj_ptr->y) )
    {
        object_action_pickup(obj_ptr, player_obj_ptr);
        return;
    }  
}

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
#include "object_move.h"
#include "object_open.h"
#include "object_close.h"
#include "object_pickup.h"
#include "object_drop.h"
#include "object_strike.h"

#include "creature.h"
#include "creature_melee_strike.h"

/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/

void open_or_close();
void pickup();
void drop();
void attack();

/***************************************************
 * private variables - static
 ***************************************************/
static creature_t *player_creature_p;

/***************************************************
 * functions
 ***************************************************/

void player_init(creature_t *creature_p)
{
    player_creature_p = creature_p;
}

void player_turn()
{
    unsigned char key;

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    switch(toupper(key)) {
        
        case 54:  // down
            object_move_by(player_creature_p->obj_p, 0, 1);
            break;

        case 55:  // up
            object_move_by(player_creature_p->obj_p, 0, -1);
            break;

        case 53:  // left
            object_move_by(player_creature_p->obj_p, -1, 0);
            break;

        case 56:  // right
            object_move_by(player_creature_p->obj_p, 1, 0);
            break;

        case 'O':  // open or close
            open_or_close();
            break;

        case 'P':  // pickup
            pickup();
            break;

        case 'D':  // drop
            drop();
            break;

        case 'A':  // attack
            attack();
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

void attack()
{
    int8_t dx, dy;
    uint8_t x, y;

    object_t *obj_p;

    creature_t *target_p;

    if (! (get_dir_or_cancel(&dx, &dy)) )
    {
        return;
    }

    x = player_creature_p->obj_p->x + dx;
    y = player_creature_p->obj_p->y + dy;

    if ( obj_p = object_strike_find_first_at(x, y) )
    {
        target_p = obj_p->creature_p;
        creature_melee_strike(player_creature_p, target_p);
        return;
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

    x = player_creature_p->obj_p->x + dx;
    y = player_creature_p->obj_p->y + dy;

    if ( obj_ptr = object_open_findat(x, y) )
    {
        object_open(obj_ptr);
        return;
    }
    
    if ( obj_ptr = object_close_findat(x, y) )
    {
        object_close(obj_ptr);
        return;
    }
}

void pickup()
{
    object_t *obj_ptr;

    if ( obj_ptr = object_pickup_find_first_at(player_creature_p->obj_p->x, player_creature_p->obj_p->y) )
    {
        object_pickup(obj_ptr, player_creature_p->obj_p);
    }  
}

void drop()
{
    object_t *obj_todrop_ptr;

    if ( obj_todrop_ptr = object_drop_find_first(player_creature_p->obj_p) )
    {
        object_drop(obj_todrop_ptr, player_creature_p->obj_p);
    }  
}

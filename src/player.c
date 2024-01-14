/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Player code

 ***************************************************/
#include "player.h"


#include <stdint.h>
#include <input.h>              // Functions for Reading Keyboards, Joysticks and Mice
#include <ctype.h>              // character classification e.g. toupper() 

#include "dungeonmap.h"

#include "globaldata_defines.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_move.h"
#include "object_open.h"
#include "object_close.h"
#include "object_pickup.h"
#include "object_drop.h"
#include "object_strike.h"
#include "object_destroy.h"

#include "object_dungeon_list.h"

#include "creature.h"
#include "creature_melee_strike.h"
#include "creature_damage.h"
#include "creature_destroy.h"

/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/

void open( void );
void close( void );
void pickup( void );
void drop( void );
void attack( void );
void move(int8_t dx, int8_t dy);
void inventory( void );

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

void player_turn( void )
{
    unsigned int key;

    // while ((key = in_Inkey()) == 0) ;   // loop while no key pressed
    // in_WaitForNoKey();    // wait no key
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key    

    switch(toupper(key)) {
        
        case 54:  // down
            move(0, 1);
            break;
        case 55:  // up
            move(0, -1);
            break;

        case 53:  // left
            move(-1, 0);
            break;

        case 56:  // right
            move (1, 0);
            break;

        case 'O':  // open
            open();
            break;

        case 'C':  // close
            close();
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

        case 'I':  // show inventory
            inventory();
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
    unsigned int key;

    // while ((key = in_Inkey()) == 0) ;   // loop while no key pressed
    // in_WaitForNoKey();    // wait no key
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key   

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

void attack( void )
{
    int8_t dx, dy;
    uint8_t x, y;
    uint8_t damage_roll;
    uint8_t actual_damage;

    object_t *obj_p;

    creature_t *target_p;

    if (! (get_dir_or_cancel(&dx, &dy)) )
    {
        return;
    }

    x = player_creature_p->obj_p->x + dx;
    y = player_creature_p->obj_p->y + dy;

    if ( obj_p = object_find_first_is_at(x, y, object_strike_is))
    {
        target_p = obj_p->creature_p;

        // Miss?
        if (!creature_melee_strike(player_creature_p, target_p))
        {
            text_printf("YOU MISS THE %t\n", target_p->obj_p->name_token);
        }

        // Hit
        text_printf("YOU HIT THE %t\n", target_p->obj_p->name_token);

        // Roll for melee damage
        damage_roll = dice_roll(&player_creature_p->melee_damage_roll) + player_creature_p->melee_modifier;

        // Attempt to apply damage
        actual_damage = creature_damage(target_p, damage_roll, player_creature_p->melee_damage_type);

        // Was the target immune, vulnerable or resist damage? 
        if (actual_damage == 0)
        {
            text_printf("YOUR HIT HAS NO EFFECT\n");
        }
        else if (actual_damage < damage_roll)
        {
            text_printf("IT RESISTS SOME DAMAGE\n");
        }
        else if (actual_damage > damage_roll)
        {
            text_printf("YOUR HIT CAUSES EXTRA DAMAGE\n");
        }

        text_printf("HIT POINTS %u\n", target_p->hp);

        // Is the target dead?
        if (target_p->hp == 0)
        {
            text_printf("YOU KILLED THE %t\n", target_p->obj_p->name_token);
            
            // Destory the creature
            object_destroy(target_p->obj_p);
            creature_destroy(target_p);
        }
    }
}

void move(int8_t dx, int8_t dy)
{
    if (object_move_by(player_creature_p->obj_p, dx, dy))
    {
        player_creature_p->energy -= 100;
    }
}

// TODO tokenise strings to save memory 

void open( void )
{
    int8_t dx, dy;
    uint8_t x, y;

    object_t *obj_p;

    if (! (get_dir_or_cancel(&dx, &dy)) )
    {
        return;
    }

    x = player_creature_p->obj_p->x + dx;
    y = player_creature_p->obj_p->y + dy;

    if ( obj_p = object_find_first_is_at(x, y, object_open_is))
    {
        if ( object_open(obj_p) )
        {
            text_printf("YOU OPEN THE %t\n", (uint8_t) obj_p->name_token);

            return;
        }
    }
    text_printf("NOTHING TO OPEN HERE\n");
}

void close( void )
{
    int8_t dx, dy;
    uint8_t x, y;

    object_t *obj_p;

    if (! (get_dir_or_cancel(&dx, &dy)) )
    {
        return;
    }

    x = player_creature_p->obj_p->x + dx;
    y = player_creature_p->obj_p->y + dy;

    if ( obj_p = object_find_first_is_at(x, y, object_close_is))
    {
        if ( object_close(obj_p) )
        {
            text_printf("YOU CLOSE THE %t\n", (uint8_t) obj_p->name_token);
            return;
        }
    }
    text_printf("NOTHING TO CLOSE HERE\n");
}

void pickup( void )
{
    object_t *obj_p;

    if ( obj_p = object_find_first_is_at(player_creature_p->obj_p->x, player_creature_p->obj_p->y, object_pickup_is))
    {
        object_pickup(obj_p, player_creature_p->obj_p);
        text_printf("YOU PICK UP THE %t\n", (uint8_t) obj_p->name_token);
        return;
    }
    text_print_string("NOTHING TO PICK UP HERE\n");
}

// TODO implement drop from inventory 
void drop( void )
{
    object_t *obj_p;

    if ( obj_p = object_drop_find_first(player_creature_p->obj_p) )
    {
        object_drop(obj_p, player_creature_p->obj_p);
        text_printf("YOU DROP THE %t\n", (uint8_t) obj_p->name_token);   
        return;     
    }
    text_printf("NOTHING TO DROP\n");
}

void inventory( void )
{
    object_t *obj_p;
    unsigned char index = 'A';
    unsigned int key;    


    obj_p = object_list_first(player_creature_p->obj_p);
    
    if (!obj_p)
    {
        text_printf("THERE IS NOTHING IN YOUR INVENTORY\n");
        return;
    }
    
    text_select_win( WIN_LARGE);
    text_cls();

    while (obj_p)
    {
        text_printf("%c) ", index);
        text_printf("%t\n", obj_p->name_token);

        index++;
        obj_p = object_list_next(obj_p);
    }

    text_printf("\n PRESS ANY KEY\n");
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key 

    text_select_win( WIN_MESSAGES);

}

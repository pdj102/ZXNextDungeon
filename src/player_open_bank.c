/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - open action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"

#include "globaldata.h"

#include "dungeonmap_list.h"

#include "creature.h"
#include "creature_action_open.h"

#include "text.h"
#include "text_token.h"

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

void player_open_b( void )
{
    const direction_t d = get_dir_or_cancel_b();

    if (d == NO_DIR)
    {
        return;
    }

    if ( ! creature_action_open_dir(globaldata.player.player_creature_p, d) )
    {
        text_printf("Nothing to open here\n");
    }
}
/*    
    int8_t dx, dy;
    uint8_t x, y;

    object_t *obj_p;

    if (! (get_dir_or_cancel_b(&dx, &dy)) )
    {
        return;
    }

    x = globaldata.player.player_creature_p->obj_p->x + dx;
    y = globaldata.player.player_creature_p->obj_p->y + dy;

    if ( obj_p = dungeonmap_list_first_is_at(x, y, object_open_is))
    {
        globaldata.player.player_creature_p->energy = 0;

        if ( object_open(obj_p) )
        {
            text_printf("You open the %t\n", (unsigned int) obj_p->name_token);

            return;
        }
    }
    text_printf("Nothing to open here\n");
*/

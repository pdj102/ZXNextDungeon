/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Main game

**************************************************/

#include <arch/zxn.h>   // ZX Spectrum Next architecture specific functions
#include <stdio.h>

#include "globaldata.h"
#include "memory.h"
#include "tile_defns.h"
#include "palette.h"
#include "tilemap.h"
#include "dungeonmap.h"
#include "dungeonmap_generator.h"
#include "player.h"
#include "object_action_move.h"
#include "object.h"
#include "text.h"


/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

static object_t *player_obj_ptr ;

/***************************************************
 * functions
 ***************************************************/

void init_game()
{
    /* set CPU speed 28MHz */
    ZXN_WRITE_REG(REG_TURBO_MODE, 0b00000011);

    /* disable RAM contention */
    ZXN_WRITE_REG(REG_PERIPHERAL_3, (ZXN_READ_REG(REG_PERIPHERAL_3) | RP3_DISABLE_CONTENTION));

    /*
     * Disable the ZXnext ULA screen
     *
     * 0x68     - ULA Control
     *
     * bit 7    = 1 to disable ULA output
     * bit 6    = 0 to select the ULA colour for blending in SLU modes 6 & 7
     *          = 1 to select the ULA/tilemap mix for blending in SLU modes 6 & 7
     * bits 5-1 = Reserved must be 0
     * bit 0    = 1 to enable stencil mode when both the ULA and tilemap are enabled
     *
     */
    ZXN_NEXTREG(0x68, 0b10000000);

    memory_init();
    globaldata_init();
    
    tile_defns_init();
    palette_init();
    tilemap_init();

    text_init();

    dungeonmap_init();
    object_init();

    object_t    *obj_ptr;

    obj_ptr = object_create(HUMANOID_HUMAN, 2, 2);
    player_obj_ptr = obj_ptr;
    object_add_to_dungeon_list(obj_ptr);

    obj_ptr = object_create(POTION_HEALING, 2, 5);
    object_add_to_dungeon_list(obj_ptr);
    obj_ptr = object_create(POTION_SPEED, 5, 5);
    object_add_to_dungeon_list(obj_ptr);
    obj_ptr = object_create(DOOR_CLOSED, 4, 7);    
    object_add_to_dungeon_list(obj_ptr);

    player_init(player_obj_ptr);
   
}


int main()
{
    zx_border(1);
    init_game();
    zx_border(4);
 
    dungeonmap_generate();

    dungeonmap_draw();
    object_drawall();

    text_print_string_at(0, 24, "WELCOME TO DUNGEON!");
    text_print_string("EXPLORE");

    while (1)
    {
        player_turn();

        dungeonmap_draw();
        object_drawall();

    }
    return 0;
}
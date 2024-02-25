/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Main game

**************************************************/

#include <arch/zxn.h>   // ZX Spectrum Next architecture specific functions
#include <stdio.h>

#include "globaldata.h"
#include "globaldata_defines.h"
#include "memory.h"
#include "text.h"
#include "tile_defns.h"
#include "palette.h"
#include "tilemap.h"

#include "dungeonmap.h"
#include "dungeonmap_generator.h"

#include "object.h"
#include "object_list.h"
#include "dungeonmap_list.h"
#include "object_create.h"
#include "object_move.h"
#include "object_destroy.h"
#include "object_pickup.h"
#include "object_open.h"

#include "creature.h"
#include "creature_list.h"
#include "creature_create.h"

#include "player.h"
#include "player_calc_stats.h"

#include "event.h"
#include "event_list.h"

#include "ui_stats.h"

#include "util.h"

#include "adt/p_forward_list.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

uint8_t call_back(object_t *obj_p);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/



void init_game( void )
{
    event_t *tmp_event_p;  

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

    // Init windows
    // Tilemap is 40x32
    text_init();
    text_init_window(WIN_MESSAGES, 0, 24, 40, 8);  // init window used for messages
    text_cls();     
    text_init_window(WIN_LARGE, 0, 0, 24, 24);  // init large window used for inventory etc
    text_cls(); 
    text_init_window(WIN_STATS, 24, 0, 16, 24);  // init window used for player stats 
    text_cls();
    text_select_win(WIN_MESSAGES);

    dungeonmap_init();
    object_init();
    dungeonmap_list_init();

    event_init();
    event_list_init();    

    creature_init();
    creature_list_init();

    player_init();

    dungeonmap_generate();

    // snake 1
    creature_create(BEAST_SNAKE, 10, 2);

    // snake 2
    // creature_create(BEAST_SNAKE, 12, 2);

    // withering weed
    creature_create(PLANT_WITHERWEED, 4, 3);

    // slime ooze
    creature_create(OOZE_SLIME, 15, 5);

    // grey ooze
    creature_create(OOZE_GREY, 5, 23);    

    object_t *healing_obj_p = object_create(POTION_HEALING, 0, 0);
    // todo dungeonmap_addobject()
    dungeonmap_list_add(healing_obj_p);
    object_move_place(healing_obj_p, 2, 5);

    object_t *door_obj_p = object_create(DOOR_CLOSED, 0, 0);
    dungeonmap_list_add(door_obj_p);
    object_move_place(door_obj_p, 4, 7);

    object_t *chest_obj_p = object_create(CHEST_LARGE, 0, 0);
    dungeonmap_list_add(chest_obj_p);
    object_move_place(chest_obj_p, 4, 4);

    object_t *speed_obj_p = object_create(POTION_SPEED, 0, 0);
    object_list_add(speed_obj_p, chest_obj_p);

    object_t *speed2_obj_p = object_create(POTION_SPEED, 0, 0);
    object_list_add(speed2_obj_p, chest_obj_p);    
   
    object_t *trap_obj_p = object_create(TRAP_NOISE, 0, 0);      
    dungeonmap_list_add(trap_obj_p);
    object_move_place(trap_obj_p, 1, 2);

    object_t *ring_obj_p = object_create(RING_HP, 0, 0);      
    dungeonmap_list_add(ring_obj_p);
    object_move_place(ring_obj_p, 3, 2);

    tmp_event_p = event_create_object_cb(object_open, door_obj_p, 5);
    event_list_add(tmp_event_p);

    tmp_event_p = event_create_object_cb(object_open, chest_obj_p, 6);
    event_list_add(tmp_event_p);    

    player_calc_stats();
}

int main( void )
{



    util_assert(sizeof(globaldata_t) < (16 * 1024));     // check global data struct is less than 16KiB and fits in MMU slots 0 and 1

    init_game();
 


    #ifdef DEBUG
        text_print_string("DEBUG: GLOBAL DATA SIZE:");

        text_print_uint16(sizeof(globaldata_t));
        text_print_string("\n");
    #endif    

    text_printf("Welcome to Dungeon!\n");
    ui_display_hp_mp();
    ui_display_stats();

    while (1)
    {
        dungeonmap_draw();
        dungeonmap_list_drawall();

        event_list_update_all();

        creature_list_update_all();
    }
    return 0;
}
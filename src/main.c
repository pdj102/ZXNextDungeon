/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Main game

**************************************************/

#include <arch/zxn.h>   // ZX Spectrum Next architecture specific functions
#include <stdio.h>

#include "globaldata.h"
#include "memory.h"
#include "text.h"
#include "tile_defns.h"
#include "palette.h"
#include "tilemap.h"
#include "dungeonmap.h"
#include "dungeonmap_generator.h"
#include "player.h"
#include "object.h"
#include "object_list.h"
#include "object_dungeon_list.h"
#include "object_create.h"
#include "object_move.h"
#include "object_destroy.h"
#include "object_pickup.h"
#include "object_open.h"

#include "creature.h"
#include "creature_list.h"
#include "creature_create.h"

#include "event.h"
#include "event_list.h"

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
    object_dungeon_list_init();

    event_init();
    event_list_init();    

    creature_init();
    creature_list_init();

    creature_t  *snake1_creature_p;
    creature_t  *snake2_creature_p;
    object_t     *snake1_obj_p;
    object_t     *snake2_obj_p;

    event_t *tmp_event_p;  

    // player
    object_t *human_obj_p = object_create(HUMANOID_HUMAN, 2, 2);
    object_dungeon_list_add(human_obj_p);

    creature_t *human_creature_p = creature_create(human_obj_p);
    creature_list_add(human_creature_p);
    human_obj_p->creature_p = human_creature_p;
    human_creature_p->creature_class = PLAYER;
    player_init(human_creature_p);
    

    // snake 1
    snake1_obj_p = object_create(BEAST_SNAKE, 10, 2);
    snake1_creature_p = creature_create(snake1_obj_p);
    snake1_obj_p->creature_p = snake1_creature_p;
    object_dungeon_list_add(snake1_obj_p);
    creature_list_add(snake1_creature_p);

    // snake 2
    snake2_obj_p = object_create(BEAST_SNAKE, 12, 2);
    snake2_creature_p = creature_create(snake2_obj_p);
    snake2_obj_p->creature_p = snake2_creature_p;
    object_dungeon_list_add(snake2_obj_p);
    creature_list_add(snake2_creature_p);    

    object_t *healing_obj_p = object_create(POTION_HEALING, 2, 5);
    object_dungeon_list_add(healing_obj_p);

    object_t *door_obj_p = object_create(DOOR_CLOSED, 4, 7);      
    object_dungeon_list_add(door_obj_p);

    object_t *chest_obj_p = object_create(CHEST_LARGE, 4, 4);
    object_dungeon_list_add(chest_obj_p);

    object_t *speed_obj_p = object_create(POTION_SPEED, 5, 5);
    object_list_add(speed_obj_p, chest_obj_p);

    object_t *speed2_obj_p = object_create(POTION_SPEED, 5, 5);
    object_list_add(speed2_obj_p, chest_obj_p);    
   
    object_t *trap_obj_p = object_create(TRAP_NOISE, 1, 1);      
    object_dungeon_list_add(trap_obj_p);

    tmp_event_p = event_create_object_cb(object_open, door_obj_p, 5);
    event_list_add(tmp_event_p);

    tmp_event_p = event_create_object_cb(object_open, chest_obj_p, 6);
    event_list_add(tmp_event_p);    

}

int main( void )
{
    zx_border(1);
    init_game();
    zx_border(4);
 
    dungeonmap_generate();

    text_printf("WELCOME TO DUNGEON!\n");
    text_printf("TEST TOKEN %t UINT8 %u INT8 %d \n", (uint8_t)1, (uint8_t)255, (int8_t)-128);

    text_print_string("GLOBAL DATA SIZE:");
    uint16_t s;
    s = sizeof(globaldata_t);
    text_print_uint16(s);
    text_print_string("\n");

    while (1)
    {
        dungeonmap_draw();
        object_dungeon_list_drawall();

        event_list_update_all();

        creature_list_update_all();
    }
    return 0;
}
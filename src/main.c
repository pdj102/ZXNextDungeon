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

#include "event.h"
#include "event_list.h"


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

static object_t *player_obj_ptr ;

static object_t *tmp_obj_ptr1;
static object_t *tmp_obj_ptr2;
static event_t *tmp_event_p;

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
    object_dungeon_list_init();

    event_init();
    event_list_init();    

    creature_init();

    object_t    *obj_ptr;
    creature_t  *creature_p;

    obj_ptr = object_create(HUMANOID_HUMAN, 2, 2);
    player_obj_ptr = obj_ptr;
    creature_p = creature_create(player_obj_ptr);
    object_dungeon_list_add(obj_ptr);
    player_init(player_obj_ptr);

    obj_ptr = object_create(BEAST_SNAKE, 10, 2);
    creature_p = creature_create(obj_ptr);
    object_dungeon_list_add(obj_ptr);

    obj_ptr = object_create(POTION_HEALING, 2, 5);
    object_dungeon_list_add(obj_ptr);
  

    obj_ptr = object_create(DOOR_CLOSED, 4, 7);      
    tmp_obj_ptr2 = obj_ptr;
    object_dungeon_list_add(obj_ptr);

    obj_ptr = object_create(CHEST_LARGE, 4, 4);
    tmp_obj_ptr1 = obj_ptr;
    object_dungeon_list_add(obj_ptr);

    obj_ptr = object_create(POTION_SPEED, 5, 5);
    object_list_add(obj_ptr, tmp_obj_ptr1); 

    obj_ptr = object_create(POTION_SPEED, 5, 5);
    object_list_add(obj_ptr, tmp_obj_ptr1);     
   
    obj_ptr = object_create(TRAP_NOISE, 1, 1);      
    object_dungeon_list_add(obj_ptr);

    tmp_event_p = event_create_object_cb(object_open, tmp_obj_ptr2, 10);
    event_list_add(tmp_event_p);
}

uint8_t call_back(object_t *obj_p)
{
    text_print_string("CALL BACK");
}

int main()
{
    zx_border(1);
    init_game();
    zx_border(4);
 
    dungeonmap_generate();

    text_print_string_at(0, 24, "WELCOME TO DUNGEON!");

    uint16_t s;
    s = sizeof(globaldata_t);
    text_print_uint16(s);

    dungeonmap_draw();
    object_dungeon_list_drawall();


    while (1)
    {
        player_turn();

        dungeonmap_draw();
        object_dungeon_list_drawall();

        event_update_all();

    }
    return 0;
}
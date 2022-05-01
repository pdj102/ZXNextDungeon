/***************************************************
    Dungeon - ZX Spectrum Next
    Paul Johnson

 ***************************************************/

#include <arch/zxn.h> // ZX Spectrum Next architecture specfic functions

#include "player.h"
#include "dungeon_map.h"
#include "dungeon_map_generator.h"
#include "tilemap.h"

#include "entity.h"
#include "entity_creature.h"
#include "entity_item.h"
#include "ui.h"
#include "messages.h"
#include "token_string.h"

#include "ai_pathfind.h"
#include "ai.h"

//#define printAt(row, col)    printf("\x16%c%c", row, col)

/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/

void draw_all()
{
    dungeon_map_draw();

    entity_draw_all();

    messages_display();
}

void init_game()
{
    /* set CPU speed 28MHz */
    ZXN_WRITE_REG(0x07, 0b00000011);

    /* Init dungeon map data structures */
    dungeon_map_init();

    dungeon_map_generate();    

    entity_init();
    entity_creature_init();
    entity_item_init();

    tilemap_init();

    messages_init();

    entity_creature_create(SNAKE, 19, 19);
    entity_creature_create(SNAKE, 11, 11);
    entity_creature_create(SNAKE, 2, 2);
    entity_item_create(blue_potion, 13, 5);    
    entity_item_create(red_potion, 13, 13);
    entity_item_create(ring_ac, 11, 5);
    entity_item_create(red_potion, 10, 5);    

    entity_item_create(long_sword, 5, 4);
    entity_item_create(metal_helmet, 6, 4);
    entity_item_create(chain_mail_armour, 7, 4);

    player_create(5, 5);

    ai_pathfind(5, 5);
}

void play_game()
{
    entity_t *entity_ptr = entity_front();

    // step through each entity
    while (entity_ptr)
    {
        // increment energy
        if (entity_ptr->current_energy < 10)
        {
            entity_ptr->current_energy++;
        }

        // enough energy to take a turn?
        // TODO change energy system so can current energy decreases each turn, can take action when current energy is 0 and the action adds to the current energy
        if (entity_ptr->current_energy >= 10)
        {
            if (entity_ptr == entity_player_ptr)
            {
                player_turn();
            }
            else if (entity_ptr->type == entity_type_creature)
            {
                ai_turn((creature_t *)entity_ptr->ptr);
            }
        }
        entity_ptr = entity_next(entity_ptr);
    }
}

int main()
{
    char test[15];

    token_string_token_t ts[] = { 1, 2, 3, 0};

    token_string_print(ts, test, 15);
    messages_println(test);

    init_game();

    draw_all();

    while (entity_player_ptr)
    {
        play_game();
        entity_draw_all();
        ui_draw_stat_block((creature_t *)entity_player_ptr->ptr);        
    };
    return 0;
}

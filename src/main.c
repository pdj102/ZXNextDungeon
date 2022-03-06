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
#include "messages.h"

#include "ai_pathfind.h"
#include "ai.h"

//#define printAt(row, col)    printf("\x16%c%c", row, col)

/***************************************************
 * function prototypes
 ***************************************************/
void hit(uint8_t x, uint8_t y);

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

    /* Init dungeon map data structures */
    dungeon_map_init();

    /* Map Dungeon map generator (bank 18) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 18);
    dungeon_map_generate();    

    entity_init();
    entity_creature_init();
    entity_item_init();

    tilemap_init();

    messages_init();

    entity_creature_create(SNAKE, 19, 19);
    entity_creature_create(SNAKE, 11, 11);
    entity_creature_create(SNAKE, 2, 2);
    entity_item_create(RING, 13, 13);

    player_create(5, 5);

    // Map bank 19 into ZX Spectrum 8k MMU slot 6
    ZXN_WRITE_REG(0x56, 19);
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
            else if (entity_ptr->type == creature)
            {
                ai_turn((creature_t *)entity_ptr->ptr);
            }
        }
        entity_ptr = entity_next(entity_ptr);
    }
}

int main()
{
    init_game();

    draw_all();

    while (entity_player_ptr)
    {
        play_game();
        entity_draw_all();
        entity_creature_draw_stat_block(creature_player_ptr);
    };
    return 0;
}

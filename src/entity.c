/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manage entities. An entity represents an item, effect or creature

    Provides functions that can be used on any type of entity.
    Entity type specific functions are provided in specific module e.g. entity_creature

 ***************************************************/
#include "entity.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <adt/p_forward_list.h> // linked list
#include <stdio.h>
#include <stdlib.h>

#include "dungeon_map.h"
#include "entity_creature.h"
#include "entity_item.h"
#include "dice.h"
#include "messages.h"


/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/
// Single linked list of all entities
static p_forward_list_t entities;

/***************************************************
 * function definitions
 ***************************************************/

void entity_init()
{
    p_forward_list_init(&entities);      // init entities p_forward_list
}

entity_t *entity_create_creature(uint8_t x, uint8_t y, creature_type_t c_type)
{
    entity_t *entity_ptr;
    //TODO validate inputs

    //TODO check for NULL
    // create creature
    creature_t *creature_ptr = entity_creature_create(c_type);

    // create entity of type creature
    entity_ptr = entity_create(x, y, creature_ptr->tile, creature_ptr->tile_attr,creature_ptr->blocking, creature, creature_ptr, NULL);
    
    return entity_ptr;
}

entity_t *entity_create_item(uint8_t x, uint8_t y, item_type_t i_type)
{
    entity_t *entity_ptr;
    //TODO validate inputs

    //TODO check for NULL
    // create item
    item_t *item_ptr = entity_item_create(i_type);

    // create entity of type item
    entity_ptr = entity_create(x, y, item_ptr->tile, item_ptr->tile_attr, item_ptr->blocking, item, NULL, item_ptr);
    
    return entity_ptr;
}

entity_t *entity_create(uint8_t x, uint8_t y, uint8_t tile, uint8_t tile_attr, uint8_t blocking, entity_type_t type, creature_t *creature_ptr, item_t *item_ptr)
{
    //TODO validate inputs

    entity_t *entity_ptr = (entity_t *) malloc(sizeof(entity_t));
    //TODO check for NULL

    entity_ptr->x = x;
    entity_ptr->y = y;
    entity_ptr->tile=tile;
    entity_ptr->tile_attr=tile_attr;
    entity_ptr->blocking=blocking;
    entity_ptr->type = type;
    entity_ptr->creature_ptr = creature_ptr;
    entity_ptr->item_ptr = item_ptr;

    entity_ptr->current_energy = 0;

    p_forward_list_push_front(&entities, entity_ptr);

    return entity_ptr;
}

void entity_delete_entity(entity_t *entity_ptr)
{
    dungeon_map_draw_tile(entity_ptr->x, entity_ptr->y);

    p_forward_list_remove(&entities, entity_ptr);

    if (entity_ptr->creature_ptr)
    {
        entity_creature_delete(entity_ptr->creature_ptr);
        entity_ptr->creature_ptr = NULL;
    }

    if (entity_ptr->item_ptr)
    {
        //entity_item_delete(entity_ptr->item_ptr);
        entity_ptr->item_ptr = NULL;
    }
    free(entity_ptr);
}

entity_t *entity_front()
{
    return p_forward_list_front(&entities);
}

entity_t *entity_next(entity_t *entity_ptr)
{
    return p_forward_list_next(entity_ptr);
}

uint8_t entity_move_or_strike(entity_t *entity_ptr, int8_t dx, int8_t dy)
{
    if (!entity_move(entity_ptr, dx, dy))
    {
        return (strike(entity_ptr, dx, dy));
    }
    return 1;
}

uint8_t entity_move(entity_t *entity_ptr, int8_t dx, int8_t dy)
{
    uint8_t effort;

    if (dungeon_map_is_square_empty(entity_ptr->x+dx, entity_ptr->y+dy)) {
        // redraw dungeon tile
        dungeon_map_draw_tile(entity_ptr->x, entity_ptr->y);
        entity_ptr->y +=dy;
        entity_ptr->x +=dx;

        // decrease entity energy by 10 - speed. 
        effort = (10 - entity_ptr->creature_ptr->speed);
        entity_ptr->current_energy = entity_ptr->current_energy - effort;
        return 1;
    }
    return 0;
}

uint8_t strike(entity_t *attacker_entity_ptr, int8_t dx, int8_t dy)
{
    entity_t *target_entity_ptr = entity_first_at( attacker_entity_ptr->x+dx, attacker_entity_ptr->y+dy );

    uint8_t attack_roll;
    uint8_t dmg_roll;

    char message[21];
  

    while (target_entity_ptr != NULL)
    {
        if (target_entity_ptr->type == creature) {
            // decrease energy by speed
            attacker_entity_ptr->current_energy = (10 - attacker_entity_ptr->creature_ptr->speed) ;

            // attack roll
            attack_roll = dice_roll_1d20();

            // 012345678901234567890123456789
            // AAAAAAAAAA strikes TTTTTTTTTT
            sprintf(message, "%s strikes %s\n", attacker_entity_ptr->creature_ptr->name, target_entity_ptr->creature_ptr->name);
            messages_print(message);

            // Sucessful hit?
            if (attack_roll > target_entity_ptr->creature_ptr->ac)
            {
                // todo roll for damage
                dmg_roll = dice_roll(attacker_entity_ptr->creature_ptr->dmg_die_p);
                target_entity_ptr->creature_ptr->curr_hp -= dmg_roll;

                // 012345678901234567890123456789
                // DD points damage
                sprintf(message, "%u points damage\n", dmg_roll);
                messages_print(message);

                // Is target dead?
                if (target_entity_ptr->creature_ptr->curr_hp <= 0)
                {
                    // 012345678901234567890123456789
                    // TTTTTTTTTT is killed!
                    sprintf(message, "%s is killed!\n", target_entity_ptr->creature_ptr->name);
                    messages_print(message);

                    entity_delete_entity(target_entity_ptr);
                }
                else
                {
                    // todo entity_event_hit();
                }
            }
            else
            {
                // Miss!
                sprintf(message, "%s misses\n", attacker_entity_ptr->creature_ptr->name);
                messages_print(message);
                return 1;
            }

        }
        target_entity_ptr = entity_next_at( attacker_entity_ptr->x+dx, attacker_entity_ptr->y+dy, target_entity_ptr );
    } 
    return 0;
}


void entity_draw_all()
{
    entity_t *entity_ptr;

    // print entities
    for (entity_ptr = p_forward_list_front(&entities); entity_ptr; entity_ptr = p_forward_list_next(entity_ptr))
    {
        dungeon_map_draw_entity(entity_ptr->x, entity_ptr->y, entity_ptr->tile, entity_ptr->tile_attr);
    }
}

uint8_t entity_passable(uint8_t y, uint8_t x)
{
    entity_t *entity_ptr;

    // Does a unpassable entity occupy square
    for (entity_ptr = p_forward_list_front(&entities); entity_ptr; entity_ptr = p_forward_list_next(entity_ptr))
    {
        if (entity_ptr->y == y && entity_ptr->x == x && entity_ptr->blocking == 1) {
            return 0;
        }
    }
    return 1;
}

entity_t *entity_first_at(uint8_t x, uint8_t y)
{
    entity_t *entity_ptr = entity_front();

    while ( entity_ptr)
    {
        if (entity_ptr->x == x && entity_ptr->y == y) {
            return entity_ptr;
        }
        entity_ptr = entity_next(entity_ptr);
    }
    return NULL; 
}

entity_t* entity_next_at(uint8_t x, uint8_t y, entity_t *entity_ptr)
{
    while( entity_ptr = entity_next(entity_ptr) )
    {
        if (entity_ptr->x == x && entity_ptr->y == y) {
            return entity_ptr;
        }
    }
    return NULL;
}



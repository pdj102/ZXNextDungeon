/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    Creature entity pickup action

 ***************************************************/
#include "entity_creature_pickup.h"

#include <inttypes.h>

#include "entity.h"
#include "entity_item.h"
#include "entity_creature.h"
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


/***************************************************
 * function definitions
 ***************************************************/


uint8_t entity_creature_pickup(creature_t *creature_ptr)
{
    item_t *item;

    item = entity_item_at(creature_ptr->entity_ptr->x, creature_ptr->entity_ptr->y);

    if (item)
    {
        // pickup item
        messages_print("PICKED UP ");
        messages_println(item->name);

        
        item->entity_ptr->location = PLAYER;
        item->entity_ptr->x = 255;
        item->entity_ptr->y = 255;
        
        return 1;
    }
    
    return 0;
}

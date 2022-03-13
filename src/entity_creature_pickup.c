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
 * private variables - static
 ***************************************************/


/***************************************************
 * function definitions
 ***************************************************/


uint8_t entity_creature_pickup(creature_t *creature_ptr)
{
    entity_item_t *item_ptr;

    item_ptr = entity_item_first_at(creature_ptr->entity_ptr->x, creature_ptr->entity_ptr->y);

    if (item_ptr)
    {
        // pickup item
        messages_print("PICKED UP ");
        messages_println(item_ptr->name);

        
        item_ptr->entity_ptr->location = inventory;
        item_ptr->entity_ptr->x = 255;
        item_ptr->entity_ptr->y = 255;
        
        return 1;
    }
    messages_println("NO ITEM");
    
    return 0;
}

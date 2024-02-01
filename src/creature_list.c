/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon list of creatures

**************************************************/

#include <stdint.h>
#include <adt/p_forward_list.h>

#include "text.h"

#include "creature.h"

#include "globaldata.h"

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

void creature_list_init( void )
{
    p_forward_list_init(&globaldata.creature_list);
}

void creature_list_add(creature_t *creature_p)
{
    p_forward_list_push_front(&globaldata.creature_list, creature_p);
}

uint8_t creature_list_remove(creature_t *creature_p)
{
    p_forward_list_remove(&globaldata.creature_list, creature_p);
    return 1;
}

creature_t *creature_list_first( void )
{
    return p_forward_list_front(&globaldata.creature_list);
}

creature_t *creature_list_next(creature_t *creature_p)
{
    return p_forward_list_next(creature_p);
}

creature_t *creature_list_first_at(uint8_t x, uint8_t y)
{
    creature_t *creature_p;

    for (creature_p = creature_list_first(); creature_p; creature_p = creature_list_next(creature_p))
    {
        if (creature_p->obj_p->x == x && creature_p->obj_p->y == y)
        {
            return creature_p;
        }
    }
    return 0;
}

creature_t *creature_list_next_at(creature_t *creature_p, uint8_t x, uint8_t y)
{
    while (creature_p = creature_list_next(creature_p))
    {
        if (creature_p->obj_p->x == x && creature_p->obj_p->y == y)
        {
            return creature_p;
        }
    }
    return 0;
}

creature_t *creature_list_first_within_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    creature_t *creature_p;

    for (creature_p = creature_list_first(); creature_p; creature_p = creature_list_next(creature_p))
    {
        if ((creature_p->obj_p->x >= x1 && creature_p->obj_p->x <= x2) &&
            (creature_p->obj_p->y >= y1 && creature_p->obj_p->y <= y2))
        {
            return creature_p;
        }
    }
    return 0;
}

creature_t *creature_list_next_within_rect(creature_t *creature_p, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    while (creature_p = creature_list_next(creature_p))
    {
        if ((creature_p->obj_p->x >= x1 && creature_p->obj_p->x <= x2) &&
            (creature_p->obj_p->y >= y1 && creature_p->obj_p->y <= y2))
        {
            return creature_p;
        }
    }
    return 0;
}


// TODO3 - change is_a to work on creatures
creature_t *creature_list_first_is_a_at(uint8_t x, uint8_t y, object_is_a is_a_p)
{
    creature_t *creature_p = creature_list_first_at(x, y);

    while( creature_p )
    {
        if (is_a_p(creature_p->obj_p))
        {
            return creature_p;
        }
        creature_p = creature_list_next_at(creature_p, x, y);
    }
    return 0;
}


// TODO3 - change is_a to work on creatures
creature_t *creature_list_next_is_a_at(creature_t *creature_p, uint8_t x, uint8_t y, object_is_a is_a_p)
{
    while ( creature_p = creature_list_next_at(creature_p, x, y) )
    {
        if (is_a_p(creature_p->obj_p))
        {
            return creature_p;
        }
    }
    return 0;
}

creature_t *creature_list_first_is_a_within_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_is_a is_a_p)
{
    creature_t *creature_p = creature_list_first_within_rect(x1, y1, x2, y2);

    while( creature_p )
    {
        if (is_a_p(creature_p))
        {
            return creature_p;
        }
        creature_p = creature_list_next_within_rect(creature_p, x1, y1, x2, y2);
    }
    return 0;
}

creature_t *creature_list_next_is_a_within_rect(creature_t *creature_p, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_is_a is_a_p)
{
    while ( creature_p = creature_list_next_within_rect(creature_p, x1, y1, x2, y2) )
    {
        if (is_a_p(creature_p))
        {
            return creature_p;
        }
    }
    return 0;
}

creature_t *creature_list_first_is_a2_within_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_t *agent_p, creature_is_a2 is_a2_p)
{
    creature_t *creature_p = creature_list_first_within_rect(x1, y1, x2, y2);

    while( creature_p )
    {
        if (is_a2_p(agent_p, creature_p))
        {
            return creature_p;
        }
        creature_p = creature_list_next_within_rect(creature_p, x1, y1, x2, y2);
    }
    return 0;
}

creature_t *creature_list_next_is_a2_within_rect(creature_t *creature_p, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, creature_t *agent_p, creature_is_a2 is_a2_p)
{
    while ( creature_p = creature_list_next_within_rect(creature_p, x1, y1, x2, y2) )
    {
        if (is_a2_p(agent_p, creature_p))
        {
            return creature_p;
        }
    }
    return 0;
}

void creature_list_update_all( void )
{
    creature_t *creature_p;
    
    for (creature_p = p_forward_list_front(&globaldata.creature_list); creature_p; creature_p = p_forward_list_next(creature_p))
    {
        creature_turn(creature_p);
    }    
}


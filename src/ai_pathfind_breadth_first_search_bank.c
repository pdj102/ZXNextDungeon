/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding - breadth first search

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_pathfind_breadth_first_search_bank.h"

#include <stdint.h>

#include "ai_pathfind_bank.h"

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"
#include "text_token.h"


#define MAX_SIZE   100

/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
static void push_frontier_b(coord_t *coord);
static uint8_t pop_frontier_b(coord_t *coord); 
static uint8_t get_next_neighbor_coord_b(coord_t *current, coord_t *next, direction_t *direction_from);
static uint8_t get_next_neighbor_b(coord_t* current, coord_t *next, direction_t *direction_from);

/***************************************************
 * private variables - static
 ***************************************************/
// variables are defined in ai_pathfind_data.asm
extern coord_t frontier[MAX_SIZE];

extern uint8_t frontier_head;
extern uint8_t frontier_tail;
extern uint8_t frontier_count;
extern uint8_t neighbor;
extern uint8_t max_x;
extern uint8_t min_x;
extern uint8_t max_y;
extern uint8_t min_y;

/***************************************************
 * functions
 ***************************************************/

void ai_pathfind_breadth_first_search_b(uint8_t x, uint8_t y)
{
    coord_t current;
    coord_t next;
    direction_t direction_from = NO_DIR;
 
    frontier_head = 0;
    frontier_tail = 0;
    frontier_count = 0;

    next.x = x;
    next.y = y;

    // Limit the bounds of the path finding to a maximum of 10 x 10 squares around the player
    if (x<10) { min_x = 0; } else { min_x = x - 10; }
    if (x> DUNGEONMAP_WIDTH - 1 - 10) { max_x = DUNGEONMAP_WIDTH - 1; } else { max_x = x + 10; }
    if (y<10) { min_y = 0; } else { min_y = y - 10; }
    if (y> DUNGEONMAP_HEIGHT - 1 - 10) { max_y = DUNGEONMAP_HEIGHT - 1; } else { max_y = y + 10; }

    // clear previous path information (currently only within limits of new path)
    // todo - faster to memcopy 0 over the array?
    for(x = min_x; x < max_x; x++)
    {
        for (y = min_y; y < max_y; y++)
        {
            reached[x][y].reached = 0;
            reached[x][y].reached_from = NO_DIR;
        }
    }



    push_frontier_b(&next);

    mark_reached_b(&next, direction_from);

    while(pop_frontier_b(&current))
    {
        neighbor = 0;
        // TODO add limit to depth of search 
        // TODO handle blocking objects (object mark map?)
        // TODO Intelligent vs non-intelligent can open doors so not blocked

        while (get_next_neighbor_b(&current, &next, &direction_from))  
        {
                             
            if(!is_reached_b(&next))
            {
                push_frontier_b(&next);
                mark_reached_b(&next, direction_from);           
            }
        }
    } 
}

void push_frontier_b(coord_t *coord)
{
    if (frontier_count == MAX_SIZE)
    {
        return;
    }

    frontier[frontier_head].x = coord->x;
    frontier[frontier_head].y = coord->y;
    frontier_head++;
    frontier_count++;
    if (frontier_head == MAX_SIZE)
    {
        frontier_head = 0;
    }
}

uint8_t pop_frontier_b(coord_t *coord)
{
    if (frontier_count == 0)
    {   
        return 0;
    }
    
    coord->x = frontier[frontier_tail].x;
    coord->y = frontier[frontier_tail].y;
    frontier_tail++;
    frontier_count--;    

    if (frontier_tail == MAX_SIZE)
    {
        frontier_tail = 0;
    }

    return 1;
}


uint8_t get_next_neighbor_b(coord_t* current, coord_t *next, direction_t *direction_from)
{
    uint8_t blocked;
    
    while (get_next_neighbor_coord_b(current, next, direction_from) )
    // while there is another neighbour
    {
        // is it blocked?
        blocked = dungeonmap_tile_is_blocked(next->x, next->y);
        if (!blocked) {
            // not blocked return it
            return 1;
        }
    };

    // no more neighbours
    return 0;
}

uint8_t get_next_neighbor_coord_b(coord_t *current, coord_t *next, direction_t *direction_from)
{
    next->x = current->x;
    next->y = current->y;

    // down
    if (neighbor == 0)
    {
        if (next->y+1 < max_y)
        {
            next->y++;
            *direction_from = N;
        }
        neighbor++;
        return 1;
    } else if (neighbor == 1)
    // right
    {
        if (next->x+1 < max_x)
        {
            next->x++;
            *direction_from = W;            
        }
        neighbor++;
        return 1;
    } else if (neighbor == 2)
    // up
    {
        if (next->y-1 >= min_y)
        {
            next->y--;
            *direction_from = S;              
        }
        neighbor++; 
        return 1;       
    } else if (neighbor == 3)
    // left
    {
        if (next->x-1 >= min_x)
        {
            next->x--;
            *direction_from = E;           
        }
        neighbor++;
        return 1;
    } else 
    // no more neighbors
    {
        // messages_println("NO MORE NEIGHBORS");
        return 0;
    }
}

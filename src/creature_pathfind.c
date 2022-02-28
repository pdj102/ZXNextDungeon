/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   Creature pathfinder

 ***************************************************/
#include "creature_pathfind.h"

#include <inttypes.h>           
#include <stdlib.h>             // rand()

#include "dungeon_map.h"
#include "tile_defns.h"
#include "messages.h"

#include <input.h>      //  in_WaitForKey()
        

#pragma output CRT_ORG_CODE = 0xC000

/***************************************************
 * types
 ***************************************************/


typedef struct
{
    uint8_t x;
    uint8_t y;
} coord_t;

typedef struct
{
    uint8_t reached;
} path_t;





/***************************************************
 * function prototypes
 ***************************************************/

static void push_frontier(coord_t *coord);
static uint8_t pop_frontier(coord_t *coord); 
static void mark_reached(coord_t *coord);
static uint8_t is_reached(coord_t *coord);
static uint8_t get_next_neighbor_coord(coord_t *current, coord_t *next);
static uint8_t get_next_neighbor(coord_t* current, coord_t *next);

/***************************************************
 * variables
 ***************************************************/

// variables are defined in creature_pathfind_data.asm
extern coord_t frontier[100];
extern path_t reached[10][10];
extern uint8_t frontier_pos;
extern uint8_t x_offset;
extern uint8_t y_offset;
extern uint8_t neighbor;

/***************************************************
 * functions
 ***************************************************/

void creature_pathfind(uint8_t x, uint8_t y)
{
    coord_t current;
    coord_t next;
 
    frontier_pos = 0;

    next.x = x;
    next.y = y;

    x_offset = x;
    y_offset = y;

    for(x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            reached[x][y].reached = 0;
        }
    }

    push_frontier(&next);

    mark_reached(&next);

    while(pop_frontier(&current))
    {
        neighbor = 0;
        // TO DO add from so path can be determined
        // TO DO add limit to depth of search 
        // TO DO move reached flag to the dungeon array
        while (get_next_neighbor(&current, &next))  
        {
                // messages_print_s_uint8("X", next.x);
                // messages_print_s_uint8("Y", next.y);
                               
            if(!is_reached(&next))
            {
                push_frontier(&next);
                mark_reached(&next);
                dungeon_map[next.x][next.y].tile_defn_graphic = TILE_8_0;
            }
        }
    }

    // in_wait_nokey();
    // in_wait_key();
}


void push_frontier(coord_t *coord)
{
    if (frontier_pos < sizeof(frontier))
    {
        frontier[frontier_pos].x = coord->x;
        frontier[frontier_pos].y = coord->y;
        frontier_pos++;
        messages_print_s_uint8("PUSH", frontier_pos);
    }
}

uint8_t pop_frontier(coord_t *coord)
{
    if (frontier_pos == 0) return 0;

    frontier_pos--;
    coord->x = frontier[frontier_pos].x;
    coord->y = frontier[frontier_pos].y;
    // messages_println("POP");

    return 1;
}

void mark_reached(coord_t *coord)
{
    int8_t x;
    int8_t y;

    x = coord->x - x_offset + 5;
    y = coord->y - y_offset + 5;

    reached[x][y].reached = 1 ;
}

uint8_t is_reached(coord_t *coord)
{
    int8_t x;
    int8_t y;

    x = coord->x - x_offset + 5;
    y = coord->y - y_offset + 5;

    return ( reached[x][y].reached );
}

uint8_t get_next_neighbor(coord_t* current, coord_t *next)
{
    uint8_t blocked;
    
    while (get_next_neighbor_coord(current, next) )
    // while there is another neighbour
    {
        // is it blocked?
        blocked = dungeon_map_is_blocked(next->x, next->y);
        if (!blocked) {
            // not blocked return it
            return 1;
        }
    };

    // no more neighbours
    return 0;
}

uint8_t get_next_neighbor_coord(coord_t *current, coord_t *next)
{
    next->x = current->x;
    next->y = current->y;

    // up
    if (neighbor == 0)
    {
        if (next->y+1 < DUNGEON_MAP_HEIGHT)
        {
            next->y++;
        }
        neighbor++;
        return 1;
    } else if (neighbor == 1)
    // right
    {
        if (next->x+1 < DUNGEON_MAP_WIDTH)
        {
            next->x++;
        }
        neighbor++;
        return 1;
    } else if (neighbor == 2)
    // down
    {
        if (next->y-1 >= 0)
        {
            next->y--;
        }
        neighbor++; 
        return 1;       
    } else if (neighbor == 3)
    // left
    {
        if (next->x-1 >= 0)
        {
            next->x--;
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

/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_pathfind_bank.h"

#include <stdint.h>

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"
#include "text_token.h"


#define FRONTIER_SIZE   100

/***************************************************
 * private types
 ***************************************************/
typedef struct
{
    uint8_t reached;
    direction_t reached_from;
} path_t;

/***************************************************
 * private function prototypes
 ***************************************************/
static void push_frontier_b(coord_t *coord);
static uint8_t pop_frontier_b(coord_t *coord); 
static void mark_reached_b(coord_t *coord, direction_t direction_from);
static uint8_t is_reached_b(coord_t *coord);
static uint8_t get_next_neighbor_coord_b(coord_t *current, coord_t *next, direction_t *direction_from);
static uint8_t get_next_neighbor_b(coord_t* current, coord_t *next, direction_t *direction_from);

/***************************************************
 * private variables - static
 ***************************************************/
// variables are defined in creature_pathfind_data.asm
extern coord_t frontier[FRONTIER_SIZE];
extern path_t reached[40][40];
extern uint8_t frontier_head;
extern uint8_t frontier_tail;
extern uint8_t frontier_count;
extern uint8_t x_offset;
extern uint8_t y_offset;
extern uint8_t neighbor;
extern uint8_t max_x;
extern uint8_t min_x;
extern uint8_t max_y;
extern uint8_t min_y;

/***************************************************
 * functions
 ***************************************************/

void ai_pathfind_b(uint8_t x, uint8_t y)
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
    if (x> DUNGEONMAP_WIDTH - 10) { max_x = DUNGEONMAP_WIDTH; } else { max_x = x + 10; }
    if (y<10) { min_y = 0; } else { min_y = y - 10; }
    if (y> DUNGEONMAP_HEIGHT - 10) { max_y = DUNGEONMAP_HEIGHT; } else { max_y = y + 10; }

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

void ai_pathfind_print_b( void )
{
    uint8_t x;
    uint8_t y;
    direction_t direction_from;

    for(x = 0; x < 40; x++)
    {
        for (y = 0; y < 40; y++)
        {
                direction_from = ai_pathfind_direction_to_player_b(x, y);

                switch (direction_from)
                {
                case N:
                     text_print_char_at(x, y, 'N');
                    break;
                case S:
                     text_print_char_at(x, y, 'S');
                    break;
                case W:
                     text_print_char_at(x, y, 'W');
                    break;
                case E:
                     text_print_char_at(x, y, 'E');
                    break;                                                            
                
                default:
                    text_print_char_at(x, y, ' ');
                    break;
                }

        }
    }  
}

direction_t ai_pathfind_direction_to_player_b(uint8_t x, uint8_t y)
{
    return (reached[x][y].reached_from);
}


void push_frontier_b(coord_t *coord)
{
    if (frontier_count == FRONTIER_SIZE)
    {
        return;
    }

    frontier[frontier_head].x = coord->x;
    frontier[frontier_head].y = coord->y;
    frontier_head++;
    frontier_count++;
    if (frontier_head == FRONTIER_SIZE)
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

    if (frontier_tail == FRONTIER_SIZE)
    {
        frontier_tail = 0;
    }

    return 1;
}

void mark_reached_b(coord_t *coord, direction_t direction_from)
{
    reached[coord->x][coord->y].reached = 1 ;
    reached[coord->x][coord->y].reached_from = direction_from;
}

uint8_t is_reached_b(coord_t *coord)
{
    return ( reached[coord->x][coord->y].reached );
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

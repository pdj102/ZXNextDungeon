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

    for(x = 0; x < 40; x++)
    {
        for (y = 0; y < 40; y++)
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
        // TO DO add limit to depth of search 
        // TO DO creatures will not avoid each other. We need to treat a square with a monster on it as passable otherwise the creature cannot move
        // TO DO implement A* so creatures can avoid each other. Also we can open doors if intelligent etc passing in params to path calculator

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
    coord_t next;

    for(x = 0; x < 40; x++)
    {
        for (y = 0; y < 40; y++)
        {
                next.x = x;
                next.y = y;
                direction_from = ai_pathfind_direction_to_player_b(&next);

                switch (direction_from)
                {
                case N:
                     text_print_char_at(next.x, next.y, 'N');
                    break;
                case S:
                     text_print_char_at(next.x, next.y, 'S');
                    break;
                case W:
                     text_print_char_at(next.x, next.y, 'W');
                    break;
                case E:
                     text_print_char_at(next.x, next.y, 'E');
                    break;                                                            
                
                default:
                    text_print_char_at(next.x, next.y, ' ');
                    break;
                }

        }
    }  
}

direction_t ai_pathfind_direction_to_player_b(const coord_t *coord)
{
    //messages_print_s_int8("PATHDIR", reached[coord->x][coord->y].reached_from);
    return (reached[coord->x][coord->y].reached_from);
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

    // up
    if (neighbor == 0)
    {
        if (next->y+1 < DUNGEONMAP_HEIGHT)
        {
            next->y++;
            *direction_from = N;
        }
        neighbor++;
        return 1;
    } else if (neighbor == 1)
    // right
    {
        if (next->x+1 < DUNGEONMAP_WIDTH)
        {
            next->x++;
            *direction_from = W;            
        }
        neighbor++;
        return 1;
    } else if (neighbor == 2)
    // down
    {
        if (next->y-1 >= 0)
        {
            next->y--;
            *direction_from = S;              
        }
        neighbor++; 
        return 1;       
    } else if (neighbor == 3)
    // left
    {
        if (next->x-1 >= 0)
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

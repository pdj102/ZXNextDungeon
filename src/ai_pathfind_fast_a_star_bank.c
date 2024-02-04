/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding - fast a star

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_pathfind_fast_a_star_bank.h"

#include <stdint.h>
#include <input.h>              // Functions for Reading Keyboards, Joysticks and Mice

#include "ai_bank.h"            // manhattan
#include "ai_pathfind_bank.h"

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"


#define MAX_SIZE   10
#define MAX_PRIORITY    20

/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
static void push_frontier_b(coord_t *coord, uint8_t priority);
static uint8_t pop_frontier_b(coord_t *coord);
static void update_neighbors_b(coord_t *coord);

/***************************************************
 * private variables - static
 ***************************************************/
// use static variables for performance - variables are defined in ai_pathfind_data.asm

extern coord_t priority_queue[MAX_SIZE][MAX_PRIORITY];
extern uint8_t queue_head[MAX_PRIORITY];
extern uint8_t queue_tail[MAX_PRIORITY];
extern uint8_t queue_count[MAX_PRIORITY];

extern coord_t start_coord;
extern coord_t goal_coord;
extern coord_t current_coord;
extern coord_t tmp_coord;


extern uint8_t max_x;
extern uint8_t min_x;
extern uint8_t max_y;
extern uint8_t min_y;

extern uint8_t tail_priority;

/***************************************************
 * functions
 ***************************************************/

void ai_pathfind_fast_a_star_b(uint8_t x, uint8_t y, uint8_t goal_x, uint8_t goal_y)
{

    direction_t direction_from;
    unsigned int key;

    goal_coord.x = goal_x;
    goal_coord.y = goal_y;
    start_coord.x = x;
    start_coord.y = y;

    current_coord.x = x;
    current_coord.y = y;
    direction_from = NO_DIR;

    tail_priority = 0;

    for (uint8_t priority = 0; priority < MAX_PRIORITY; priority++)
    {
        queue_count[priority] = 0;
        queue_head[priority] = 0;
        queue_tail[priority] = 0;
    }

    // Limit the bounds of the path finding to a maximum of 10 x 10 squares around the player
    if (x<10) { min_x = 0; } else { min_x = x - 10; }
    if (x> DUNGEONMAP_WIDTH - 1 - 10) { max_x = DUNGEONMAP_WIDTH - 1; } else { max_x = x + 10; }
    if (y<10) { min_y = 0; } else { min_y = y - 10; }
    if (y> DUNGEONMAP_HEIGHT - 1 - 10) { max_y = DUNGEONMAP_HEIGHT - 1; } else { max_y = y + 10; }

    // clear previous path information (current_coordly only within limits of new path)
    // todo - faster to memcopy 0 over the array?
    for(x = min_x; x < max_x; x++)
    {
        for (y = min_y; y < max_y; y++)
        {
            reached[x][y].reached = 0;
            reached[x][y].reached_from = NO_DIR;
        }
    }

    text_printf("A* %u,", (unsigned char) start_coord.x);
    text_printf("%u ", (unsigned char) start_coord.y);
    text_printf("%u,", (unsigned char) goal_coord.x);
    text_printf("%u\n", (unsigned char) goal_coord.y);




    push_frontier_b(&current_coord, 0);
    mark_reached_b(&current_coord, direction_from);

    while(pop_frontier_b(&current_coord))
    {
        // TODO handle blocking objects (object mark map?)
        // TODO Intelligent vs non-intelligent can open doors so not blocked

        if (current_coord.x == goal_coord.x && current_coord.y == goal_coord.y)
        {
            break;
        }

        update_neighbors_b(&current_coord);

        ai_pathfind_print_b();
        while ((key = in_inkey()) == 0) ;   // loop while no key pressed
        in_wait_nokey();    // wait no key  
    } 
}

void push_frontier_b(coord_t *coord, uint8_t priority)
{
    uint8_t head;

    // Do not push if  priority is greater or equal to max priority
    if (priority >= MAX_PRIORITY)
    {
        text_printf("DEBUG - Priority exceeds bounds");
        return;
    }
    
    // Do not push if queue[priority] is full
    if (queue_count[priority] == MAX_SIZE)
    {
        text_printf("DEBUG - queue is full");
        return;
    }

    head = queue_head[priority];

    // push onto priority queue
    priority_queue[head][priority].x = coord->x;
    priority_queue[head][priority].y = coord->y;

    queue_head[priority]++;
    queue_count[priority]++;

    text_printf("Push %u,", (unsigned char) coord->x);
    text_printf("%u ", (unsigned char) coord->y);
    text_printf("p:%u\n", (unsigned char) priority);

    // if head has reached end of array wrap to 0
    if (queue_head[priority] == MAX_SIZE)
    {
        queue_head[priority] = 0;
    }

    // set tail_priority to priority if lower 
    if (priority < tail_priority)
    {
        tail_priority = priority;
    }
}

uint8_t pop_frontier_b(coord_t *coord)
{
    uint8_t tail; 

    // if no more entiries in tail_queue find next priority queue with an entry
    while (queue_count[tail_priority] == 0)
    {
        tail_priority++;
        if (tail_priority == MAX_PRIORITY)
        {
            // if reached max priority queue there are no more entries 
            return 0;
        }
    }
    
    tail = queue_tail[tail_priority];

    // pop entry from tail queue
    coord->x = priority_queue[tail][tail_priority].x;
    coord->y = priority_queue[tail][tail_priority].y;

    text_printf("Pop  %u,", (unsigned char) coord->x);
    text_printf("%u ", (unsigned char) coord->y);
    text_printf("p:%u\n", (unsigned char) tail_priority);

    queue_tail[tail_priority]++;
    queue_count[tail_priority]--;  

    // if tail has reached end of array wrap to 0
    if (queue_tail[tail_priority] == MAX_SIZE)
    {
        queue_tail[tail_priority] = 0;
    }

    return 1;
}


void update_neighbors_b(coord_t *coord)
{
    uint8_t cost;

    // north
    tmp_coord.x = coord->x;
    tmp_coord.y = (coord->y > min_y) ? coord->y - 1 : min_y;

    if (!is_reached_b(&tmp_coord))
    {
        cost = distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        push_frontier_b(&tmp_coord, cost);
        mark_reached_b(&tmp_coord, S);  
    }

    // south
    tmp_coord.x = coord->x;
    tmp_coord.y = (coord->y < max_y) ? coord->y + 1 : max_y;

    if (!is_reached_b(&tmp_coord))
    {
        cost = distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        push_frontier_b(&tmp_coord, cost);
        mark_reached_b(&tmp_coord, N);  
    }

    // west
    tmp_coord.x = (coord->x > min_x) ? coord->x - 1 : min_x;
    tmp_coord.y = coord->y;

    if (!is_reached_b(&tmp_coord))
    {
        cost = distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        push_frontier_b(&tmp_coord, cost);
        mark_reached_b(&tmp_coord, E);  
    }    

    // east
    tmp_coord.x = (coord->x < max_x) ? coord->x + 1 : max_x;
    tmp_coord.y = coord->y;

    if (!is_reached_b(&tmp_coord))
    {
        cost = distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        push_frontier_b(&tmp_coord, cost);
        mark_reached_b(&tmp_coord, W);  
    }        
}
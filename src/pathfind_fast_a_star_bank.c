/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding - fast a star

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "pathfind_fast_a_star_bank.h"

#include <stdint.h>
#include <input.h>              // Functions for Reading Keyboards, Joysticks and Mice

#include "pathfind_bank.h"

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"
#include "util.h"


#define MAX_SIZE        20
#define MAX_PRIORITY    30

/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
static void init_priority_queue( void );
static void push_frontier_b(coord_t *coord, uint8_t priority);
static uint8_t pop_frontier_head_b(coord_t *coord);
static uint8_t pop_frontier_tail_b(coord_t *coord);
static void update_neighbors_b( void );
static void update_tile_b(void);

/***************************************************
 * private variables - static
 ***************************************************/
// use static variables for performance - variables are defined in pathfind_data.asm

extern coord_t priority_queue[MAX_SIZE][MAX_PRIORITY];
extern uint8_t queue_head[MAX_PRIORITY];
extern uint8_t queue_tail[MAX_PRIORITY];
extern uint8_t queue_count[MAX_PRIORITY];

extern coord_t start_coord;
extern coord_t goal_coord;
extern coord_t current_coord;
extern coord_t tmp_coord;
extern direction_t tmp_dir;

extern uint8_t     tmp_cost_so_far;
extern uint8_t     tmp_total_cost;

extern uint8_t max_x;
extern uint8_t min_x;
extern uint8_t max_y;
extern uint8_t min_y;

extern uint8_t tail_priority;
extern uint8_t priority_offset;

/***************************************************
 * functions
 ***************************************************/

uint8_t pathfind_fast_a_star_b(uint8_t origin_x, uint8_t origin_y, uint8_t goal_x, uint8_t goal_y)
{
    direction_t direction_from;

    uint8_t x, y;

    #ifdef DEBUG_PATHFIND  
    text_printf("A* origin: %u ", origin_x);
    text_printf("%u ", origin_y);
    text_printf("goal: %u ", goal_x);
    text_printf("%u ", goal_y);
    #endif

    // flip origin and goal around as the resultant path is walked backwards
    goal_coord.x = origin_x;
    goal_coord.y = origin_y;
    start_coord.x = goal_x;
    start_coord.y = goal_y;

    // set current coord to start of path. Direction to start is NO_DIR  
    current_coord.x = start_coord.x;
    current_coord.y = start_coord.y;
    direction_from = NO_DIR;

    init_priority_queue();

    min_x = 0;
    max_x = DUNGEONMAP_WIDTH;
    min_y = 0;
    max_y = DUNGEONMAP_HEIGHT;

    // clear previous path information 
    // todo - faster to memcopy 0 over the array?
    for(x = min_x; x < max_x; x++)
    {
        for (y = min_y; y < max_y; y++)
        {
            reached[x][y].cost_so_far = 0;
            reached[x][y].total_cost = 255;
            reached[x][y].reached_from = NO_DIR;
        }
    }

    // calculate initial costs
    tmp_cost_so_far = 0;
    tmp_total_cost = tmp_cost_so_far + util_distance_manhattan(start_coord.x, start_coord.y, goal_coord.x, goal_coord.y);

    // set queue prioirty offet. Priority will only ever be equal or greater to this
    priority_offset = tmp_total_cost;

    // push start coord onto froniter queue
    push_frontier_b(&current_coord, 0);
    pathfind_mark_reached_b(&current_coord, direction_from, tmp_total_cost, tmp_cost_so_far);

    // while there are more coords in the froniter queue to explore
    while(pop_frontier_head_b(&current_coord))
    {
        // TODO handle blocking objects (object mark map?)
        // TODO Intelligent vs non-intelligent can open doors so not blocked

        // Have we reached the goal coord?
        if (current_coord.x == goal_coord.x && current_coord.y == goal_coord.y)
        {
            #ifdef DEBUG_PATHFIND 
                text_printf("path found\n");
            #endif

            return 1;
        }
        update_neighbors_b();
    } 

    // did not find a path to goal
    #ifdef DEBUG_PATHFIND  
        text_printf("path NOT found\n");
    #endif
    
    return 0;   
}

/**
 * @brief bounded priority queue
 * 
 * A fast bounded priority queue
 * 
 * The priority queue is built from a fixed number of queues
 * Each queue is consists of a fixed array of MAX_SIZE and represents a priority
 * Maximum priority is bounded by the number of queues MAX_PRIORITY
 * Head is the index of the next empty slot in the queue
 * Tail is the index of the tail entry in the queue
 * Count equals the number of enteries in the queue
 * Queue grows in the positive direction
 */

void init_priority_queue( void )
{
    tail_priority = 0;
    for (uint8_t priority = 0; priority < MAX_PRIORITY; priority++)
    {
        queue_count[priority] = 0;
        queue_head[priority] = 0;
        queue_tail[priority] = 0;
    }
}

void push_frontier_b(coord_t *coord, uint8_t priority)
{
    uint8_t head;

    // Do not push if priority is greater or equal to max priority
    if (priority > MAX_PRIORITY - 1)
    {
        return;
    }
    
    // Do not push if queue[priority] is full
    if (queue_count[priority] == MAX_SIZE - 1)
    {
        // text_printf("DEBUG - queue is full");
        return;
    }

    head = queue_head[priority];

    // push onto priority queue
    priority_queue[head][priority].x = coord->x;
    priority_queue[head][priority].y = coord->y;

    queue_head[priority]++;
    queue_count[priority]++;

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

uint8_t pop_frontier_head_b(coord_t *coord)
{
    uint8_t head; 

    // if no more entiries in tail_queue find next priority queue with an entry
    while (queue_count[tail_priority] == 0)
    {
        tail_priority++;
        if (tail_priority == MAX_PRIORITY - 1)
        {
            // if reached max priority queue there are no more entries 
            return 0;
        }
    }
    

    // pop entry from head of queue
    head  = queue_head[tail_priority];
    
    head = (head != 0) ? head - 1: MAX_SIZE - 1;

    coord->x = priority_queue[head][tail_priority].x;
    coord->y = priority_queue[head][tail_priority].y;
    queue_head[tail_priority]--;
    queue_count[tail_priority]--;      

    // if head index has gone past end of array wrap to 0
    if (queue_head[tail_priority] == MAX_SIZE)
    {
        queue_head[tail_priority] = 0;
    }

    return 1;
}


uint8_t pop_frontier_tail_b(coord_t *coord)
{
    uint8_t tail; 

    // if no more entiries in tail_queue find next priority queue with an entry
    while (queue_count[tail_priority] == 0)
    {
        tail_priority++;
        if (tail_priority == MAX_PRIORITY - 1)
        {
            // if reached max priority queue there are no more entries 
            return 0;
        }
    }
    
    // pop entry from tail of queue
    tail = queue_tail[tail_priority];    
    coord->x = priority_queue[tail][tail_priority].x;
    coord->y = priority_queue[tail][tail_priority].y;
    
    queue_tail[tail_priority]++;
    queue_count[tail_priority]--;  

    // if tail index has gone past end of array wrap to 0
    if (queue_tail[tail_priority] == MAX_SIZE)
    {
        queue_tail[tail_priority] = 0;
    }

    return 1;
}

void update_neighbors_b(void)
{

    tmp_cost_so_far = reached[current_coord.x][current_coord.y].cost_so_far + 1;

    // north
    if (current_coord.y > min_y)
    {
        tmp_coord.y = current_coord.y - 1;
        tmp_coord.x = current_coord.x;
        tmp_dir = S;

        update_tile_b();
    }

    // south
    if (current_coord.y < max_y)
    {
        tmp_coord.y = current_coord.y + 1;
        tmp_coord.x = current_coord.x;
        tmp_dir = N;

        update_tile_b();
    }

    // west
    if (current_coord.x > min_x)
    {
        tmp_coord.y = current_coord.y;
        tmp_coord.x = current_coord.x - 1;
        tmp_dir = E;

        update_tile_b();
    }    


    // east
    if (current_coord.x < max_x)
    {
        tmp_coord.y = current_coord.y;
        tmp_coord.x = current_coord.x + 1;
        tmp_dir = W;

        update_tile_b();
    }
}

void update_tile_b(void)
{
    if (!dungeonmap_tile_flag_test(tmp_coord.x, tmp_coord.y, DGN_FLAG_BLK_ALL | DGN_FLAG_WALL))
    {
        tmp_total_cost = tmp_cost_so_far + util_distance_manhattan(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        if (tmp_total_cost < reached[tmp_coord.x][tmp_coord.y].total_cost)
        {
            push_frontier_b(&tmp_coord, tmp_total_cost - priority_offset);
            pathfind_mark_reached_b(&tmp_coord, tmp_dir, tmp_total_cost, tmp_cost_so_far);
        }
    }

}
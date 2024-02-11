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

void ai_pathfind_fast_a_star_b(uint8_t origin_x, uint8_t origin_y, uint8_t goal_x, uint8_t goal_y)
{
    direction_t direction_from;


    unsigned int key;

    uint8_t x, y;

    // flip origin and goal around as the resultant path is walked backwards
    goal_coord.x = origin_x;
    goal_coord.y = origin_y;
    start_coord.x = goal_x;
    start_coord.y = goal_y;


    // set current to start of path. Direction to start is NO_DIR  
    current_coord.x = start_coord.x;
    current_coord.y = start_coord.y;
    direction_from = NO_DIR;

    init_priority_queue();

    // Limit the bounds of the path finding to a maximum of 10 x 10 squares around the start
    if (start_coord.x<10) { min_x = 0; } else { min_x = start_coord.x - 10; }
    if (start_coord.x> DUNGEONMAP_WIDTH - 1 - 10) { max_x = DUNGEONMAP_WIDTH - 1; } else { max_x = start_coord.x + 10; }
    if (start_coord.y<10) { min_y = 0; } else { min_y = start_coord.y - 10; }
    if (start_coord.y> DUNGEONMAP_HEIGHT - 1 - 10) { max_y = DUNGEONMAP_HEIGHT - 1; } else { max_y = start_coord.y + 10; }

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

    tmp_cost_so_far = 0;
    tmp_total_cost = tmp_cost_so_far + distance_manhattan_b(start_coord.x, start_coord.y, goal_coord.x, goal_coord.y);
    priority_offset = tmp_total_cost;

    push_frontier_b(&current_coord, 0);
    mark_reached_b(&current_coord, direction_from, tmp_total_cost, tmp_cost_so_far);

    while(pop_frontier_head_b(&current_coord))
    {
        // TODO handle blocking objects (object mark map?)
        // TODO Intelligent vs non-intelligent can open doors so not blocked

        if (current_coord.x == goal_coord.x && current_coord.y == goal_coord.y)
        {
            // text_printf("A* found path\n");
            break;
        }
        update_neighbors_b();

        ai_pathfind_print_b();
        while ((key = in_inkey()) == 0) ;   // loop while no key pressed
        in_wait_nokey();    // wait no key          
    } 
  
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
        text_printf("DEBUG - Priority exceeds bounds");
        return;
    }
    
    // Do not push if queue[priority] is full
    if (queue_count[priority] == MAX_SIZE - 1)
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
    text_printf("p:%u", (unsigned char) priority);
    text_printf("c:%u\n", (unsigned char) queue_count[priority]);

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

    text_printf("Pop  %u,", (unsigned char) coord->x);
    text_printf("%u ", (unsigned char) coord->y);
    text_printf("p:%u", (unsigned char) tail_priority);  
    text_printf("c:%u\n", (unsigned char) queue_count[tail_priority]);  



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

    
    text_printf("Pop  %u,", (unsigned char) coord->x);
    text_printf("%u ", (unsigned char) coord->y);
    text_printf("p:%u\n", (unsigned char) tail_priority);
    

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
    tmp_coord.x = current_coord.x;
    tmp_coord.y = (current_coord.y > min_y) ? current_coord.y - 1 : min_y;

    if (!dungeonmap_tile_is_blocked(tmp_coord.x, tmp_coord.y))
    {
        // A* cost is cost of path so far + distance to goal
        tmp_total_cost = tmp_cost_so_far + distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);

        // if cost is less than previous visit to the square
        if (tmp_total_cost < reached[tmp_coord.x][tmp_coord.y].total_cost)
        {
            push_frontier_b(&tmp_coord, tmp_total_cost - priority_offset);
            mark_reached_b(&tmp_coord, S, tmp_total_cost, tmp_cost_so_far);
        }
    }

    // south
    tmp_coord.x = current_coord.x;
    tmp_coord.y = (current_coord.y < max_y) ? current_coord.y + 1 : max_y;

    if (!dungeonmap_tile_is_blocked(tmp_coord.x, tmp_coord.y))
    {
        tmp_total_cost = tmp_cost_so_far + distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        if (tmp_total_cost < reached[tmp_coord.x][tmp_coord.y].total_cost)
        {
            push_frontier_b(&tmp_coord, tmp_total_cost - priority_offset);
            mark_reached_b(&tmp_coord, N, tmp_total_cost, tmp_cost_so_far);
        }
    }

    // west
    tmp_coord.x = (current_coord.x > min_x) ? current_coord.x - 1 : min_x;
    tmp_coord.y = current_coord.y;

    if (!dungeonmap_tile_is_blocked(tmp_coord.x, tmp_coord.y))
    {
        tmp_total_cost = tmp_cost_so_far + distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        if (tmp_total_cost < reached[tmp_coord.x][tmp_coord.y].total_cost)
        {
            push_frontier_b(&tmp_coord, tmp_total_cost - priority_offset);
            mark_reached_b(&tmp_coord, E, tmp_total_cost, tmp_cost_so_far);
        }
    }

    // east
    tmp_coord.x = (current_coord.x < max_x) ? current_coord.x + 1 : max_x;
    tmp_coord.y = current_coord.y;

    if (!dungeonmap_tile_is_blocked(tmp_coord.x, tmp_coord.y))
    {
        tmp_total_cost = tmp_cost_so_far + distance_manhattan_b(tmp_coord.x, tmp_coord.y, goal_coord.x, goal_coord.y);
        if (tmp_total_cost < reached[tmp_coord.x][tmp_coord.y].total_cost)
        {
            push_frontier_b(&tmp_coord, tmp_total_cost - priority_offset);
            mark_reached_b(&tmp_coord, W, tmp_total_cost, tmp_cost_so_far);
        }
    }
}
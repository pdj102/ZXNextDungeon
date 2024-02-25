/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Pathfinding - breadth first search

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "pathfind_bank.h"

#include <stdint.h>

#include "text.h"
#include "util.h"


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

direction_t pathfind_direction_b(uint8_t x, uint8_t y)
{
    return (reached[x][y].reached_from);
}

void pathfind_mark_reached_b(coord_t *coord, direction_t direction_from, uint8_t total_cost, uint8_t cost_so_far)
{
    reached[coord->x][coord->y].total_cost = total_cost;
    reached[coord->x][coord->y].cost_so_far = cost_so_far;
    reached[coord->x][coord->y].reached_from = direction_from;
}

uint8_t pathfind_is_reached_b(coord_t *coord)
{
    return ( reached[coord->x][coord->y].total_cost );
}

void pathfind_print_b( void )
{
    uint8_t x;
    uint8_t y;
    direction_t direction_from;

    for(x = 0; x < 25; x++)
    {
        for (y = 0; y < 25; y++)
        {
                direction_from = pathfind_direction_b(x, y);

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



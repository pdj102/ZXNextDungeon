/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding - breadth first search

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_pathfind_bank.h"

#include <stdint.h>

#include "text.h"


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

direction_t ai_pathfind_direction_b(uint8_t x, uint8_t y)
{
    return (reached[x][y].reached_from);
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


void ai_pathfind_print_b( void )
{
    uint8_t x;
    uint8_t y;
    direction_t direction_from;

    for(x = 0; x < 40; x++)
    {
        for (y = 0; y < 40; y++)
        {
                direction_from = ai_pathfind_direction_b(x, y);

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




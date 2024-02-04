/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_pathfind_breadth_first_search_bank.h"

#include <stdint.h>
#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions   

#include "ai_pathfind_breadth_first_search_bank.h"
#include "ai_pathfind_fast_a_star_bank.h"

void ai_pathfind_fast_a_star(uint8_t x, uint8_t y, uint8_t goal_x, uint8_t goal_y)
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    ai_pathfind_breadth_first_search_b(x, y);
    ai_pathfind_fast_a_star_b(x, y, goal_x, goal_y);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

void ai_pathfind_breadth_first_search(uint8_t x, uint8_t y)
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    ai_pathfind_breadth_first_search_b(x, y);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

direction_t ai_pathfind_direction(uint8_t x, uint8_t y)
{
    uint8_t current_bank;

    direction_t c;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    c = ai_pathfind_direction_b(x, y);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);   
    return c;
}

void ai_pathfind_print( void )
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map AI (bank 26) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(26);    
    ai_pathfind_print_b();

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

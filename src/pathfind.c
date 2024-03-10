/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Pathfinding

    Code is banked do not call directly

 ***************************************************/

#include "pathfind.h"

#include <stdint.h>
#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions   

#include "pathfind_fast_a_star_bank.h"

uint8_t pathfind_fast_a_star(uint8_t origin_x, uint8_t origin_y, uint8_t goal_x, uint8_t goal_y, uint8_t mem_page, uint8_t flags)
{
    uint8_t current_bank;
    uint8_t path_found;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map pathfding code (bank 27) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_MMU6(27);
    /* Map pathfinding data page into ZX Spectrum 8k MMU slot 7 */
    ZXN_WRITE_MMU7(mem_page);        

    /* Call banked code */     
    path_found = pathfind_fast_a_star_b(origin_x, origin_y, goal_x, goal_y, flags);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return path_found;
}

direction_t pathfind_direction(uint8_t x, uint8_t y, uint8_t mem_page)
{
    uint8_t current_bank;

    direction_t c;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map pathfding code (bank 27) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_MMU6(27);
    /* Map pathfinding data page into ZX Spectrum 8k MMU slot 7 */
    ZXN_WRITE_MMU7(mem_page);        

    /* Call banked code */      
    c = pathfind_direction_b(x, y);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);   
    return c;
}

void pathfind_print( uint8_t mem_page )
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map pathfding code (bank 27) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_MMU6(27);
    /* Map pathfinding data page into ZX Spectrum 8k MMU slot 7 */
    ZXN_WRITE_MMU7(mem_page);         

    /* Call banked code */    
    pathfind_print_b();

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

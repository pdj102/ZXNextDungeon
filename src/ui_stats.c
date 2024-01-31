/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief UI player stats

 ***************************************************/
#include "ui_stats.h"
#include "ui_stats_bank.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions 

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

void ui_display_hp_mp( void )
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Call banked code */ 
    ZXN_WRITE_MMU7(25);    
    ui_display_hp_mp_b();

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

void ui_display_stats( void )
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Call banked code */ 
    ZXN_WRITE_MMU7(25);    
    ui_display_stats_b();

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

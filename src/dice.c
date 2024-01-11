/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dice

 ***************************************************/
#include "dice.h"

#include <stdint.h>
#include <stdlib.h>


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
 * functions definitions
 ***************************************************/

uint8_t dice_1d20(void)
{
    return 1 + rand() % 20;
}

uint8_t dice_roll(const dice_t *dice_p)
{
    uint8_t roll = 0;

    for (uint8_t i = 0; i < dice_p->n; i++)
    {
        roll += 1 + rand() % dice_p->d;
    }
    roll += dice_p->mod;

    return roll;
}

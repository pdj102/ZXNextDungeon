/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Dice

 ***************************************************/
#include "dice.h"

#include <inttypes.h>
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

uint8_t dice_roll(const dice_t *dice_ptr)
{
    uint8_t roll = 0;

    for (uint8_t i = 0; i < dice_ptr->n; i++)
    {
        roll = 1 + rand() % dice_ptr->d;
    }
    roll += dice_ptr->modifier;

    return roll;
}

uint8_t dice_roll_1d20()
{
    return 1 + rand() % 20;
}

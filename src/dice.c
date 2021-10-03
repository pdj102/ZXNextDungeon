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
 * private variables
 ***************************************************/
dice_t dice_1d20 = { 1, 20, 0, "1D20"};
dice_t dice_1d12 = { 1, 12, 0, "1D12"};
dice_t dice_1d10 = { 1, 10, 0, "1D10"};
dice_t dice_1d8  = { 1, 8,  0, "1D8"};
dice_t dice_1d6  = { 1, 6,  0, "1D6"};
dice_t dice_1d4  = { 1, 4,  0, "1D4"};
dice_t dice_1d2  = { 1, 2,  0, "1D2"};

dice_t *dice_1d20_p;
dice_t *dice_1d12_p;
dice_t *dice_1d10_p;
dice_t *dice_1d8_p;
dice_t *dice_1d6_p;
dice_t *dice_1d4_p;
dice_t *dice_1d2_p;

/***************************************************
 * functions definitions
 ***************************************************/

void dice_init()
{
    dice_1d20_p = &dice_1d20;
    dice_1d12_p = &dice_1d12;
    dice_1d10_p = &dice_1d10;
    dice_1d8_p  = &dice_1d8;
    dice_1d6_p  = &dice_1d6;
    dice_1d4_p  = &dice_1d4;
    dice_1d2_p  = &dice_1d2;
}

uint8_t dice_roll(dice_t *dice)
{
    uint8_t roll = 0;

    for (uint8_t i = 0; i < dice->n; i++)
    {
        roll = 1 + rand() % dice->d;
    }
    roll += dice->modifier;

    return roll;
}

uint8_t dice_roll_1d20()
{
    return 1 + rand() % 20;
}

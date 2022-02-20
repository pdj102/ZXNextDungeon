/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Dice

 ***************************************************/

#ifndef DICE_H 
    #define DICE_H 

#include <inttypes.h>

/***************************************************
 * public types
 ***************************************************/

typedef struct {
    uint8_t n;
    uint8_t d;
    uint8_t modifier;
} dice_t;

/***************************************************
 * public variables - extern
 ***************************************************/



/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief roll dice nDx+m
 * @param dice_ptr 
 *
 * @return roll
 */
uint8_t dice_roll(dice_t *dice_ptr);


/**
 * @brief Roll 1D20
 *
 * @return 1d20
 */
uint8_t dice_roll_1d20();

#endif

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

/**
 * @brief A structure to represent dice rolls - n * dice + modifier
 * 
 */
typedef struct {
    uint8_t n;          /**< the number of die to roll */
    uint8_t d;          /**< the number of sides e.g. d20  */
    uint8_t modifier;   /**< the modifier to add to the dice roll */
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
uint8_t dice_roll(const dice_t *dice_ptr);


/**
 * @brief Roll 1D20
 *
 * @return 1d20
 */
uint8_t dice_roll_1d20();

#endif

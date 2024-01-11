/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dice

 ***************************************************/

#ifndef DICE_H 
    #define DICE_H 

#include <stdint.h>

/***************************************************
 * public types
 ***************************************************/

typedef struct {
    uint8_t n;          /**< the number of die to roll */
    uint8_t d;          /**< the number of sides e.g. d20  */
    uint8_t mod;        /**< the modifier to add to the dice roll */
} dice_t;

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief roll 1d20
 * 
 * @return uint8_t  returns 1d20 result
 */
uint8_t dice_1d20(void);

/**
 * @brief roll dice
 * 
 * @return uint8_t  returns result
 */
uint8_t dice_roll(const dice_t *dice_p);

#endif
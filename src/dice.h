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
    char name[];
} dice_t;

/***************************************************
 * public variables - extern
 ***************************************************/
extern dice_t *dice_1d20_p;
extern dice_t *dice_1d12_p;
extern dice_t *dice_1d10_p;
extern dice_t *dice_1d8_p;
extern dice_t *dice_1d6_p;
extern dice_t *dice_1d4_p;
extern dice_t *dice_1d2_p;


/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Init die module. Call before using 
 *
 * @return void
 */
void dice_init();

/**
 * roll dice nDx+m
 *
 * @return roll
 */
uint8_t dice_roll(dice_t *dice);


/**
 * Roll 1D20
 *
 * @return 1d20
 */
uint8_t dice_roll_1d20();

#endif

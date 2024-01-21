/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The AI code

 ***************************************************/

#ifndef AI_H 
    #define AI_H 

#include "object.h"

/***************************************************
 * types
 ***************************************************/

typedef enum {
    NO_STATE, SLEEPING, ATTACKING
} ai_state_t;

typedef struct ai_s
{
    ai_state_t      state;
} ai_t;

/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Init the ai
 *
 * @param ai_ptr pointer to the ai object
 * @return void
 */
void ai_init(ai_t *ai_p);

/**
 * Ai takes turn
 * 
 * @return void
 */
void ai_turn( void );

#endif
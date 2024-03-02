/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - guarding state

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_GOTO_BANK_H 
    #define AI_GOTO_BANK_H 

#include "ai.h"

/***************************************************
 * types
 ***************************************************/

// typedef enum goto_result {GOTO_RESULT_NA, GOTO_RESULT_SUCCESS, GOTO_RESULT_FAIL_NO_PATH, GOTO_RESULT_REACHED} goto_result_t;

/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/** 
 * @brief set goto target 
 * 
 * Sets ai sub_state to GOTO_NO_PATH_SET
 * 
 * @param *ai_p     pointer to ai
 * @param x         goto x
 * @param y         goto y
 */
void ai_set_goto_b(ai_t *ai_p, uint8_t x, uint8_t y);

/**
 * @brief try to move towards goto target
 * 
 * @param *ai_p     pointer to ai
 * 
 * @return void
 */
void ai_goto_b( ai_t *ai_p );

/**
 * @brief Construct a new ai goto setpath 
 * 
 * If a path is found, sets ai sub_state to GOTO_PATH_SET
 * If no path found, sets ai sub_state to GOTO_PATH_ERROR
 * 
 * @param *ai_p     pointer to ai
 */
void ai_goto_setpath_b(ai_t *ai_p);

/**
 * @brief Attempt to move toward goto target
 * 
 * On success, sets ai sub_state to GOTO_PATH_SET
 * On failure, sets ai sub_state to GOTO_NO_PATH_SET
 * 
 * @param *ai_p     pointer to ai
 */
void ai_goto_move_b(ai_t *ai_p);

#endif
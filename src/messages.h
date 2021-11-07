/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Displays messages

 ***************************************************/

#ifndef MESSAGES_H 
    #define MESSAGES_H 

#include <inttypes.h>

/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Init messages buffer
 * 
 * @return void
 */
void messages_init();

/**
 * Adds a message to the message display buffer. Also calls messages_display to update screen
 * 
 * @param message  pointer to message string
 * @return void
 */
void messages_print(char message[]);

/**
 * Display the messages buffer on the screen
 * 
  * @return void
 */
void messages_display();

void messages_print_s_uint8(char message[], uint8_t num);

#endif
/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Messages buffer

 ***************************************************/
#include "messages.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define printAt(col, row)    printf("\x16%c%c", col, row)

#define MAX_MESSAGES 3
#define MESSAGE_LENGTH 30

// TODO change to using the tile map and longer messages

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/

char messages[MAX_MESSAGES][MESSAGE_LENGTH+1];

uint8_t head = 0;   // points to next message slot in circular buffer

/***************************************************
 * functions definitions    
 ***************************************************/

void messages_init()
{
                //  12345678901234567890123456789
    messages_print("Welcome to Dungeon");
    messages_print("You are on level 1");
    messages_print("------------------");
}

void messages_display()
{
    uint8_t pos;
    uint8_t row;

    // clear message display area
    for (row = 21; row <= 23; row++)
    {
        printAt(1, row);
        printf("                             ");
    }
    
    // print messages from circular message buffer
    pos = head;
    for (row = 23; row >= 21; row--)
    {
        // walk backwards through circular messages buffer
        if (pos == 0)
        {
            pos = MAX_MESSAGES-1;
        }
        else
        {
            pos--;
        }

        printAt(1, row);
        printf(messages[pos]);
    }
}
void messages_print(char message[])
{
   // to do truncate message to message length
    strcpy(messages[head], message);

    head++;
    if (head == MAX_MESSAGES) head = 0;
    
    messages_display();
}

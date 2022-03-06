/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Messages buffer

 ***************************************************/
#include "messages.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>     // strcpy()
#include <stdlib.h>     // iota()

#include "text.h"

// #define printAt(col, row)    printf("\x16%c%c", col, row)

#define MAX_MESSAGES 8
#define MESSAGE_LENGTH 40

// TODO change to using the tile map and longer messages

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

char messages[MAX_MESSAGES][MESSAGE_LENGTH+1];

uint8_t head = 0;   // points to next message slot in circular buffer
uint8_t column = 0; // position of the next character to be printed on the line 

            //  1234567890123456789012345678901234567890
char blank[] = "                                        ";

/***************************************************
 * functions definitions    
 ***************************************************/

void messages_init()
{
                //  1234567890123456789012345678901234567890
    messages_println("WELCOME TO DUNGEON");
    messages_println("YOU ARE ON LEVEL 1");
    messages_println("------------------");
}

void messages_display()
{
    uint8_t pos;
    uint8_t row;
    
    // print messages from circular message buffer
    pos = head;
    for (row = 24 + MAX_MESSAGES - 1; row >= 24; row--)
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

        text_print(0, row, blank);
        text_print(0, row, messages[pos]);
    }
}

void messages_print(char message[])
{
    uint8_t length = strlen(message);
    uint8_t message_pos = 0;

    while(message_pos < length)
    {
        messages[head][column] = message[message_pos];
        message_pos++;
        column++;
        if (column == MESSAGE_LENGTH + 1)
             break;   // TO DO move to next line and continue printing
    }
    messages[head][column] = '\0';  // terminate line
}

void messages_println(char message[])
{
    messages_print(message);

    // new line
    head++;
    column = 0;
    if (head == MAX_MESSAGES) head = 0;
    
    messages_display();
}

void messages_print_s_uint8(char message[], uint8_t num)
{
    char s[4];
    itoa(num, s, 10);

    messages_print(message);
    messages_println(s);

}

void messages_print_s_int8(char message[], int8_t num)
{
    char s[4];
    itoa(num, s, 10);

    messages_print(message);
    messages_println(s);

}

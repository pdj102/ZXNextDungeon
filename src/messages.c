/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    <Module description>

 ***************************************************/
#include "messages.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define printAt(col, row)    printf("\x16%c%c", col, row)

#define MAX_MESSAGES 3
#define MESSAGE_LENGTH 30

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

uint8_t head = 0;

/***************************************************
 * functions definitions    
 ***************************************************/

void messages_init()
{
    messages_print("023456789012345678901234567890");
    messages_print("123456789012345678901234567890");
    messages_print("223456789012345678901234567890");    
}

void messages_display()
{
    uint8_t pos = head;

    printAt(1, 23);
    //puts("21");
    puts(messages[pos]);
    if (pos==0)
    {
        pos = MAX_MESSAGES-1;
    }
    else
    {
        pos--;
    }
    printAt(1, 22);
    //puts("22");
    puts(messages[pos]);
    if (pos==0)
    {
        pos = MAX_MESSAGES-1;
    }
    else
    {
        pos--;
    }    
    printAt(1, 21);
    //puts("23");
    puts(messages[pos]);
}
void messages_print(char message[])
{
    head++;
    if (head == MAX_MESSAGES-1) head = 0;

   // to do truncate message to message length
    strcpy(messages[head], message);
    
    messages_display();
}

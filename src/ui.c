/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief User Interface routines

 ***************************************************/
#include "ui.h"

#include <stdio.h>      // NULL
#include <input.h>      //  in_WaitForKey()
#include <ctype.h>      // character classification e.g. toupper() 

#include "entity.h"
#include "entity_item.h"

#include "text.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions 
 ***************************************************/


uint8_t ui_display_items(entity_location_t location)
{
    entity_item_t *item_ptr;

    char s[] = "25500";     // string buffer for converting numbers to strings

    uint8_t count = 0;

    ui_clear_display();

    switch (location)
    {
    case inventory:
        text_print_string(24, 0, "INVENTORY");
        break;
    case wearing:
        text_print_string(24, 0, "EQUIPPED");
        break;
    
    default:
        break;
    } 

    item_ptr = entity_item_first_at_location(location);

    while ( item_ptr != NULL)
    {
        text_print_char(24, 2+count, 'A'+count);
        text_print_string(26, 2+count, item_ptr->name );
        count++;        

        item_ptr = entity_item_next_at_location(location, item_ptr);
    }

    return count;
}

uint8_t ui_select_item(uint8_t max)
{
    unsigned char key;    
    uint8_t index;

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key
    key = toupper(key);

    if (key == ' ')
    {
        return 0;
    }

    // A = 1
    // B = 2 etc
    index = (key - 'A') + 1;

    if (index > max)
    {
        return 0;
    }

    return index;
}

void ui_draw_stat_block(const creature_t *creature_ptr)
{
    ui_clear_display();

    text_print_string(24, 0, creature_ptr->name);
    text_print_string(24, 1, creature_ptr->creature);
    text_print_string(24, 2, "LEVEL");
    text_print_string(24, 3, "EXP");

    text_print_string(24, 5, "STR:");
    text_print_string(24, 6, "INT:");
    text_print_string(24, 7, "WIS:");
    text_print_string(24, 8, "DEX:");
    text_print_string(24, 9, "CON:");
    text_print_string(24, 10, "CHA:");    

    text_print_string(24, 11, "AC:");
    text_print_string(24, 12, "HP:");

    text_print_string(24, 13, "SPEED:");

    text_print_uint8(30, 2, creature_ptr->lvl);

    text_print_uint16(30, 3, creature_ptr->exp);


    text_print_uint8(30, 5, creature_ptr->strength);
    text_print_uint8(30, 6, creature_ptr->intelligence);
    text_print_uint8(30, 7, creature_ptr->wisdom);
    text_print_uint8(30, 8, creature_ptr->dexterity);
    text_print_uint8(30, 9, creature_ptr->constitution);
    text_print_uint8(30, 10, creature_ptr->charisma);    
    
    text_print_uint8(30, 11, creature_ptr->ac);

    text_print_uint8(30, 12, creature_ptr->curr_hp);

    text_print_uint8(30, 13, creature_ptr->speed);
}


void ui_clear_display()
{
    uint8_t i;
    const char *blank_string = "                ";

    for (i = 0; i < TILE_MAP_HEIGHT - 8; i++)
    {
        text_print_string(24, i, blank_string);
    }
}

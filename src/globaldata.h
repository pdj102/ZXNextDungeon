/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game global data 

 ***************************************************/

#ifndef GLOBALDATA_H 
    #define GLOBALDATA_H

#include <adt/p_forward_list.h>

#include "dungeonmap.h"
#include "object.h"
#include "event.h"
#include "creature.h"
#include "text.h"

/***************************************************
 * types
 ***************************************************/

// Global game data stucture 
typedef struct
{
    dungeonmap_t    dungeonmap;
    object_t        objects[MAX_OBJECT];
    event_t         events[MAX_EVENT];
    creature_t      creatures[MAX_CREATURE];
    p_forward_list_t dungeon_object_list;     
    p_forward_list_t event_list; 
    p_forward_list_t creature_list; 
    text_window_t   text_window;
    uint8_t     tmp;
} globaldata_t;

/***************************************************
 * variable declarations
 ***************************************************/

// Globaldata is defined in memory.asm
extern globaldata_t globaldata;

/***************************************************
 * function prototypes
 ***************************************************/

void globaldata_init();

#endif
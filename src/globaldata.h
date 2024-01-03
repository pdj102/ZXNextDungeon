/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game global data 

 ***************************************************/

#ifndef GLOBALDATA_H 
    #define GLOBALDATA_H

#include "dungeonmap.h"
#include "object.h"
#include "text.h"

/***************************************************
 * types
 ***************************************************/

// Global game data stucture 
typedef struct
{
    dungeonmap_t    dungeonmap;
    object_t        objects[MAX_OBJECT];
    text_window_t   text_window;
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
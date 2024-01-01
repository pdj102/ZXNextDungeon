/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game global data 

 ***************************************************/

#ifndef GLOBALDATA_H 
    #define GLOBALDATA_H

#include "dungeonmap.h"
#include "object.h"

/***************************************************
 * types
 ***************************************************/

// Global game data stucture 
typedef struct
{
    dungeonmap_t    dungeonmap;
    object_t        objects[MAX_OBJECT];
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
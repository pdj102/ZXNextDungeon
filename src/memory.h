/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Memory map definitions

    The Z80 processor can address 64Kib of memory 
    This memory is divided into 8 MMU slots of 8 KiB each
    The zxnext physical memory (1Mb+) is divided into 8KiB pages PAGE_0 through PAGE_223 
    Any physical memory page can mapped into any MMU slot

    To compile a C file to be put in a page, e.g. page 19, use the --codesegPAGE_19 --constsegPAGE_19 compiler options. 
    Note the ORG in the C file also needs to be set so the compiler knows where the page will appear in the 64k memory when banked in
    In this memory model banked pages are always banked into MMU slot 6 or 7 e.g. 0xc000+

    The memory map model is as follows:

    MMU SLOT    |   Address         |   Page    |   Description   
    ------------|-------------------|-----------|---------------------------------------------------------------------
    0           |   0x0000-0xfff    |   16      |   Global game data structure - dungeon map, objects etc. Paged in - do not bank out
    1           |   0x2000-0x3fff   |   17      |   Global game data structure - dungeon map, objects etc. Paged in - do not bank out
    2           |   0x4000-0x5fff   |   10      |   ZX Next tile map and patterns. Default page
    3           |   0x6000-0x7fff   |   11      |   ZX Next tile map and patterns. Default page
    4           |   0x8000-0x9fff   |   4       |   Global game code. Default page - do not bank out
    5           |   0xa000-0xbfff   |   5       |   Global game code and stack. Default page - do not bank out
    6           |   0xc000-0xdfff   |   Banked  |   Banked code and data
    7           |   0xe000-0xffff   |   Banked  |   Banked code and data


    MMU 6 - List of banked pages:

    Page    |   Description
    --------|-----------------------------------------------------
    18      |   Dungeon map generator
    20      |   Object create

    MMU 7 - List of banked pages:

    Page    |   Description
    --------|-----------------------------------------------------
    19      |   reserved for dungeon map generator 
    21      |   Text token 

 ***************************************************/

#ifndef MEMORY_H 
    #define MEMORY_H

#include "dungeonmap.h"

/*
 * ZX Next tile map and pattern address is located at MMU slots 2 and 3 (Bank 5) 0x4000 - 0x7fff
 * The ULA screen is located 0x4000 - 0x5FFF (7 KiB)
 * The ULA screen is not required and will be disabled so the tilemap can start at 0x4000
*/
#define TILEMAP_BASE 0x4000

/*
 * The tilemap is 2,560 (0xa00) bytes so occupies 0x4000 - 0x49ff
 * Placing the tile definitions at or above 0x4A00 avoids it
 * Note the tile defns will overflow into MMU 3
 */
#define TILEDEFNS_BASE 0x4a00


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

void memory_init( void );

#endif
/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Memory map definitions

    The Z80 processor can address 68Kib of memory 
    This memory is divided into 8 MMU slots of 8 KiB
    The zxnext physical memory (1Mb+) is divided into 8KiB pages
    Any physical memory page can mapped into any MMU slot
    BANK_H_N and BANK_L_N assigns to upper or lower 
    PAGE_N assigns to an 8K page without limits applied
    The ORG needs to be set so the compiler knows where the page will appear in memory

 ***************************************************/

#ifndef MEMORY_MAP_H 
    #define ENTITY_MAP_H 

#define ENTITY_MEMORY_BANK 17

// ------------------- MMU SLOT 0 (0x0000) ------------------- 
// Memory page 16 (8Kib) - Dungeon map data structure

// DATA _dungeon_map defined in dungeon_map_data.asm


// ------------------- MMU SLOT 1 (0x2000) ------------------- 
// Memory page 17 (8KiB) - Entities, Creature entities, items and effects data structures

// 0x2000 - 0x2400 - entity data structures (1 KiB)
#define ENTITY_BASE 0x2000
#define ENTITY_SIZE 0x400

// 0x2400 - 0x2fff - entity_creature data structures (3 KiB)
#define CREATURE_BASE 0x2400
#define CREATURE_SIZE 0xC00

// 0x3000 - 0x33ff - item data structures (1 KiB)
#define ITEM_BASE 0x3000
#define ITEM_SIZE 0x400

// 0x3400 - 0x37ff - effect data structures (1 KiB)
#define EFFECT_BASE 0x3400
#define EFFECT_SIZE 0x400

// 2KiB unsued 

// ------------------- MMU SLOT 2 (0x4000) -------------------
// Memory page 10 (8KiB) - tile map and patterns

// 0x4000 - 0x49ff -tile map
#define TILEMAP_BASE 0x4000

// 0x4a00 - tile patterns
// DATA _tile_pattern defined in tile_defns_data.asm


// ------------------- MMU SLOT 3 (0x6000) -------------------
// Memory page 11 (8KiB) - tile map and patterns

// tile patterns from memory page 10 overflow into memory page 11

// ------------------- MMU SLOT 4 (0x8000) -------------------
// Memory page 4 (8KiB) - common code not banked out

// By default z88dk will place code starting at 0x8000

// ------------------- MMU SLOT 5 (0xa000) -------------------
// Memory page 5 (8KiB) - common code not banked out
// Top of stack located at 0xbfff (set by pragma)

// ------------------- MMU SLOT 6 (0xc000) -------------------
// Memory pages 18 to 21 - used for banked code and data

// NB keep main code to 16KiB

// ------------------- MMU SLOT 7 (0xe000) -------------------
// Memory pages 18 to 21 - used for banked code and data

// Memory page 18 (8KiB) - dungeon map generator



#endif
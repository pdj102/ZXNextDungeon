/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Memory map definitions 

 ***************************************************/

#ifndef MEMORY_MAP_H 
    #define ENTITY_MAP_H 

#define ENTITY_MEMORY_BANK 17

// Entities - Uses 1 8KiB bank loaded into MMU slot 1 (0x2000)

// 0x2000 - 0x2400 = 1 KiB
#define ENTITY_BASE 0x2000
#define ENTITY_SIZE 0x400

// 0x2400 - 0x2fff = 3 KiB
#define CREATURE_BASE 0x2400
#define CREATURE_SIZE 0x800

// 0x3000 - 0x33ff = 1 KiB
#define ITEM_BASE 0x3000
#define ITEM_SIZE 0x400

// 0x3400 - 0x37ff = 1 KiB
#define EFFECT_BASE 0x3400
#define EFFECT_SIZE 0x400

// 2KiB unsued 

#endif
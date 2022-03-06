/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Set palette

 ***************************************************/

#ifndef PALETTE_H 
    #define PALETTE_H 

#define PALETTE_DUNGEON     0b00000000 
#define PALETTE_PLAYER      0b00010000 
#define PALETTE_ITEM_RED    0b01000000 
#define PALETTE_ITEM_BLUE   0b01010000
#define PALETTE_ITEM_GREEN  0b01100000


/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * Set the tilemap palette
 * 
 * @return void
 */
void palette_init();


#endif
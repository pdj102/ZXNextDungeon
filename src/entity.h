/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manage entities. An entity represents an item, effect or creature 

 ***************************************************/

#ifndef ENTITY_H 
    #define ENTITY_H 

#include <inttypes.h>
#include "entity_creature.h"

/***************************************************
 * types
 ***************************************************/
enum entity_type {item, effect, creature};


typedef struct item {
    uint8_t i;
} item_t;

typedef struct effect {
    uint8_t i;
} effect_t;



typedef struct entity {
    void *next;     // p_forward_list next

    uint8_t x;
    uint8_t y; 
    uint8_t c;

    uint8_t current_energy;
    uint8_t turn_energy;

    uint8_t blocking; 

    enum entity_type type;
    creature_t *creature_ptr;
    item_t *item_ptr;    

} entity_t;


/***************************************************
 * function prototypes
 ***************************************************/

void entity_init();
void entity_print();
uint8_t entity_passable(uint8_t y, uint8_t x);
uint8_t move(entity_t *entity_ptr, int8_t dy, int8_t dx);

entity_t *entity_at(uint8_t y, uint8_t x);

entity_t *entity_player();
entity_t *entity_next(entity_t *entity_ptr);

void entity_remove(entity_t *entity_ptr);

#endif
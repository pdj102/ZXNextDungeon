/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creatures

 ***************************************************/

#ifndef CREATURE_H 
    #define CREATURE_H 

#include <inttypes.h>

#include "object.h"


#define MAX_CREATURE  15


/***************************************************
 * types
 ***************************************************/

typedef enum {PLAYER, AI} creature_class_e;


typedef struct 
{
    void                    *next;              /**< creatures can be part of a list of creatures. Next pointer must be first 2 bytes in struct */
    uint8_t                 free;               /**< 1 if creature slot is free */
    object_t                *obj_p;             /** all creatures have an associated object */

    creature_class_e        creature_class;     /**< player or AI */

    uint8_t                 max_hp;
    uint8_t                 hp;
    uint8_t                 ac;

    uint8_t                 speed;
    uint8_t                 energy;

    uint8_t                 strength;
    uint8_t                 dexteriy;
    uint8_t                 intelligence;
    uint8_t                 wisdom;
    uint8_t                 charisma;

    uint8_t                 exp;

    uint8_t                 max_magic;
    uint8_t                 cur_magic;
        
} creature_t;



/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the creature data structure. Must be called before using Creature module
 * 
 * @return void
 */
void creature_init();

/**
 * Find a free creature slot
 * 
 * @return   creature_t* pointer to a free creature slot or 0 if no free slot
 */
creature_t* creature_getfree();

/**
 * Create a creature
 * 
 * Creates a creature record based on the provided object. 
 * NB the object specifies the creature type to create
 *
 * @param obj_p* pointer to object
 *
 * @return pointer to created creature or NULL on failed to create
 */
creature_t* creature_create(object_t *obj_p);

/**
 * Delete a creature 
 * 
 * NB creature's object needs to be deleted separately 
 * 
 * @param   *creature_p  Creature to destroy
 */
void creature_delete(creature_t *creature_p);

/**
 * Creature turn
 * 
 * 
 * @param   *creature_p  
 */
void creature_turn(creature_t *creature_p);


#endif
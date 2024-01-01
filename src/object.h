/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

 ***************************************************/

#ifndef OBJECT_H 
    #define OBJECT_H 

#include <inttypes.h>
#include <adt/p_forward_list.h>

#include "tilemap.h"

#define MAX_OBJECT  40


/***************************************************
 * types
 ***************************************************/

typedef enum object_class {PHYSICAL, ITEM, CREATURE} object_class_e;

typedef enum object_type {
    DOOR,
    HUMANOID,
    POTION
    } object_type_e;

typedef enum object_subtype {
    DOOR_OPEN,
    DOOR_CLOSED,
    HUMANOID_HUMAN,
    POTION_HEALING,
    POTION_SPEED
    } object_subtype_e;

typedef struct
{
    void                    *next;              /**< list of active objects. Next pointer must be first 2 bytes in struct */
    uint8_t                 free;               /** 1 if object is free */
    tilemap_tile_t          tilemap_tile;
    uint8_t                 x;
    uint8_t                 y;
    uint8_t                 blocking;           /**< 1 if the object is blocking 0 if non-blocking */
    object_class_e          class;
    object_type_e           type;
    object_subtype_e        subtype;
        
} object_t;


/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the object data structure. Must be called before using Object 
 * 
 * @return void
 */
void object_init();

/**
 * Create an  object of type subtype at xm y.  
 *
 * @param subtype object subtype to create
 * @param x dungeon x position
 * @param y dungeon y position
 * @return pointer to created object or NULL on failed to create
 */
object_t* object_create(object_subtype_e subtype, uint8_t x, uint8_t y);

/**
 * Move object to position x, y if not blocked
 * 
 * @param *obj pointer to object to move
 * @param x move to dungeon x position
 * @param y move to dungeon y position
 * 
 * @return void
 */
void object_xy(object_t *obj, uint8_t x, uint8_t y);

 void object_test();

/**
 * Check if an object is blocking dungeon x, y
 * 
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return 1 if object blocking or 0
 */
uint8_t object_isblocking(uint8_t x, uint8_t y);

/**
 * Draws all the objects to the graphics tile map
 * 
 * @return void
 */
void object_drawall();

/**
 * Returns the first in use object 
 * 
 * @return *object_t    first in use object or 0 if no objects
 */
object_t *object_first();

/**
 * Returns the next in use object 
 * 
 * @return *object_t    next in use object or 0 if no more objects
 */
object_t *object_next(object_t *obj_ptr);

#endif
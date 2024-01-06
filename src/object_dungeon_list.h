/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief @brief Dungeon list of objects

 ***************************************************/

#ifndef OBJECT_DUNGEON_LIST_H 
    #define OBJECT_DUNGEON_LIST_H 

#include <inttypes.h>

#include "object.h"


/***************************************************
 * types
 ***************************************************/

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
void object_dungeon_list_init();

/**
 * Add the object to the list of dungeon objects
 * Object must not belong to another list!
 *
 * @param *obj_ptr pointer to object 
 * 
 * @return uint8_t  1 success 0 fail
 */
void object_dungeon_list_add(object_t* obj_ptr);

/**
 * Remove the object from the list of dungeon objects
 *
 * @param *obj_ptr pointer to object 
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t object_dungeon_list_remove(object_t* obj_ptr);

/**
 * Check if an object is blocking dungeon x, y
 * 
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return 1 if object blocking or 0
 */
uint8_t object_dungeon_list_isblocking_at(uint8_t x, uint8_t y);

/**
 * Draws all the objects to the graphics tile map
 * 
 * @return void
 */
void object_dungeon_list_drawall();

/**
 * Returns the first object in the dungeon object list
 * 
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_dungeon_list_first();

/**
 * Returns the next object in the dungeon object list
 * 
 * @return *object_t    pointer to next object or 0 if no more objects
 */
object_t *object_dungeon_list_next(object_t *obj_ptr);

#endif
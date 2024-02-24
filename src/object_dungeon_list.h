/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief @brief Dungeon list of objects

 ***************************************************/

#ifndef OBJECT_DUNGEON_LIST_H 
    #define OBJECT_DUNGEON_LIST_H 

#include <stdint.h>

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
 * Initialises the dungeon object list. Must be called before using the list
 * 
 * @return void
 */
void object_dungeon_list_init( void );

/**
 * Add the object to the list of dungeon objects
 * Object must not belong to another list!
 *
 * @param *obj_ptr pointer to object 
 * 
 * @return uint8_t  1 success 0 fail
 */
void object_dungeon_list_add(object_t *const obj_ptr);

/**
 * Remove the object from the list of dungeon objects
 *
 * @param *obj_ptr pointer to object 
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t object_dungeon_list_remove(object_t *const obj_ptr);

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
void object_dungeon_list_drawall( void );

/**
 * Returns the first object in the dungeon object list
 * 
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_dungeon_list_first( void );

/**
 * Returns the next object in the dungeon object list
 * 
 * @return *object_t    pointer to next object or 0 if no more objects
 */
object_t *object_dungeon_list_next(object_t *obj_ptr);

/**
 * Returns the first object in dungeon object list at position x, y
 * 
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_dungeon_list_first_at(uint8_t x, uint8_t y);

/**
 * Returns the next object in dungeon object list at position x, y
 * 
 * @param *obj_p    previous object at x, y
 * @param x         dungeon x position
 * @param y         dungeon y position
 * 
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_dungeon_list_next_at(object_t *obj_p, uint8_t x, uint8_t y);

/**
 * Returns the first object in dungeon object list of a requested type at position x, y
 * 
 * the function calls the supplied function to determine if an object at x,y is of the requested type 
 * e.g. passing a pointer to the function 'uint_8t isopen(const object_t *obj_p)' will return the first object that can be opened
 * 
 * @param x dungeon x position
 * @param y dungeon y position
 * @param uint8_t (*isfunc_p)(struct object_s *) pointer to function that tests if object is of requested type
 * 
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_dungeon_list_first_is_at(uint8_t x, uint8_t y, object_is_a);

/**
 * Returns the next object in dungeon object list of a requested type at position x, y
 * 
 * @param *obj_p    previous object at x, y
 * @param x         dungeon x position
 * @param y         dungeon y position
 * @param uint8_t (*isfunc_p)(struct object_s *) pointer to function that tests if object is of requested type
 * 
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_dungeon_list_next_is_at(object_t *obj_p, uint8_t x, uint8_t y, object_is_a);



#endif
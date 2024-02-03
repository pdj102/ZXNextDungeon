/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

 ***************************************************/

#ifndef OBJECT_H 
    #define OBJECT_H 

#include <stdint.h>
#include <adt/p_forward_list.h>

#include "tilemap.h"


/***************************************************
 * types
 ***************************************************/

typedef enum {PHYSICAL, ITEM, CREATURE} object_class_e;

typedef enum object_type_s {
    // Physical
    DOOR,
    CHEST,
    TRAP,

    // ITEM
    FOOD,
    POTION,
    SCROLL,
    MELEE_WEAPON,
    RANGED_WEAPON,
    ARMOUR,
    SHIELD, 
    RING, 
    WAND,

    // CREATURE
    HUMANOID,
    BEAST,
    OOZE,
    PLANTS,
    UNDEAD

    } object_type_e;

typedef enum object_subtype_s {

    // Physical
    DOOR_OPEN,
    DOOR_CLOSED,
    CHEST_LARGE,

    TRAP_NOISE,

    // Items
    FOOD_BREAD,

    POTION_HEALING,
    POTION_SPEED,

    SCROLL_FIREBALL,

    MELEE_WEAPON_SWORD,

    RANGED_WEAPON_SLING,

    ARMOUR_LEATHER,

    RING_HP,

    WAND_FIREBALL,
    
    // Creatures
    HUMANOID_PLAYER, 
    
    HUMANOID_HUMAN,

    BEAST_SNAKE,

    OOZE_SLIME,

    PLANT_WITHERWEED,

    UNDEAD_SKELETON
    } object_subtype_e;


typedef struct object_s
{
    void                    *next;              /**< objects can be part of a list of objects. Next pointer must be first 2 bytes in struct */
    uint8_t                 free;               /**< 1 if object slot is free */
    tilemap_tile_t          tilemap_tile;
    uint8_t                 x;
    uint8_t                 y;
    uint8_t                 blocking;           /**< 1 if the object is blocking 0 if non-blocking */
    p_forward_list_t        obj_list;           /**< Objects can contain a list of objects e.g. the players inventory or a chest */
    object_class_e          class;
    object_type_e           type;
    object_subtype_e        subtype;
    int8_t                  attr_1;             /**< attribute 1. Purpose determined by object's subtype */
    int8_t                  attr_2;             /**< attribute 2. Purpose determined by object's subtype */
    uint16_t                name_token;
    uint8_t                 count;              /**< number of objects*/
    struct creature_s       *creature_p;        /**< pointer to associated creature object*/
} object_t;

// Typedef for object is_a functions
typedef uint8_t (*object_is_a)(object_t *);

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
void object_init( void );

/**
 * Find a free object slot
 * 
 * @return   object_t* pointer to a free object slot or 0 if no free slot
 */
object_t* object_getfree( void );

/**
 * Create an  object of type subtype at xm y.  
 *
 * @param subtype object subtype to create
 * @param x dungeon x position
 * @param y dungeon y position
 * @return pointer to created object or NULL on failed to create
 */
// object_t* object_create(object_subtype_e subtype, uint8_t x, uint8_t y);

/**
 * Delete an object and all its contained objects
 * 
 * The object must have been removed from any object lists before calling delete
 * 
 * @param   *obj_p  Object to destroy
 */
void object_delete(object_t *obj_p);

/**
 * Free an object
 * 
 * Marks an object slot as free for use 
 * 
 * @param   *obj_p  Object to free
 */
// void object_free(object_t *obj_p);


#endif
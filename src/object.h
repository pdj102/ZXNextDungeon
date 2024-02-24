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

    // =========== Items =============
    
    // food
    FOOD_BREAD,

    // Potions
    POTION_HEALING,
    POTION_SPEED,

    // melee weapons
    MELEE_WEAPON_CLUB,
    MELEE_WEAPON_DAGGER,
    MELEE_WEAPON_AXE,
    MELEE_WEAPON_SHORT_SWORD,
    MELEE_WEAPON_LONG_SWORD,
    MELEE_WEAPON_GREAT_SWORD,    

    // ranged weapons
    RANGED_WEAPON_SLING,
    RANGED_WEAPON_DART,
    RANGED_WEAPON_SHORTBOW,
    RANGED_WEAPON_LONGBOW,
    RANGED_WEAPON_CROSSBOW,    

    // armour
    ARMOUR_PADDED,
    ARMOUR_LEATHER,
    ARMOUR_STUDDED_LEATHER,
    ARMOUR_CHAIN_SHIRT,
    ARMOUR_SCALE_MAIL,
    ARMOUR_HALF_PLATE,
    ARMOUR_RING_MAIL,
    ARMOUR_CHAIN_MAIL, 
    ARMOUR_SPLINT,
    ARMOUR_PLATE,

    // rings
    RING_HP,
    RING_SPEED,

    // scrolls
    SCROLL_FIREBALL,


    WAND_FIREBALL,
    
    // =========== Creatures =============

    // humanoid
    HUMANOID_PLAYER, 
    HUMANOID_HUMAN,

    // Beast
    BEAST_SNAKE,

    // Ooze
    OOZE_GREY,
    OOZE_SLIME,

    // plant
    PLANT_WITHERWEED,

    // undead
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
 * Free an object slot 
 * 
 * NB objects should be destroyed by calling object_destroyed() 
 * 
 * @param   *obj_p  Object to mark free
 */
void object_free(object_t *const obj_p);


#endif
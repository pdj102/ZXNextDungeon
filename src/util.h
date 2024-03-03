/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Useful utils

 ***************************************************/

#ifndef UTIL_H 
    #define UTIL_H 

#include <inttypes.h>


/***************************************************
 * types
 ***************************************************/
typedef enum direction_e {NO_DIR, N, NE, E, SE, S, SW, W, NW} direction_t;

typedef struct coord_s
{
    uint8_t x;
    uint8_t y;
} coord_t;


/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * @brief returns manhattan distance
 * 
 */
uint8_t util_distance_manhattan(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2);

/**
 * @brief returns an area centred on x, y of 2r clamped to dungeon map
 * 
 * @param x centre of area
 * @param y centre of area
 * @param r area size radius
 * @param x1 area
 * @param y1 area
 * @param x2 area
 * @param y2 area
 * 
 */
void util_return_area_xy_r(uint8_t x, uint8_t y, uint8_t r, uint8_t *x1, uint8_t *y1, uint8_t *x2, uint8_t *y2);

void util_dir_to_dxdy(direction_t d, int8_t *dx, int8_t *dy);

void util_assert_f(const char *message, const char *file, unsigned line);

#ifdef NDEBUG
    #define util_assert(_Expression) ((void)0)
#else /* !defined (NDEBUG) */
    #define util_assert(_Expression) if (!(_Expression)) util_assert_f(#_Expression,__FILE__,__LINE__);
#endif /* !defined (NDEBUG) */

#include <assert.h>

#endif
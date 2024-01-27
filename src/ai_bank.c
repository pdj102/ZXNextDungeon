/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_bank.h"

#include <stdint.h>
#include <stdlib.h>         // abs()

#include "ai.h"
#include "ai_pathfind_bank.h"

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"

#include "object.h"
#include "object_list.h"

#include "object_dungeon_list.h"

#include "creature.h"
#include "creature_move.h"
#include "creature_melee_strike.h"
#include "creature_damage.h"



/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
void ai_attacking(creature_t *creature_p);
uint8_t distance_manhattan(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void ai_init_b(ai_t *ai_p)
{
    // globaldata.ai.ai_creature_p = creature_p;
}

void ai_turn_b( creature_t *creature_p )
{
    creature_p->energy = 0;
    #ifdef DEBUG_ERROR
        text_printf("DEBUG: AI TURN %t\n", creature_p->obj_p->name_token );
    #endif

    switch (creature_p->ai.state)
    {
        case SLEEPING:
            return;
        case GUARDING:
            // TODO see player attack or flee
            return;
        case ATTACKING:
            ai_attacking(creature_p);
            return;
        default:
            return;
    }
}

void ai_attacking(creature_t *creature_p)
{
    //TODO if target in melee reach attempt to strike
    //TODO ranged attacks
    //TODO dont assume player is target?
    //TODO lost target. Revert to another state

    direction_t d;
    coord_t c;
    uint8_t moved = 0;
    uint8_t distance;
    uint8_t damage_roll;

    c.x = creature_p->obj_p->x;
    c.y = creature_p->obj_p->y;

    // Distance to target
    distance = distance_manhattan(c.x, c.y, globaldata.player.player_creature_p->obj_p->x, globaldata.player.player_creature_p->obj_p->y);

    // In range of melee strike (adjacent either up, down, left or right)
    if ( distance== 1)
    {
        creature_melee_strike(creature_p, globaldata.player.player_creature_p);
        return;
    }    

    d = ai_pathfind_direction_to_player_b( &c );

    switch (d)
    {
    case NO_DIR:
        break;
    case N:
        moved = creature_move_by(creature_p, 0, -1);
        break;
    case S:
        moved = creature_move_by(creature_p, 0, 1);
        break;
    case W:
        moved = creature_move_by(creature_p, -1, 0);
        break;
    case E:
        moved = creature_move_by(creature_p, 1, 0);
        break;
    default:
        break;
    }

    if (moved)
    {
        return;
    }


}

uint8_t distance_manhattan(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2)
{
    uint8_t x = x1 > x2 ? x1 - x2 : x2 - x1;
    uint8_t y  = y1 > y2 ? y1 - y2 : y2 - y1;

    return x + y;
}

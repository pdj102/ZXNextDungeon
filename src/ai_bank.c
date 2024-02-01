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
#include "object_strike.h"

#include "creature.h"
#include "creature_list.h"
#include "creature_move.h"
#include "creature_melee_strike.h"
#include "creature_damage.h"



/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
void ai_attacking_b(creature_t *attacker_p);
void ai_guarding_b(creature_t *attacker_p);
void ai_lost_target_b( creature_t *creature_p );
uint8_t distance_manhattan_b(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void ai_turn_b( creature_t *creature_p )
{
    creature_p->energy = 0;

    switch (creature_p->ai.state)
    {
        case SLEEPING:
            return;
        case GUARDING:
            ai_guarding_b(creature_p);
            return;
        case ATTACKING:
            ai_attacking_b(creature_p);
            return;
        default:
            return;
    }
}

uint8_t ai_is_enemy_b(creature_t *attacker_p, creature_t *target_p)
{
    if (attacker_p == target_p)
    {
        return 0;
    }

    return 1;
}
/**
 * @brief AI turn - guarding
 * 
 * @param *guarding_p   pointer to AI creature
 * 
 * Behaviour
 * 1) Check if any creature is adjacent
 * 2) It adjacent perform melee strike
 * 3) Otherise, do nothing
 * 
 */
void ai_guarding_b(creature_t *attacker_p)
{
    //TODO1 plants should only attack creatures not other plants
    creature_t *target_p = creature_list_first_is_a2_within_rect(attacker_p->obj_p->x - 1, attacker_p->obj_p->y - 1, attacker_p->obj_p->x + 1, attacker_p->obj_p->y + 1, 
    attacker_p, 
    ai_is_enemy_b);

    if (target_p)
    {
        creature_melee_strike(attacker_p, target_p);
    }
}


/** 
 * @brief AI turn - attacking
 * 
 * @param *attacker_p    Pointer to AI creature
 * 
 * Behaviour 
 * 1) Check target still valid? Call lost target if not
 * 2) If adjacent to target perform melee strike 
 * 3) Otherwise move towards target
 * 
 * TODO - ranged attacks
 * TODO - handle unable to find target 
 * 
 */
void ai_attacking_b(creature_t *attacker_p)
{
    direction_t d;
    uint8_t distance;
    creature_t *target_p;

    target_p = attacker_p->ai.target;

    // Is target valid?
    if (target_p->hp == 0)
    {
        ai_lost_target_b( attacker_p );
        return;
    }

    // Melee strike if adjacent 
    // Distance to target
    distance = distance_manhattan_b(attacker_p->obj_p->x, attacker_p->obj_p->y, target_p->obj_p->x, target_p->obj_p->y);

    // In range of melee strike (adjacent either up, down, left or right)
    if ( distance== 1)
    {
        creature_melee_strike(attacker_p, target_p);
        return;
    }    

    // Move towards target
    d = ai_pathfind_direction_to_player_b( attacker_p->obj_p->x, attacker_p->obj_p->y );

    switch (d)
    {
    case NO_DIR:
        break;
    case N:
        creature_move_by(attacker_p, 0, -1);
        break;
    case S:
        creature_move_by(attacker_p, 0, 1);
        break;
    case W:
        creature_move_by(attacker_p, -1, 0);
        break;
    case E:
        creature_move_by(attacker_p, 1, 0);
        break;
    default:
        break;
    }
}

/**
 * Notify AI of an attack by another creature
 * 
 * @return void
 */
void ai_is_attacked_b(creature_t *target_p, creature_t *attacker_p)
{
    // Has the creature been killed?
    if (target_p->hp == 0)
    {
        target_p->ai.state = DEAD;
    }

    switch (target_p->ai.state)
    {
        case SLEEPING:
            text_printf("%t WAKES UP\n", (unsigned int) target_p->obj_p->name_token);
            target_p->ai.state = ATTACKING;
            target_p->ai.target = attacker_p;        
        case AWAKE:
            target_p->ai.state = ATTACKING;
            target_p->ai.target = attacker_p;
            break;
        case GUARDING:
            target_p->ai.target = attacker_p;
            break;
        case ATTACKING:
            // TODO - possibly change target if attacker is different to current target
            // TODO - possibly flee 
            break;
        default:
            break;
    }
}

void ai_lost_target_b( creature_t *creature_p )
{
    // TODO Add support for parties and select next target in party
    creature_p->ai.state = AWAKE;
    creature_p->ai.target = 0;      
}

uint8_t distance_manhattan_b(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2)
{
    uint8_t x = x1 > x2 ? x1 - x2 : x2 - x1;
    uint8_t y  = y1 > y2 ? y1 - y2 : y2 - y1;

    return x + y;
}

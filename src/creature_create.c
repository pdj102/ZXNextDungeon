/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

**************************************************/

#include "creature_create.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions    

#include "creature_create_bank.h"
#include "object.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions
 ***************************************************/

creature_t* creature_create(object_subtype_e obj_subtype, uint8_t x, uint8_t y)
{
    uint8_t current_bank;
    creature_t *c;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    c = creature_create_b(obj_subtype, x, y);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return c;    
}

void creature_create_reset_base_stats(creature_t *creature_p)
{
    uint8_t current_bank;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    creature_create_reset_base_stats_b(creature_p);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);
}

uint8_t creature_create_base_speed(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_speed_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;    
}
uint8_t creature_create_base_hp(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_hp_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

uint8_t creature_create_base_magic(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_magic_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

uint8_t creature_create_base_ac(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_ac_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

creature_attack_t creature_create_base_melee(object_subtype_e subtype)
{
    uint8_t current_bank;
    creature_attack_t a;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    a = creature_create_base_melee_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return a;
}

uint8_t creature_create_base_str(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_str_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

uint8_t creature_create_base_dex(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_dex_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}
uint8_t creature_create_base_con(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_con_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

uint8_t creature_create_base_inte(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_inte_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

uint8_t creature_create_base_wis(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_wis_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

uint8_t creature_create_base_cha(object_subtype_e subtype)
{
    uint8_t current_bank;
    uint8_t v;

    /* Remember current bank*/
    current_bank = ZXN_READ_MMU6();

    /* Map Create Creature (bank 22) into ZX Spectrum 8k MMU slot 6 */
    /* Call banked code */ 
    ZXN_WRITE_MMU6(22);    
    v = creature_create_base_cha_b(subtype);

    /* restore previous bank */
    ZXN_WRITE_MMU6(current_bank);

    return v;
}

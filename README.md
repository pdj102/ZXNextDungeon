# Dungeon - A rogue like for the ZX Spectrum Next

Note: this project is in development

## To compile

Compile using z88dk C compiler and GNU make

Set the z88dk compiler paths for the library and config files
- set z88dk to point to the z88dk directory
- $Env:Z80_OZFILES=$Env:z88dk+"\Lib\"
- $Env:ZCCCFG=$Env:z88dk+"\Lib\Config"

Run 'make all'

## Memory map
The game uses Spectrum Next memory banking to access more then 64Kb

8k Slots    Memory              8k Bank     Use and notes

Slot 0      0x0000 - 0x1fff     16          Dungeon Map 
                                            (default ROM is mapped out)

Slot 1      0x2000 - 0x3fff     17          Entities, Creatures, Items and Effects
                                            (by default mapped to ROM)

            0x2000 - 0x23ff                 Entities use first 1k of slot 1

            0x2400 - 0x2bff                 Creatures use next 2k of slot 1

Slot 2      0x4000 - 0x5fff     10          Tilemap located at 0x4000 - 0x49ff
                                            Tile definitions at 0x4a00 - 4f20 (assuming 41 tile definitions at 4 * 8 bytes each)
                                            (default use ULA screen. Game disables ULA screen)

Slot 3      0x6000 - 0x7fff     11          Not used 
                                            (default is contended ram. Could be used by game. Turn off contended memory first with next reg 0x08)

Slot 4      0x8000 - 0x9fff     4           Common game code (not banked out)

Slot 5      0xa000 - 0xbfff     5           Common game code (not banked out)
                                            Top of stack located at 0xbfff (set by pragma)

Slot 6      0xc000 - 0xfddd     17-31       Banked game code & data
                                            (banks 16 to 31 are extra RAM on Spectrum Next)

Slot 7      0xe000 - 0xfff      17-31       Banked game code & data

## z88dk compiler notes

CRT targets are documented here
 https://github.com/z88dk/z88dk/blob/master/libsrc/_DEVELOPMENT/target/zxn/zxn_crt.asm.m4

 Incude the <arch/zxn.h> for spectrum next functions (SDCC compiler)
https://github.com/z88dk/z88dk/tree/master/include/_DEVELOPMENT/sdcc/arch

z88dk has two compilers SCCZ80 and ZSDCC 
The ZSDCC compiler is recommended for the ZX Spectrum next as it produces more compact code

z88dk has two libraries Classic and New 
There are in turn two versions of the New library, sdcc_ix and sdcc_iy
Use the sdcc_iy library as it produces smaller faster code. The compiler will use IX as its frame pointer
The sdcc_iy library is selected with -clib=sdcc_iy

For information on memory banking
https://www.z88dk.org/forum/viewtopic.php?t=9995
https://www.z88dk.org/forum/viewtopic.php?t=10464


## Moving stack notes

From forums: The default setting for CLIB_MALLOC_HEAP_SIZE (-1) will try to create a heap between the end of BSS and the bottom of the stack. But since you moved your stack below BSS, the crt computes a negative heap size and silently causes the program to exit, which will cause a crash if you move your SP down low enough.

Another setting is to specify a size > 14 bytes. If that's done the heap will be created in the BSS section.

And a third option is to specify the top address of the heap so that the heap is created between the end of BSS and that address. In this case, the top address is given as a negative value. Eg if you set CLIB_MALLOC_HEAP_SIZE = -0xffff, then the heap will extend from the end of BSS up to and including address 0xffff.
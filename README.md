# Dungeon - A rogue like for the ZX Spectrum Next

Note: this project is in development

## Development environment

- Visual Studio IDE
- github source code repository 
- z88dk compiler
- CSpect spectrum next emulator
- https://zx.remysharp.com/sprites/#sprite-editor


## To compile

Compile using z88dk C compiler and GNU make

Set the z88dk compiler paths for the library and config files
- set z88dk to point to the z88dk directory
- $Env:Z80_OZFILES=$Env:z88dk+"\Lib\"
- $Env:ZCCCFG=$Env:z88dk+"\Lib\Config"

Run 'make all'

The executable is a .nex file called dungeon.nex

## To run

Run dungeon.nex using the CSpect emulator

- Start CSpect
- F2 to select file to run
- Select dungeon.nex


## Memory map notes
The game uses Spectrum Next memory banking to access more then 64Kb

MMU slots 6 & 7 are used for banked game code and data. 

For details on memory map see memory_map.h


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


## Sprite and palette editor

### sprites

To load the sprites in the editor 
- Toggle 8x8 on
- Select 4bit
- upload .spr file
- upload palette file

To save the sprites from the editor
- save the .spr file (to reload into the editor later)

To export sprite data to source code
-  select sprites
-  select 8x8
- bytes per line 16
- Note each sprite is 16 bytes * 8 bytes and contains 4 tile definitions
- select line prefix db
- select byte format hex 0x
- cut n paste sprite data into tilemap_tile_defns_data.asm
- set the sprite_count to the number of sprites to load 
- define the tiles in tilemap_tile_defns.h 

each tile definition is 16*16 pixels held as 16 bytes * 2 bytes (each byte = 2 pixels)
64 sprites = 8,192 = 8KiB 

TO DO as the org is 0x4a00 some of the sprite defs do not fit in section page 10 they overflow into page 11 if more sprites are required the data needs to go in the next memory page


### palette

To export palette into source code 
- toggle export palette on
- range e.g. 0 to 112 (16 bytes per line )
- format 8bit
- bytes per line 16 (16 bytes per tile palette)
- line prefix db
- byte format hex 0x

- cut n paste palette data into palette_data.asm
- set palette_count to the size of the palette data e.g. 112 bytes
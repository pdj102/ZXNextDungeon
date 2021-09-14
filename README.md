# Dungeon - A rogue like for the ZX Spectrum Next

Note: this project is in development

## To compile

Compile using z88dk C compiler

Set the z88dk compiler paths for the library and config files
- set z88dk to point to the z88dk directory
- $Env:Z80_OZFILES=$Env:z88dk+"\Lib\"
- $Env:ZCCCFG=$Env:z88dk+"\Lib\Config"

Target ZX Spectrum with NEW library and using zsdcc compiler
zcc +zxn -vn -SO3 -clib=sdcc_iy -startup=1 --max-allocs-per-node200000 .\src\main.c .\src\dungeon_map.c -create-app -subtype=nex

- +zx           Choose zx spectrum as target
- -SO3          Optimization level 3
- -vn           verbose off. -v verbose on
- -startup      select the C Run Time to run before main is called. 0 setups IO streams. 31 no iostreams to save memory  
- -clib=sdcc_iy Compile using the sdcc_iy library (will use zsdcc compiler)
- --max-allocs-per-node200000 Optimisation
- -create-app   Run the create-app to create an executable 
- -subtype=new  Create a nex executable file - can be loaded by emulator

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


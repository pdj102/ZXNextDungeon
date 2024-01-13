# set variables
CC=zcc				# Frontend for the z88dk Cross-C Compiler
AS=zcc
TARGET=+zxn
VERBOSITY=-vn		# verbose off -vn on -v
CRT=31 				# CRT=31 no stdin stdout stderr streams setup
# CRT=1 setup stdin stdout stderr streams

PRAGMA_FILE=zpragma.inc

# compiler optimisation parameters 
# 
C_OPT_FLAGS=-SO3 --max-allocs-per-node200000
# C_OPT_FLAGS=-SO3 

# Compile with new library using SDCC. Works but bugs with <stdarg.h>
CFLAGS=$(TARGET) $(VERBOSITY) -c $(C_OPT_FLAGS) -compiler=sdcc -clib=sdcc_iy -pragma-include:$(PRAGMA_FILE)
LDFLAGS=$(TARGET) $(VERBOSITY) -clib=sdcc_iy -pragma-include:$(PRAGMA_FILE)
ASFLAGS=$(TARGET) $(VERBOSITY) -c

# Compile with classic libray using SDCC. Does not work
# CFLAGS=$(TARGET) $(VERBOSITY) -c $(C_OPT_FLAGS) -compiler=sdcc -pragma-include:$(PRAGMA_FILE)
# LDFLAGS=$(TARGET) $(VERBOSITY) -clib=classic -lndos -pragma-include:$(PRAGMA_FILE)
# ASFLAGS=$(TARGET) $(VERBOSITY) -c

# place .c and .asm source files in ./src
# warning do not create a .c and .asm with the same name 
# object files are placed in ./obj
# binary output is placed in ./bin
OBJDIR=./obj
SRCDIR=./src
BINDIR=./bin

# use wildcard to select all .c files in src directory
CFILES=$(wildcard $(SRCDIR)/*.c)

# use wildcard to select all .asm files in src directory
AFILES=$(wildcard $(SRCDIR)/*.asm)

# use patsubst to name .o file for each .c file name in CFILES
OFILESC=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CFILES))

# use patsubst to name .o file for each .asm file name in AFILES
OFILESA=$(patsubst $(SRCDIR)/%.asm,$(OBJDIR)/%.o,$(AFILES))

# consolidate list of .o files for C and ASM
OFILES = $(OFILESC) $(OFILESA)


# program output name
PROGRAM=dungeon.nex

# program output name
ASSEMBLEY=dungeon.asm

# ####################################################################################################################################
# PAGE_18
# Target for dungeon map generator code and data
# - dungeon_map_generator_bank.o 
$(OBJDIR)/dungeonmap_generator_bank.o: $(SRCDIR)/dungeonmap_generator_bank.c $(SRCDIR)/dungeonmap_generator_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_18 --constsegPAGE_18 -o $@ $<

# ####################################################################################################################################
# PAGE_20
# Target for object creator code and data
# - object_create_bank.o 
$(OBJDIR)/object_create_bank.o: $(SRCDIR)/object_create_bank.c $(SRCDIR)/object_create_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_20 --constsegPAGE_20 -o $@ $<

# ####################################################################################################################################
# PAGE_21
# Target for text token and data 
# - text_token_bank.o 
$(OBJDIR)/text_token_bank.o: $(SRCDIR)/text_token_bank.c $(SRCDIR)/text_token_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_21 --constsegPAGE_21 -o $@ $<	

# ####################################################################################################################################
# PAGE_22
# Target for create creature and data 
# - create_creature_bank.o 
$(OBJDIR)/create_creature_bank.o: $(SRCDIR)/create_creature_bank.c $(SRCDIR)/create_creature_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_21 --constsegPAGE_21 -o $@ $<	

# ####################################################################################################################################
# target for *.o : dependency is *.c and *.h 
# This rule requires .c file to have a .h file
# call C compiler
# example to compile ./src/test.c execute "make ./obj/test.o"
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) -o $@ $<

# ####################################################################################################################################
# target for *.o : dependency is *.asm
# call assembler
# example to compile ./src/test2.asm execute "make ./obj/test2.o"
$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

# ####################################################################################################################################
# target for all : dependency is $program
all : $(PROGRAM)

# ####################################################################################################################################
# target for $program : dependency is all object files
$(PROGRAM) : $(OFILES)
	 $(CC) $(LDFLAGS) -startup=$(CRT) $(OFILES) -o $(BINDIR)/$(PROGRAM) -create-app -subtype=nex

# ####################################################################################################################################
.PHONY: clean
clean:
	del .\obj\*.o 
	del .\bin\*.bin
	del .\bin\*.nex 
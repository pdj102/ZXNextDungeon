# set variables
# set compiler to zcc 
# Windows
# CC=zcc
# AS=zcc
# Linux flatpack
CC=z88dk.zcc
AS=z88dk.zcc

TARGET=+zxn
VERBOSITY=-vn		# verbose off -vn on -v

# CRT=31 no stdin stdout stderr streams setup
CRT=31 
#CRT=1 setup stdin stdout stderr streams
PRAGMA_FILE=zpragma.inc

# compiler optimisation parameters 
C_OPT_FLAGS=-SO3 --max-allocs-per-node200000

CFLAGS=$(TARGET) $(VERBOSITY) -c $(C_OPT_FLAGS) -compiler sdcc -clib=sdcc_iy -pragma-include:$(PRAGMA_FILE)
LDFLAGS=$(TARGET) $(VERBOSITY) -clib=sdcc_iy -pragma-include:$(PRAGMA_FILE)
ASFLAGS=$(TARGET) $(VERBOSITY) -c

# place .c and .asm source files in ./src
# warning do not create a .c and .asm with the  same name 
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
# DEFAULT TARGET 
# target for all : $program
all : $(PROGRAM)

# ####################################################################################################################################
# PAGE_18
# Target for dungeon map generator code and data
# - dungeon_map_generator_bank.o 
$(OBJDIR)/dungeon_map_generator_bank.o: $(SRCDIR)/dungeon_map_generator_bank.c $(SRCDIR)/dungeon_map_generator_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_18 --constsegPAGE_18 -o $@ $<

# ####################################################################################################################################
# PAGE_19
# target for ai* _bank
# - ai_pathfind
# - ai
$(OBJDIR)/ai_pathfind_bank.o: $(SRCDIR)/ai_pathfind_bank.c $(SRCDIR)/ai_pathfind_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_19 --constsegPAGE_19 -o $@ $<

$(OBJDIR)/ai_bank.o: $(SRCDIR)/ai_bank.c $(SRCDIR)/ai_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_19 --constsegPAGE_19 -o $@ $<

# ####################################################################################################################################
# PAGE 20
# target for player_inventory_bank*
$(OBJDIR)/player_inventory_bank.o: $(SRCDIR)/player_inventory_bank.c $(SRCDIR)/player_inventory_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_20 --constsegPAGE_20 -o $@ $<

# ####################################################################################################################################
# PAGE 21
# target for token_bank*
$(OBJDIR)/token_bank.o: $(SRCDIR)/token_bank.c $(SRCDIR)/token_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_21 --constsegPAGE_21 -o $@ $<

# ####################################################################################################################################
# DEFAULT  PAGES
# target for *.o - call C compiler
# example to compile ./src/test.c execute "make ./obj/test.o"
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(PRAGMA_FILE)
	$(CC) $(CFLAGS) -o $@ $<


# target for *.o - call assembler
# example to compile ./src/test2.asm execute "make ./obj/test2.o"
$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<



# target for $program : dependency is all object files
$(PROGRAM) : $(OFILES)
	 $(CC) $(LDFLAGS) -startup=$(CRT) $(OFILES) -o $(BINDIR)/$(PROGRAM) -create-app -subtype=nex


.PHONY: clean
clean:
	del .\obj\*.o 
	del .\bin\*.bin
	del .\bin\*.nex 
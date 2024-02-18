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

# Compile with new library using SDCC
CFLAGS=$(TARGET) $(VERBOSITY) -c $(C_OPT_FLAGS) -compiler=sdcc -clib=sdcc_iy -pragma-include:$(PRAGMA_FILE) -DDEBUG -DDEBUG_PATHFIND
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
$(OBJDIR)/dungeonmap_generator_bank.o: $(SRCDIR)/dungeonmap_generator_bank.c $(SRCDIR)/dungeonmap_generator_bank.h $(SRCDIR)/dungeonmap_generator_bank_data.asm $(PRAGMA_FILE)
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
$(OBJDIR)/creature_create_bank.o: $(SRCDIR)/creature_create_bank.c $(SRCDIR)/creature_create_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_22 --constsegPAGE_22 -o $@ $<	

# ####################################################################################################################################
# PAGE_24
# Target for player code 
# - player_bank.o 
$(OBJDIR)/player_bank.o: $(SRCDIR)/player_bank.c $(SRCDIR)/player_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<
# - player_open_bank.o 
$(OBJDIR)/player_open_bank.o: $(SRCDIR)/player_open_bank.c $(SRCDIR)/player_open_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<
# - player_close_bank.o 
$(OBJDIR)/player_close_bank.o: $(SRCDIR)/player_close_bank.c $(SRCDIR)/player_close_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<	
# - player_quaff_bank.o 
$(OBJDIR)/player_quaff_bank.o: $(SRCDIR)/player_quaff_bank.c $(SRCDIR)/player_quaff_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<		
# - player_drop_bank.o 
$(OBJDIR)/player_drop_bank.o: $(SRCDIR)/player_drop_bank.c $(SRCDIR)/player_drop_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<
# - player_strike_bank.o 
$(OBJDIR)/player_strike_bank.o: $(SRCDIR)/player_strike_bank.c $(SRCDIR)/player_strike_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<
# - player_inventory_bank.o 
$(OBJDIR)/player_inventory_bank.o: $(SRCDIR)/player_inventory_bank.c $(SRCDIR)/player_inventory_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<
# - player_move_bank.o 
$(OBJDIR)/player_move_bank.o: $(SRCDIR)/player_move_bank.c $(SRCDIR)/player_move_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<
# - player_pickup_bank.o 
$(OBJDIR)/player_pickup_bank.o: $(SRCDIR)/player_pickup_bank.c $(SRCDIR)/player_pickup_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<	
# - player_wield_bank.o 
$(OBJDIR)/player_wield_bank.o: $(SRCDIR)/player_wield_bank.c $(SRCDIR)/player_wield_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<	
# - player_calc_stats_bank.o 
$(OBJDIR)/player_calc_stats_bank.o: $(SRCDIR)/player_calc_stats_bank.c $(SRCDIR)/player_calc_stats_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<
# - player_takeoff_bank.o 
$(OBJDIR)/player_takeoff_bank.o: $(SRCDIR)/player_takeoff_bank.c $(SRCDIR)/player_takeoff_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<	
# - player_equipment_bank.o 
$(OBJDIR)/player_equipment_bank.o: $(SRCDIR)/player_equipment_bank.c $(SRCDIR)/player_equipment_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_24 --constsegPAGE_24 -o $@ $<	
	

# ####################################################################################################################################
# PAGE_25
# Target for UI code
# - ui_stats_bank.o 
$(OBJDIR)/ui_stats_bank.o: $(SRCDIR)/ui_stats_bank.c $(SRCDIR)/ui_stats_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_25 --constsegPAGE_25 -o $@ $<

# ####################################################################################################################################
# PAGE_26
# Target for AI code
# - ai_bank.o
$(OBJDIR)/ai_bank.o: $(SRCDIR)/ai_bank.c $(SRCDIR)/ai_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_26 --constsegPAGE_26 -o $@ $<
# - ai_attacking_melee_bank.o 
$(OBJDIR)/ai_attacking_melee_bank.o: $(SRCDIR)/ai_attacking_melee_bank.c $(SRCDIR)/ai_attacking_melee_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_26 --constsegPAGE_26 -o $@ $<	
# - ai_attacking_ranged_bank.o 
$(OBJDIR)/ai_attacking_ranged_bank.o: $(SRCDIR)/ai_attacking_ranged_bank.c $(SRCDIR)/ai_attacking_ranged_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_26 --constsegPAGE_26 -o $@ $<		
# - ai_guarding_bank.o 
$(OBJDIR)/ai_guarding_bank.o: $(SRCDIR)/ai_guarding_bank.c $(SRCDIR)/ai_guarding_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_26 --constsegPAGE_26 -o $@ $<
# - ai_sleeping_bank.o 
$(OBJDIR)/ai_sleeping_bank.o: $(SRCDIR)/ai_sleeping_bank.c $(SRCDIR)/ai_sleeping_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_26 --constsegPAGE_26 -o $@ $<
# - ai_goto_bank.o 
$(OBJDIR)/ai_goto_bank.o: $(SRCDIR)/ai_goto_bank.c $(SRCDIR)/ai_goto_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_26 --constsegPAGE_26 -o $@ $<	
# - ai_wandering_bank.o 
$(OBJDIR)/ai_wandering_bank.o: $(SRCDIR)/ai_wandering_bank.c $(SRCDIR)/ai_wandering_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_26 --constsegPAGE_26 -o $@ $<	

# ####################################################################################################################################
# PAGE_27
# Target for Pathfinding code
# - pathfind_bank.o 
$(OBJDIR)/pathfind_bank.o: $(SRCDIR)/pathfind_bank.c $(SRCDIR)/pathfind_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_27 --constsegPAGE_27 -o $@ $<		
# - pathfind_breadth_first_search_bank.o 
$(OBJDIR)/pathfind_breadth_first_search_bank.o: $(SRCDIR)/pathfind_breadth_first_search_bank.c $(SRCDIR)/pathfind_breadth_first_search_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_27 --constsegPAGE_27 -o $@ $<
# - pathfind_fast_a_star_bank.o 
$(OBJDIR)/pathfind_fast_a_star_bank.o: $(SRCDIR)/pathfind_fast_a_star_bank.c $(SRCDIR)/pathfind_fast_a_star_bank.h $(PRAGMA_FILE)
	$(CC) $(CFLAGS) --codesegPAGE_27 --constsegPAGE_27 -o $@ $<				

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
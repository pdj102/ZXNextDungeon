# set variables
CC=zcc
AS=zcc
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

# place source files in ./src
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

# target for *.o - call C compiler
# example to compile ./src/test.c execute "make ./obj/test.o"
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(PRAGMA_FILE)
	$(CC) $(CFLAGS) -o $@ $<

# target for *.o - call assembler
# example to compile ./src/test2.asm execute "make ./obj/test2.o"
$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

# target for all : $program
all : $(PROGRAM)

# target for $program : dependency is all object files
$(PROGRAM) : $(OFILES)
	 $(CC) $(LDFLAGS) -startup=$(CRT) $(OFILES) -o $(BINDIR)/$(PROGRAM) -create-app -subtype=nex

# target for assembley : dependency all 
# assembley : $(ASSEMBLEY)

# target for $assembley : dependency all object files
# $(ASSEMBLEY) : $(OFILES)
#	 $(CC) $(LDFLAGS) -startup=$(CRT) $(OFILES) -a $(BINDIR)/$(ASSEMBLEY)

.PHONY: clean
clean:
	del .\obj\*.o 
	del .\bin\*.bin
	del .\bin\*.nex 
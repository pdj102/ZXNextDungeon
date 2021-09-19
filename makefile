# set variables
CC=zcc
AS=zcc
TARGET=+zxn
VERBOSITY=-vn
CRT=31
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

# use patsubst to name .o file for each .c file name in CFILES
OFILES=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CFILES))

# program output name
PROGRAM=dungeon.nex

# target for *.o - call C compiler
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(PRAGMA_FILE)
	$(CC) $(CFLAGS) -o $@ $<

# target for *.o - call assembler
$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

# target for all : $program
all : $(PROGRAM)

# target for $program : all object files
$(PROGRAM) : $(OFILES)
	 $(CC) $(LDFLAGS) -startup=$(CRT) $(OFILES) -o $(BINDIR)/$(PROGRAM) -create-app -subtype=nex

.PHONY: clean
clean:
	rm -f $(OBJDIR)*.o 
	rm -f $(BINDIR)*.bin
	rm -f $(BINDIR)*.nex 
	rm -f *.map 
	rm -f zcc_opt.def 
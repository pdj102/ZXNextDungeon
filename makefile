CC=zcc
AS=zcc
TARGET=+zxn
VERBOSITY=-vn
CRT=1

PRAGMA_FILE=zpragma.inc

C_OPT_FLAGS=-SO3 --max-allocs-per-node200000

CFLAGS=$(TARGET) $(VERBOSITY) -c $(C_OPT_FLAGS) -compiler sdcc -clib=sdcc_iy -pragma-include:$(PRAGMA_FILE)
LDFLAGS=$(TARGET) $(VERBOSITY) -clib=sdcc_iy -pragma-include:$(PRAGMA_FILE)
ASFLAGS=$(TARGET) $(VERBOSITY) -c

OBJDIR=./obj
SRCDIR=./src
BINDIR=./bin

CFILES=$(wildcard $(SRCDIR)/*.c)
OFILES=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CFILES))
#OFILES=$(CFILES:.c=.o)

PROGRAM=dungeon.nex

obj/main.o : src/main.c
	$(CC) $(CFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(PRAGMA_FILE)
	$(CC) $(CFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

all : $(PROGRAM)

$(PROGRAM) : $(OFILES)
	 $(CC) $(LDFLAGS) -startup=$(CRT) $(OFILES) -o $(BINDIR)/$(PROGRAM) -create-app -subtype=nex

.PHONY: clean
clean:
	rm -f *.o *.bin *.nex *.map zcc_opt.def 
OBJS = getopt.o
CSRCS = getopt.c
ASRCS =
COBJS = getopt.o
AOBJS =
HELLOOBJS = getopt.o
CFLAGS = -m32 -g3 -O0 -Wall -Werror -std=c11 -pedantic
AFLAGS = -f elf32 -g3 -F dwarf
LDFLAGS = -m32 -lm -no-pie
TARGETS = getopt
LISTINGS =
CC = gcc
AS = nasm

#default target
all: $(TARGETS)

.PHONY: clean

$(AOBJS): $(ASRCS)
	$(AS) $(AFLAGS) -o $(@) -l $(*).lst $(<)

# Rule to build object files
# -c is special in that it can use automatic variables with automatic rename from .c to .o
$(COBJS): $(CSRCS)
	$(CC) $(CFLAGS) -c $(@:.o=.c)



hello: $(HELLOOBJS)
	$(CC) $(LDFLAGS) $(HELLOOBJS) -o $(@)

logic: 
	$(CC) $(LDFLAGS) $(<) -o logic

clean:
	 rm -f $(OBJS) $(LISTINGS) $(TARGETS)

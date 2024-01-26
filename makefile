OBJS =  sizeof.o
CSRCS = sizeof.c
ASRCS = 
COBJS = sizeof.o
AOBJS = 
HELLOOBJS = sizeof.o
CFLAGS = -m32 -g3 -O0 -Wall -Werror -std=c11 -pedantic
AFLAGS = -f elf32 -g3 -F dwarf
LDFLAGS = -m32 -lm -no-pie
TARGETS = sizeof
LISTINGS = 
CC = gcc
AS = nasm

#default target
all: $(TARGETS)

.PHONY: clean

#there are some special make automatic variables
# @ is the target filename
# * is the basename of the target filename
# < is the first dependency
# there are others, but these are the ones we will be using
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

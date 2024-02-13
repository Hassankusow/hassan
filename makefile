#comments look like this
#variables typically at the top of the file
OBJS = getopt_long.o
CSRCS = getopt_long.c
ASRCS = 
COBJS = getopt_long.o
AOBJS = 
HELLOOBJS = getopt_long.o
CFLAGS = -m32 -g3 -O0 -Wall -Werror -std=c11 -pedantic
AFLAGS = -f elf32 -g3 -F dwarf
LDFLAGS = -m32 -lm -no-pie
TARGETS = getopt_long
LISTINGS = 
CC = gcc
AS = nasm

#default target
all: $(TARGETS)

HEADERS = getopt.h


.PHONY: clean


$(AOBJS): $(ASRCS)
	$(AS) $(AFLAGS) -o $(@) -l $(*).lst $(<)


$(COBJS): $(CSRCS) $(HEADERS)
	$(CC) $(CFLAGS) -c $(@:.o=.c)

hello: $(HELLOOBJS)
	$(CC) $(LDFLAGS) $(HELLOOBJS) -o $(@)

logic: 
	$(CC) $(LDFLAGS) $(<) -o logic

clean:
	rm -f $(OBJS) $(LISTINGS) $(TARGETS)

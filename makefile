OBJS = lab1.o hex_func.o
CSRCS = lab1.c hex_func.c
COBJS = lab1.o 
AOBJS = 
HELLOOBJS = hex_func.o
CFLAGS = -m32 -g3 -O0 -Wall -Werror -std=c11 -pedantic
AFLAGS = -f elf32 -g3 -F dwarf
LDFLAGS = -m32 -lm -no-pie
TARGETS = lab1 
LISTINGS = 
CC = gcc
AS = nasm

HEADERS = getopt.h 

#default target
all: $(TARGETS)

.PHONY: clean

$(AOBJS): $(ASRCS)
	$(AS) $(AFLAGS) -o $(@) -l $(*).lst $(<)

$(COBJS): $(CSRCS) $(HEADERS)  
	$(CC) $(CFLAGS) -c $(@:.o=.c)

lab1: $(COBJS)
	$(CC) $(LDFLAGS) $(COBJS) -o $(@)

logic: logic_ops2.o
	$(CC) $(LDFLAGS) $(<) -o logic

clean:
	rm -f $(OBJS) $(LISTINGS) $(TARGETS)


OBJS = ex-1.o ex-2.o ex-3.o ex-4.o
CSRCS = ex-1.c ex-2.c ex-3.c ex-4.c
ASRCS = 
COBJS = ex-1.o ex-2.o ex-3.o ex-4.o
AOBJS = 
HELLOOBJS = ex-1.o ex-2.o ex-3.o ex-4.o
CFLAGS = -m32 -g3 -O0 -Wall -Werror -std=c11 -pedantic
AFLAGS = -f elf32 -g3 -F dwarf
LDFLAGS = -m32 -lm -no-pie
TARGETS = ex-1 ex-2 ex-3 ex-4
LISTINGS = 
CC = gcc
AS = nasm

all: $(TARGETS)

.PHONY: clean

$(AOBJS): $(ASRCS)
	$(AS) $(AFLAGS) -o $(@) -1 $(*).lst $(<)

$(COBJS): $(CSRCS)
	$(CC) $(CFLAGS) -c $(@:.o=.c)

output: $(HELLOOBJS)
	$(CC) $(LDFLAGS) $(HELLOOBJS) -o $(@)



ex-4: ex-4.c
	$(CC) $(CFLAGS) $< -o $@ -lm

clean:
	rm -f $(OBJS) $(LISTINGS) $(TARGETS)


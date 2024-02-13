CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = main.o dlist.o  supplied.o

output: $(OBJTS)
	$(CC) $(CPPFLAGS) -o output $(OBJTS)

main.o: dlist.h  supplied.o

dlist.o: dlist.h  supplied.o

clean:
	rm output *.o

CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = main3.o web.o table.o

output: $(OBJTS)
	$(CC) $(CPPFLAGS) -o output $(OBJTS)

main3.o: web.h table.h

web.o: web.h

table.o: table.h web.h 

clean:
	rm output *.o

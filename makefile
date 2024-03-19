CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = main4.o web.o table.o

output: $(OBJTS)
	$(CC) $(CPPFLAGS) -o output $(OBJTS)

main4.o: web.h table.h

web.o: web.h

table.o: table.h web.h

clean:
	rm output *.o

CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = main.o song.o list.o

output: $(OBJTS)
	$(CC) $(CPPFLAGS) -o output $(OBJTS)

main.o: song.h list.h myutil.h

song.o: song.h myutil.h

list.o: list.h song.h myutil.h

clean:
	rm output *.o

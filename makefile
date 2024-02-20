CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = main.o line.o stack.o queue.o

output: $(OBJTS)
	$(CC) $(CPPFLAGS) -o output $(OBJTS)

main.o: stack.h line.h myutil.h queue.h

line.o: myutil.h

stack.o: line.h stack.h myutil.h

queue.o: line.h queue.h myutil.h

clean:
	rm output *.o

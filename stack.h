/*
  Author: Hassan abdi
  Class: CS260
  Project: Project 2
  File: stack.h
  Description: Header file for the stack array where it pushes peeks and display also pops our clinet list.
*/


#include "line.h"
#include <fstream>

class Stack
{
public:
	Stack();
	Stack(const Stack& aStack);
	~Stack();

	void push(const info& ainfo);
        bool pop(info& ainfo);
        bool peek(info& ainfo) const;
	void display(info& ainfo) const;

	const Stack& operator= (const Stack& aStack);
	friend ostream& operator<< (ostream& out, const Stack& aStack);

	void loadfromFile(const char * filename);
	void savetofile(const char * filename) const;

private:
        info **  astack;
        
	
	int capacity;
	int top;
	void destroy();
	void expand();

};

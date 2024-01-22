#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>
#include <iostream>

using namespace std;

class LinkedList
{
public:
        LinkedList();
        ~LinkedList();

        void add(char ch);
        bool find(char ch);
        bool del(char ch);
        void print();


private:

     struct node
{
        char data;
        node * next;
};
    node * head = nullptr;
};

#endif // _LINKED_LIST_

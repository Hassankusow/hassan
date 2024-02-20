/*
  Author: Hassan abdi
  Class: CS260
  Project: Project 2
  File: queue.h
  Description: Header file my circular linear link list.
  recuursive function are display displayR
*/


#pragma once
#include "line.h"
#include "myutil.h"
#include <iostream>

class Queue {
public:
    Queue();
    Queue(const Queue& aQueue);
    ~Queue();
    void destroy();

    void enqueue(const info& ainfo);
    bool dequeue(info& ainfo);
    bool peek(info& ainfo) const;
    void display() const;

    Queue& operator= (const Queue& aQueue);
    friend std::ostream& operator<< (std::ostream& out, const Queue& aQueue);

    void loadFromFile(const char *fileName);
    void savetofile(const char *fileName)const;

private:
    struct Node {
        info data;
        Node* next;
        Node* prev;
        Node(const info& ainfo) : data(ainfo), next(nullptr), prev(nullptr) {}
    };
    Node* front;
    Node* back;
    int size;

    void displayR(Node* current, int position) const;
};


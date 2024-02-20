

#include "stack.h"
// empty constructor
Stack::Stack() : top(0), capacity(10) {
    astack = new info*[capacity];
    for (int i = 0; i < capacity; ++i) {
        astack[i] = nullptr;
    }
}



// copy construcot 
Stack::Stack(const Stack& aStack) : top(aStack.top), capacity(aStack.capacity) {
     *this = aStack;
}



//destroctor
Stack::~Stack() {
    destroy();
}



// display function for my dtack elments
void Stack::display(info& ainfo) const{
     if (top == -1) {
     cout << "Stack is empty." << endl;
     return;
    }

    cout << "Stack elements:" << endl;
    for (int i = top - 1; i >= 0; --i) {
        const info* currentInfo = astack[i];
        cout << *currentInfo << endl;
    }
}



// push function where pushes my clinet list 
void Stack::push(const info& ainfo) {
    if (top == capacity) {
        expand();
    }
    astack[top] = new info(ainfo);
    top++;
}



// pops when i conatacted the client
bool Stack::pop(info& ainfo) {
    if (top == 0) {
        return false;
    }
    ainfo = *(astack[top -1]);
    delete astack[top-1];
    top--;
    return true;
}



// takes a peek at my client when i am contacted him
bool Stack::peek(info& ainfo) const {
    if (top == 0) {
        return false;
    }
    ainfo = *(astack[top - 1]);
    return true;
}



// stack overboad operator 
const Stack& Stack::operator= (const Stack& aStack) {
    if (this == &aStack) {
        return *this;
    }
    destroy();
    top = aStack.top;
    capacity = aStack.capacity;
    astack = new info*[capacity];
    for (int i = 0; i < top; ++i) {
        astack[i] = new info(*(aStack.astack[i]));
    }
    return *this;
}



// output 
std::ostream& operator<< (std::ostream& out, const Stack& aStack) {
    out << "Displaying the stack ..." << std::endl;
    for (int i = 0; i < aStack.top; ++i) {
        out << *(aStack.astack[i]) << std::endl;
    }
    return out;
}



// destory function for destoructor 
void Stack::destroy() {
    for (int i = 0; i < top; ++i) {
        delete astack[i];
    }
    delete[] astack;
}


// expanding my cpapacity function fir stack size 
void Stack::expand() {
    capacity *= 2;
    info** tempStack = new info*[capacity];
    for (int i = 0; i < top; i++) {
        tempStack[i] = astack[i];
    }
    delete[] astack;
    astack = tempStack;
}



// load function for external file 
void Stack::loadfromFile(const char* fileName) {
    ifstream in(fileName);
    if (!in) {
        cerr << "Fail to open " << fileName << " for reading!" << endl;
        exit(1);
    }

    const int MAX_CHAR = 101;
    char currGroup[MAX_CHAR];
    char currName[MAX_CHAR];
    char currAddress[MAX_CHAR];
    int currNumber;
    char currChair[MAX_CHAR];

    in.get(currGroup, MAX_CHAR, ';');
    while (!in.eof()) {
        in.get();
        in >> currNumber;
        in.ignore(MAX_CHAR, ';');
        in.get(currChair, MAX_CHAR, ';');
        in.ignore(MAX_CHAR, ';');
        in.get(currName, MAX_CHAR, ';');
        in.ignore(MAX_CHAR, ';');
        in.get(currAddress, MAX_CHAR, '\n');

        info currInfo(currGroup, currName, currNumber, currChair, currAddress);
        push(currInfo);
        in.get(currGroup, MAX_CHAR, ';');
    }
    in.close();
}



// save function for external file 
void Stack::savetofile(const char* fileName) const {
    ofstream out(fileName);
    if (!out) {
        cerr << "Fail to open " << fileName << " for writing!" << endl;
        exit(1);
    }

    for (int i = 0; i < top; ++i) {
        out << astack[i]->get_group() << ';' << astack[i]->getname() << ';' << astack[i]->getnumber() << ';' << astack[i]->get_chair() << ';' << astack[i]->get_adress() << endl;
    }
    out.close();
}

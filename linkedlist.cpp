#include "linkedlist.h"

//implementations for the member functions of LinkedList class

LinkedList::LinkedList() : head(nullptr) {}
void LinkedList::add(char ch) {
    if (!head) {
        head = new node;
        head->data = ch;
        head->next = nullptr;
    } else {
        node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new node;
        current->next->data = ch;
        current->next->next = nullptr;
    }
}


bool LinkedList::find(char ch){
        node * current = head;
        while ( current != nullptr){
            if (current -> data == ch){
                    return true;}
            current = current -> next;
    }
        return false;


}
bool LinkedList::del(char ch) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == ch) {
        node* temp = head;
        head = temp->next;
        delete temp;
        return true;
    }

    node* current = head;
    node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == ch) {
            prev->next = current->next;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

void LinkedList::print(){
        node * current = head;
        while ( current != nullptr){
                cout << current -> data << " " ;
                current = current -> next;
        }
        cout << endl;

}
LinkedList::~LinkedList(){
        while (head != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

}

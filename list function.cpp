#include "list.h"
using namespace std;


// my welcome function where just post my menu
void welcome(){
	cout << "Welcome to this linear link list problem program" << endl;
	cout << "a. to enter a new problem" << endl;
	cout << "b. to display all problems" << endl;
	cout << "c. to display a random problem" << endl;
	cout << "d. to quit" << endl;
}


// this is for the menu choice i return menu choice
char get_menu() {
	char choice;
	cout << "Enter a menu choice: ";
	cin >> choice;
	cin.ignore(100, '\n');
	return choice;
}


// my problem input i passed through my node lll as a refrence in order to uptade my list
void problem_input(node * &head) {
    PracticeProblem newProblem;
    newProblem.title = new char[100];
    newProblem.details = new char[100];
    newProblem.prototype = new char[100];
    newProblem.additionalItem = new char[100];

    cout << "Enter the title of the problem: ";
    cin.get(newProblem.title, 100);
    cin.ignore(100, '\n');
    cout << "Enter the description of the problem: ";
    cin.get(newProblem.details, 100);
    cin.ignore(100, '\n');
    cout << "Enter the prototype of the problem: ";
    cin.get(newProblem.prototype, 100);
    cin.ignore(100, '\n');
    cout << "Enter the additional info about the problem: ";
    cin.get(newProblem.additionalItem, 100);
    cin.ignore(100, '\n');
    
    // ill be creating a new node where 
    node* newNode = new node;
    newNode->list = newProblem;
    newNode->next = nullptr;// set the new node as a null due to it being the last as of now

    if (head == nullptr) {
        head = newNode;
    } else {
        node* current = head;//create a temp current pionter
        // traversing to the last
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    
}


// display where passed through my node as a value due to it not being updated
void display_all(node* head) {
    node* current = head;//temp pionter plus traversing while printing what the list has
    while (current != nullptr) {
        cout << "Title: " << current->list.title << endl;
        cout << "Details: " << current->list.details << endl;
        cout << "Prototype: " << current->list.prototype << endl;
        cout << "Additional Item: " << current->list.additionalItem << endl;
        cout << endl;
        current = current->next;
    }}
 

// ill be display ramdom node just like dissplay all passed by value
void display_random(node * head){
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    int count = 0;
    node* current = head;//traversing
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    int randomIndex = rand() % count;//finding a random number
    current = head;
    for (int i = 0; i < randomIndex; i++) {
        current = current->next;
    }

    cout << "Random Problem:" << endl;
    cout << "Title: " << current->list.title << endl;
    cout << "Details: " << current->list.details << endl;
    cout << "Prototype: " << current->list.prototype << endl;
    cout << "Additional Item: " << current->list.additionalItem << endl;
}


// this is for it to be destroyed passed by refrence 
void destroy(node* &head) {
    while (head != nullptr) {
        node* current = head;
        head = head->next;
        delete[] current->list.title;
        delete[] current->list.details;
        delete[] current->list.prototype;
        delete current;
    }
}


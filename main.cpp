#include "queue.h"
#include "stack.h"


#include <iostream>

int main() {
    Queue myQueue;
    Stack myStack;

    char filename[] = "reservoa.txt";
    char clients[] = "clients.txt";
    //myStack.loadfromFile(clients);
    //myQueue.loadFromFile(filename);
    bool ans;
    int choice;

    info groupinfo;

    do {
        cout << "Menu:\n"
             << "1. Add a group to the waiting list\n"
             << "2. Seat a group\n"
             << "3. Display waiting list\n"
             << "4. Add customer to promotional list\n"
             << "5. Contact customers for promotions\n"
             << "6. Display promotional list\n"
             << "0. Quit the program\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // gets info from info and then passes stores in a circular lll in enqueue function 
                groupinfo.inputgroup();
                myQueue.enqueue(groupinfo);
                break;
            }
            case 2: {
                // to remove the steated indviduls from the list 
                ans = myQueue.dequeue(groupinfo);
                if (ans == true)
                   cout << "The group: " << groupinfo.get_group() << " has been seated" << endl;

               break;
                    }
            case 3: {
                // Display waiting list
                myQueue.display();
                break;
            }
            case 4: {
	        // this is for the push client where if the client its not none for promotional materials 
                if (strcmp(groupinfo.getname(), "None") != 0) 
                    myStack.push(groupinfo);

                break;
            }
            case 5: {
	       // this does a peek where peeks at the client info and then pops becouse we took a peek and then we contacted him/her
               ans = myStack.peek(groupinfo);
	       if ( ans == true)
               cout << "THe person: " << groupinfo.getname() << " is in the prosces of being contacted" << endl;	       
               ans = myStack.pop(groupinfo);
	    
	       if ( ans == true)
	       cout << "THe person: " << groupinfo.getname() << " has been removed from the list" << endl;
	       else 
		       cout <<"empty" << endl;
                
                break;
            }
            case 6: {
	       // display my client lists 
                myStack.display(groupinfo);
                break;
            }
            case 0: {
                // Quit the program save in savetofile
                cout << "Exiting program.\n";
                myQueue.savetofile(filename);
		myStack.savetofile(clients);
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}

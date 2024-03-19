#include "myutil.h"
#include "table.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    char filename[] = "web.txt";
    // Create a Table:wq
    Table atable;

    atable.loadFromFile(filename);
    info newInfo;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add a website\n";
        cout << "2. Remove a website\n";
        cout << "3. Retrieve website information\n";
        cout << "4. Display all websites\n";
        cout << "5. hieght of the tree\n";
        cout << "6. remove a topic\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1: {
                newInfo.inputwebsite();
                atable.add(newInfo);
                cout << "Website added successfully!\n";
                break;
            }
            case 2: {
                char key[100];
                cout << "Enter the keyword of the website to remove: ";
                cin.getline(key, 100);
                info removedInfo;
                if (atable.remove(key, removedInfo)) {
                    cout << "Website removed successfully:\n" << removedInfo << endl;
                } else {
                    cout << "Website with keyword \"" << key << "\" not found.\n";
                }
                break;
            }
            case 3: {
                char key[100];
                cout << "Enter the keyword of the website to retrieve: ";
                cin.getline(key, 100);
                info retrievedInfo;
                if (atable.retrieve(key, retrievedInfo)) {
                    cout << "Website information for keyword \"" << key << " is found. \n" << endl;
                } else {
                    cout << "Website with keyword \"" << key << "\" not found.\n";
                }

                break;
            }
            case 4: {
                cout << "Displaying all websites:\n";
                cout << atable;
                break;
            }
            case 5: {
                int h =  atable.height();
                cout << "The current hieght of the tree is "  << h << endl;
                break;
                    }
            case 6: {
                char key[100];
                cout << "Enter the keyword of the website to remove: ";
                cin.getline(key, 100);
                info removeInfo;
                if (atable.remove_topic(key)) {
                    cout << "topic  removed successfully:\n" << removeInfo << endl;
                } else {
                    cout << "topic with keyword \"" << key << "\" not found.\n";
                }
                break;
                    }

            case 0: {
                cout << "Exiting...\n";
                atable.saveToFile(filename);
                break;
            }
            default: {
                cout << "Invalid choice!\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}


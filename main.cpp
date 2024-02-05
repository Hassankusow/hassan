#include <iostream>
#include "list.h"  // Include the header file for your List class

using namespace std;

int main(){

	
    List songList;
    int choice;
    char name[20];

    // loading from file
    songList.loadFromFile("song.txt");

    do{
	cout << "Menu:\n"
             << "1. Add a new song\n"
             << "2. Display all songs\n"
             << "3. Display all songs for an artist\n"
             << "4. Remove all songs with fewer M likes\n"
             << "0. Quit the program\n";

        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){


            case 1: {
                
                 Song newSong;
                 newSong.inputSong(); 
                 songList.addSong(newSong); 
                break;
            }
            case 2: {
        
                songList.displayAllSongs();  
                break;
            }
            case 3: {

	        cin.ignore();
		cout << "Enter a arist name: ";
		cin.get(name,20,'\n');
                songList.displaySongsForArtist(name); 
                break;
            }
            case 4: {
                int m;
		cout <<"Enter the likes: ";
		cin >> m;
		songList.removeSongsWithFewerLikes(m);
                break;
            }
            case 0: {
                // Quit the program
                cout << "Exiting program.\n";
		songList.saveToFile("song.txt");
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }

        
        }


    }while(choice != 0);

    return 0;
}

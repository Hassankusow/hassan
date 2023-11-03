#include "hero.h"
#include <iostream>
// this program is about struct and external files ill be getting a superhero
//his information saving into a external file named superhero.txt
int main() {
    HeroData superheroes[MAX_SUPERHEROES];
    int numSuperheroes = 0;
    char choice = ' ';
    int num = 0;

    displayMenu();
    do {
        choice = getMenuChoice();

        switch (choice) {
            case 'a':
                if (numSuperheroes < MAX_SUPERHEROES) {
                    add_Superhero(superheroes[numSuperheroes]);
                    numSuperheroes++;
                } else {
                    std::cout << "Maximum number of superheroes reached." << std::endl;
                }
                break;
            case 'b':
                display_Superheroes(superheroes, numSuperheroes);
                break;
            case 'c':
                num = load_File(superheroes);
                break;
            case 'e':
                match_hero(superheroes, numSuperheroes);
                break;
            case 'd':
                save_File(superheroes, numSuperheroes);
                std::cout << "Data saved to file." << std::endl;
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'd');

    return 0;
}


#include "myutil.h"
#include "table.h"



void printMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add a website\n";
    std::cout << "2. Display websites based on topic\n";
    std::cout << "3. Edit review and rating\n";
    std::cout << "4. Remove websites with a 1-star rating\n";
    std::cout << "5. retrieve websites related to a specific topic\n";
    std::cout << "6. Display all websites\n";
    std::cout << "7. Monitor performance of hashing function\n";
    std::cout << "0. Exit\n";
}


int main() {
    char filename[] = "web.txt";
    // Create a Table:wq
    Table atable;
    
    atable.loadFromFile(filename);

    info newInfo;

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
	cin.ignore();
	char topic_keyword[100];
	info matches[100];
	int num_found = 0;

        switch (choice) {
            case 1: {
                
                newInfo.inputwebsite();
                atable.add(newInfo);
                std::cout << "Website added successfully!\n";
                break;
            }
            case 2: {
                std::cout << "Enter the topic keyword: ";
                std::cin >> topic_keyword;
                bool found = atable.display_topic(topic_keyword, matches, num_found);
                if (found) {
                    std::cout << "Websites related to topic '" << topic_keyword << "':" << std::endl;
                    for (int i = 0; i < num_found; ++i) {
                        std::cout << matches[i] << std::endl;
                    }
                } else {
                    std::cout << "No websites found for topic '" << topic_keyword << "'" << std::endl;
                }
                break;
            }
            case 3: {
                char topic[100], name[100], new_review[200];
                int new_rating;
                std::cout << "Enter the topic of the website: ";
                cin.getline(topic,100);
                std::cout << "Enter the name of the website: ";
                cin.getline(name,100);
                std::cout << "Enter the new review: ";
                cin.getline(new_review,200);
                std::cout << "Enter the new rating: ";
                std::cin >> new_rating;
                atable.edit(topic, name, new_review, new_rating);
                std::cout << "Review and rating edited successfully!\n";
                break;
            }
	    case 4: {
		atable.remove();

		break;
		    }
	    case 5: {
	        cout << "Enter the topic keyword: ";
                cin >> topic_keyword;
                bool found= atable.retrieve(topic_keyword, matches, num_found);
                if (found) {
                    cout << "The number of websites found about " << topic_keyword << " is': "<< num_found / 2 << endl;
                } else {
                    cout << "No websites found for topic '" << topic_keyword << "'" << endl;
                }
	        break;
		    }
	    case 6: {
                atable.displayAll();
                break;
            }
            case 7: {
                cout << "Monitoring performance of hashing function:" << endl;
                atable.monitorPerformance();
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

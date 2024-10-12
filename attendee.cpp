// arrendee.cpp file 


#include "myutil.h"
#include "attendee.h"

using namespace std;

// Constructors
attendee::attendee() : name(nullptr), age(0) {}


attendee::attendee(const char * input_name) {
    name = new char[strlen(input_name) + 1];
    strcpy(name, input_name);
}

attendee::attendee(const char * input_name, int input_age) {
    name = new char[strlen(input_name) + 1];  
    strcpy(name, input_name);  
    age = input_age;  
}

// Destructor
attendee::~attendee() {
    delete[] name;
}

// Copy Constructor
attendee::attendee(const attendee & Aattendee) {
    name = new char[strlen(Aattendee.name) + 1];
    strcpy(name, Aattendee.name);
    age = Aattendee.age;
}

// input

void attendee::input_a() {
    char temp_name[100];
    char is_animal_input;
    int cur_age;
    // Prompt for name
    cout << "Enter the name of the attendee: ";
    cin.getline(temp_name, 100);


    
    name = new char[strlen(temp_name) + 1];
    strcpy(name, temp_name);

    
    cout << "Enter the age of the attendee: ";
    cin >> age;
    cur_age = age;
    
    cin.ignore();
    
    // i made my life simpler i couldve added type in my constructor list
    //  but dont need to keep track

    cout << "Is the attendee an animal? (y/n): ";
    cin >> is_animal_input;

    bool is_animal = (tolower(is_animal_input) == 'y');

    if (is_animal) {
        return new animal(name_input);
    }

   

    // Based on the age, itll be child or adult 
    if (cur_age < 14) {
        return new child(name_input, age_input);
    }
    else {
        return new adult(name_input, age_input);
    }
}

//  display attendee info
ostream & operator<<(ostream & out, const attendee & Aattendee) {
    out << "Attendee Name: " << Aattendee.name << endl;
    out << "Attendee Age: " << Aattendee.age << endl;
    return out;
}

// Assignment operator
const attendee& attendee::operator=(const attendee & Aattendee) {
    if (this != &Aattendee) { // Avoid self-assignment
        delete[] name; // Clean up old memory
        name = new char[strlen(Aattendee.name) + 1];
        strcpy(name, Aattendee.name);
        age = Aattendee.age;
    }
    return *this;
}


//constructor for child
child::child() : attendee(), atype(attendee_type::KID) {}

// ill be working on the rest before the second submission 

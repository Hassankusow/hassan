#include "line.h"
//constructor
info::info() : group(nullptr), name(nullptr), number(0), adress(nullptr), chair(nullptr)
{
}


//constructor passed twutg group
info::info(const char* group) : number(0) {
    init(group, nullptr, 0, nullptr, nullptr);
}



info::info(const char * group, const char * name, int number, const char * chair, const char * adress)
{
	init(group,name,number,chair,adress);
}


//iinital fubction the building block my info data
void info::init(const char * group, const char * name, int number, const char * chair, const char * adress) {
    this->group = new char[strlen(group) + 1];
    strcpy(this->group, group);

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->chair = new char[strlen(chair) + 1];
    strcpy(this->chair, chair);

    this->adress = new char[strlen(adress) + 1];
    strcpy(this->adress, adress);

    this->number = number;
}



// copy constructor
info::info(const info& ainfo) : group(nullptr), name(nullptr), number(0), chair(nullptr), adress(nullptr)
{
	*this = ainfo;
}
//destroctur
info::~info()
{
	if(this->group)
		delete[] this->group;
	if(this->name)
		delete[] this->name;
	if(this->adress)
		delete [] this->adress;
	if(this->chair)
		delete [] this->chair;
}



//my input implemetation
void info::inputgroup()
{
    char Group[50], Name[50], Address[50], Chair[50];
    int number;

    int ask1;
    int ask2;
    cin.ignore();
    cout << "Enter a name for your reservation: ";
    cin.getline(Group, 50);

    cout << "Enter the number of people for the reservation: ";
    cin >> number;

    cout << "Would you like to request special seating? (Enter 1 for yes, any other number to skip): ";
    cin >> ask1;
    cin.ignore();

    if (ask1 == 1) {
        cout << "What type of special seating do you require (e.g., high chair, wheelchair): ";
        cin.getline(Chair, 50);
    }
    else {
        strcpy(Chair, "No special seating");
    }

    cout << "Would you like to receive coupons and promotional materials? (Enter 1 for yes, any other number to skip): ";
    cin >> ask2;
    cin.ignore();

    if (ask2 == 1) {
        cout << "Enter your full name: ";
        cin.getline(Name, 50);
        cout << "Enter your email address: ";
        cin.getline(Address, 50);
    }
    else {
        strcpy(Name, "None");
        strcpy(Address, "None");
    }

    init(Group, Name, number, Chair, Address);
}



//all of these are my get where the return the specific data to the spefici caller
const char* info::get_group() const
{
    return group;
}

const char* info::getname() const
{
    return name;
}

int info::getnumber() const
{
    return number;
}

const char* info::get_chair() const
{
    return chair;
}

const char* info::get_adress() const
{
    return adress;
}



// it ssets ip my data for load file
void info::set_group(const char* group)
{
    if (this->group)
    {
        delete[] this->group;
    }
    this->group = new char[strlen(group) + 1];
    strcpy(this->group, group);
}




void info::set_name(const char* name)
{
    if (this->name)
    {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}




void info::set_chair(const char* chair)
{
    if (this->chair)
    {
        delete[] this->chair;
    }
    this->chair = new char[strlen(chair) + 1];
    strcpy(this->chair, chair);
}




void info::set_adress(const char* adress)
{
    if (this->adress)
    {
        delete[] this->adress;
    }
    this->adress = new char[strlen(adress) + 1];
    strcpy(this->adress, adress);
}



void info::set_no(int number)
{
    this->number = number;
}



//operator for my set functions
const info& info::operator=(const info& ainfo)
{
    if (this == &ainfo)
    {
        return *this;
    }

    set_group(ainfo.group);
    set_name(ainfo.name);
    set_no(ainfo.number);
    set_chair(ainfo.chair);
    set_adress(ainfo.adress);

    return *this;



}


// operator for my output
ostream& operator<< (ostream& out, const info& ainfo)
{
   out << ainfo.group << '\t'<< ainfo.number << '\t' << ainfo.chair << '\t' << ainfo.name << '\t' << ainfo.adress << endl;
   return out; 

}


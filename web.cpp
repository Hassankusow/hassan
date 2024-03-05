#include "web.h"
#include "myutil.h"
//constructor
info::info() : topic(nullptr), name(nullptr), rating(0), review(nullptr)
{
}


//constructor passed twutg group
info::info(const char* topic) : rating(0) {

	init(topic,nullptr,0,nullptr);
}


//intialzier constructor
info::info(const char * topic, const char * name, int rating, const char * review){
	
	init(topic,name,rating,review);
}


//iinital fubction the building block my info data
void info::init(const char * topic, const char * name, int rating, const char * review) {
    this->topic = new char[strlen(topic) + 1];
    strcpy(this->topic, topic);

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->review = new char[strlen(review) + 1];
    strcpy(this->review, review);

    this->rating = rating;
}



// copy constructor
info::info(const info& ainfo) : topic(nullptr), name(nullptr), rating(0), review(nullptr)
{
        *this = ainfo;
}


//destroctur
info::~info()
{
        if(this->topic)
                delete[] this->topic;
        if(this->name)
                delete[] this->name;
        if(this->review)
                delete [] this->review;
}


//input data from user
void info::inputwebsite() {
    char name[100];
    char topic[100];
    char review[100];
    int rating;

    std::cout << "Enter the name of the website: ";
    std::cin.getline(name, 100);

    std::cout << "Enter the topic of the website: ";
    std::cin.getline(topic, 100);

    std::cout << "Enter the review of the website: ";
    std::cin.getline(review, 100);

    std::cout << "Enter the rating (1-5): ";
    std::cin >> rating;
    std::cin.ignore();

    init(topic,name,rating,review);

}


//all of these are my get where the return the specific data to the spefici caller
const char* info::get_topic() const
{
    return topic;
}

const char* info::get_name() const
{
    return name;
}

int info::get_rating() const
{
    return rating;
}

const char* info::get_review() const
{
    return review;
}


// it ssets ip my data for load file
void info::set_topic(const char* topic)
{
    if (this->topic)
    {
        delete[] this->topic;
    }
    this->topic = new char[strlen(topic) + 1];
    strcpy(this->topic, topic);
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

void info::set_review(const char* review)
{
    if (this->review)
    {
        delete[] this->review;
    }
    this->review = new char[strlen(review) + 1];
    strcpy(this->review, review);
}

void info::set_rating(int rating)
{
    this->rating = rating;
}


//operator for my set functions
const info& info::operator=(const info& ainfo)
{
    if (this == &ainfo)
    {
        return *this;
    }

    set_topic(ainfo.topic);
    set_name(ainfo.name);
    set_rating(ainfo.rating);
    set_review(ainfo.review);
    

    return *this;



}


// operator for my output
ostream& operator<< (ostream& out, const info& ainfo)
{
   out << ainfo.topic << '\t'<< ainfo.name << '\t' << ainfo.review << '\t' << ainfo.rating << endl;
   return out;

}



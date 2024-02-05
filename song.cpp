#include "song.h"


Song::Song() : name(nullptr), title(nullptr),  song_time(0), likes(0) 
{
}



Song::Song(const char * name, const char * title, float song_time, int likes)
{
   init(name, title, song_time, likes);

}

void Song::init(const char * name, const char * title, float song_time, int likes)
{
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
	this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
        this->song_time = song_time;
	this->likes = likes;
}
Song::Song(const Song& aSong): name(nullptr), title(nullptr),  song_time(0), likes(0)
{
        *this = aSong;
}

Song::~Song()
{
     if(this->name)
        {
                delete [] this->name;
        }
        this->name = nullptr;

     if(this->title)
	{
		delete [] this->title;
	}
}

void Song::inputSong()
{
    char inputName[50], inputTitle[50];
    float inputSongTime;
    int inputLikes;
    cin.ignore();
    cout << "Enter name: ";
    cin.getline(inputName, 50);

    cout << "Enter title: ";
    cin.getline(inputTitle, 50);

    cout << "Enter song time: ";
    cin >> inputSongTime;
    cin.ignore();

    cout << "Enter likes: ";
    cin >> inputLikes;
    cin.ignore(); 

    init(inputName, inputTitle, inputSongTime, inputLikes);
}

float Song::get_time() const
{
        return song_time;
}
int Song::get_likes() const
{
        return likes;
}
const char * Song::getName() const
{
        return name;
}
const char * Song::get_title() const
{
	return title;
}
void Song::set_time(float song_time)
{
        this->song_time = song_time;
}

void Song::setName(const char * name)
{
        if(this->name)
        {
        	delete [] this->name;
        }
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
}
void Song::set_title(const char * title)
{
        if(this->title)
        {
                delete [] this->title;
        }
        this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
}
void Song::set_likes(int likes)
{
    this->likes = likes;

}
const Song& Song::operator= (const Song& aSong)
{
        if(this == &aSong)
        {
                return *this;
        }

        setName(aSong.name);
	set_title(aSong.title);
	set_time(aSong.song_time);
	set_likes(aSong.likes);
        
        return *this;
}

ostream& operator<< (ostream& out, const Song& aSong)
{
        out << aSong.name << '\t' << aSong.title << '\t' <<
	       aSong.song_time	<< '\t' << aSong.likes << endl;
        return out;
}


 

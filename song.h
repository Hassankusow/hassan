#pragma once

#include "myutil.h"


class Song
{
public:
  
    Song();
    Song(const char * name);
    Song(const char * name, const char * title, float song_time, int likes);
    ~Song();
    Song(const Song& aSong);
    void inputSong();
    float get_time() const;
    const char * getName() const;
    int get_likes() const;
    const char * get_title() const;
    void setName(const char * name);
    void set_title(const  char * title);
    void set_time(float song_time);
    void set_likes(int likes);
    const Song& operator= (const Song& aSong);
    friend ostream& operator<< (ostream& out, const Song& aSong);   
  
private:
  
 

    char * name;
    char * title;
    float song_time;
    int likes;

 void init(const char * name, const char * title, float song_time, int likes);
};


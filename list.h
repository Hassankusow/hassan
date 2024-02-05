#pragma once

#include "myutil.h"
#include "song.h"


class List
{
public:
	
		  
        List();
        List(const List& aList);
        ~List();


	const List& operator= (const List& aList);
        friend ostream& operator<< (ostream& out, const List& aList);

        void loadFromFile(const char * fileName);
        void saveToFile(const char * fileName) const;
	void inputList();
        void addSong(const Song &aSong);
        void editLikes(const char *name, int newLikes);
        void displayAllSongs() const;
        void displaySongsForArtist(const char *artistName) const;
        void removeSongsWithFewerLikes(int minLikes);
        void destroy();



private:
	
         struct Node
        {
                Node(const Song & aSong )
                {
                        data = new Song (aSong);
			prev = next = nullptr;
                }
                ~Node()
                {
                        delete data;
                        data = nullptr;
                        prev = next = nullptr;
                }
                Song * data;
                Node *prev, *next;
        };
        Node *head, *tail;
        int size;
	void destory();


};

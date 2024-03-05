/*
  Author: Hassan abdi
  Class: CS260
  Project: Project 3
  File: table.h
  Description: Header file for the info for the Hash table.
*/

#include "web.h"
#include <fstream>
#include <cstring>

class Table
{
public:
        Table();
        Table(const Table& aTable);
        ~Table();

        void add(const info &ainfo);
        void displayAll() const;
        void edit(const char* topic, const char* name, const char* new_review, int new_rating);
        bool display_topic(const char* topic_keyword, info* all_matches, int& num_found) const;
	bool retrieve(const char* topic_keyword, info* all_matches, int& num_found) const;
	void monitorPerformance() const;
	void remove();
        
        
        const Table& operator= (const Table& aTable);
        friend ostream& operator<< (ostream& out, const Table& aTable);

        void loadFromFile(const char * fileName);
        void saveToFile(const char * fileName) const;
private:
        struct Node
        {
                Node(const info &ainfo)
                {
                        data = new info(ainfo);
                        next = nullptr;
                };

                info *       data;
                Node *          next;
        };
        Node**                          aTable;
        const static int        INIT_CAP = 10;
        int                                     currCapacity;
        int                             size;

        int calculateIndex(const char * key) const;
        void destroy();
        void destroyChain(Node *& currHead);
	void displayChain(std::ostream& out, Node* currHead) const;
	void copyChain(Node * srcHead, Node *& destHead);
        void writeOutChain(ostream& out, Node * currHead) const;
	
	
};

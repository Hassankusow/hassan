#include "table.h"

// constructor 
Table::Table() : size(0)
{
        currCapacity = INIT_CAP;
        aTable = new Node*[currCapacity];
        for(int i=0; i<currCapacity; i++)
        {
                aTable[i] = nullptr;
        }
}

//copy constructor
Table::Table(const Table& aTable) : aTable(nullptr), size(0)
{
        *this = aTable;
}


//destructor
Table::~Table()
{
        destroy();
}

// destroying table
void Table::destroy()
{
        for(int i=0; i<currCapacity; i++)
        {
                destroyChain(aTable[i]);
        }
        if(aTable)
                delete [] aTable;
}

// destroy chain
void Table::destroyChain(Node *& currHead)
{
        if(currHead)
        {
                destroyChain(currHead->next);
                delete currHead->data;
                delete currHead;
                currHead = nullptr;
        }
}

// adding the info to my chain
void Table::add(const info& ainfo)
{
        int     index = calculateIndex(ainfo.get_topic());
        Node *  newNode = new Node(ainfo);
        newNode->next = aTable[index];
        aTable[index] = newNode;
        size++;
}


//calculating where my index of chain will be 
int Table::calculateIndex(const char * key) const
{
        int hashingResult;
        hashingResult = 0;
        for(; *key != '\0'; key++)
        {
                hashingResult += *key;
        }
         return hashingResult % currCapacity;
}



// Display websites based on topic
bool Table::display_topic(const char* topic_keyword, info* all_matches, int& num_found) const {
    int index = calculateIndex(topic_keyword);
    Node* curr = aTable[index];
    num_found = 0;
    bool found = false;
    while (curr != nullptr) {
        if (strcmp(curr->data->get_topic(), topic_keyword) == 0) {
            all_matches[num_found++] = *(curr->data);
            found = true;
        }
        curr = curr->next;
    }
    return found;
}



// Copy chain
void Table::copyChain(Node* srcHead, Node*& destHead) {
    if (srcHead == nullptr) {
        destHead = nullptr;
        return;
    }
    destHead = new Node(*(srcHead->data));
    Node* srcCurr = srcHead->next;
    Node* destCurr = destHead;
    while (srcCurr != nullptr) {
        destCurr->next = new Node(*(srcCurr->data));
        srcCurr = srcCurr->next;
        destCurr = destCurr->next;
    }
}


// Display chain R for display all chains recuisivley 
void Table::displayChain(std::ostream& out, Node* currHead) const {
    Node* curr = currHead;
    while (curr != nullptr) {
        out << *(curr->data) << std::endl;
        curr = curr->next;
    }
}


// display all chains
void Table::displayAll() const {
    for (int i = 0; i < currCapacity; ++i) {
        displayChain(std::cout, aTable[i]);
    }
}


// Write out chain to file
void Table::writeOutChain(ostream& out, Node * currHead) const
{
        if(currHead)
        {
                out << currHead->data->get_topic() << ';' << currHead->data->get_name() << ';'
                    << currHead->data->get_rating() << ';' << currHead->data->get_review() << endl;
                writeOutChain(out, currHead->next);
        }
}


//input operator
const Table& Table::operator= (const Table& currtable)
{
        if(this == &currtable)
                return *this;
        if(this->aTable)
        {
                destroy();
        }
        size = currtable.size;
        currCapacity = currtable.currCapacity;
        aTable = new Node*[currCapacity];
        for(int i=0; i<currCapacity; i++)
        {
                aTable[i] = nullptr;
                copyChain(currtable.aTable[i], this->aTable[i]);
        }
        return *this;
}

//output operatoer
ostream& operator<< (ostream& out, const Table& currTable)
{
        out << endl << "Displaying the table ..." << endl;
        for(int i=0; i<currTable.currCapacity; i++)
        {
                out << "Chain #" << i << " ... " << endl;
                currTable.displayChain(out, currTable.aTable[i]);
                out << endl;
        }
        return out;
}



// perfomance where it posts my hashtable compeplete and where are my chanis and thier lenths (the data)
void Table::monitorPerformance() const {
    for (int i = 0; i < currCapacity; ++i) {
        int count = 0;
        Node* curr = aTable[i];
        while (curr != nullptr) {
            ++count;
            curr = curr->next;
        }
        std::cout << "Chain " << i << " Length: " << count << std::endl;
    }
}


// Edit review and rating
void Table::edit(const char* topic, const char* name, const char* new_review, int new_rating) {
    int index = calculateIndex(topic);
    Node* curr = aTable[index];
    while (curr != nullptr) {
        if (strcmp(curr->data->get_topic(), topic) == 0 && strcmp(curr->data->get_name(), name) == 0) {
            curr->data->set_review(new_review);
            curr->data->set_rating(new_rating);
            break;
        }
        curr = curr->next;
    }
}



// retreval function where it gives the user the amount of wbsites for a specific topic
bool Table::retrieve(const char* topic_keyword, info* all_matches, int& num_found) const {
    int index = calculateIndex(topic_keyword);
    Node* curr = aTable[index];
    num_found = 0;
    bool found = false;
    while (curr != nullptr) {
        if (strcmp(curr->data->get_topic(), topic_keyword) == 0) {
            all_matches[num_found++] = *(curr->data);
            found = true;
            num_found+=1;
        }
        curr = curr->next;
    }
    return found;
}


// my 1 star removeal

void Table::remove() {
    bool found = false;
    for (int i = 0; i < currCapacity; ++i) {
        Node* curr = aTable[i];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->data->get_rating() == 1) {
                if (prev == nullptr) {
                    aTable[i] = curr->next;
                    delete curr->data;
                    delete curr;
                    curr = aTable[i];
		    found = true;
                } else {
                    prev->next = curr->next;
                    delete curr->data;
                    delete curr;
                    curr = prev->next;
                }
                size--;
            } else {
                prev = curr;
                curr = curr->next;
}
             if (found){
		     cout << "Website deleted!!" << endl;
		     }
             else {
		     cout << "Website with 1 start not found!!" << endl;
	     }
}}}


// load from file 
void Table::loadFromFile(const char * fileName)
{
        ifstream        in;
        info            currInfo;
        const int       MAX_CHAR = 101;
        char            currTopic[MAX_CHAR];
	char            currName[MAX_CHAR];
	char            currReview[MAX_CHAR];
        int             currRating;

        in.open(fileName);
        if(!in)
        {
                cerr << "Fail to open " << fileName << " for reading!" << endl;
                exit(1);
        }
        cin.ignore();
        in.get(currTopic, MAX_CHAR, ';');
        while(!in.eof())
        {
         in.getline(currName, MAX_CHAR, ';');
         in.getline(currReview, MAX_CHAR, ';');
         in >> currRating;
         in.ignore(MAX_CHAR, '\n');

         // Create an info object and populate it
         info currInfo;
         currInfo.set_name(currName);
         currInfo.set_topic(currTopic);
         currInfo.set_review(currReview);
         currInfo.set_rating(currRating);
        
        // Add the info object to the table
         add(currInfo);
    }

    in.close();
}


// save to file
void Table::saveToFile(const char * fileName) const
{
        ofstream        out;

        out.open(fileName);
        if(!out)
        {
                cerr << "Fail to open " << fileName << " for writing!" << endl;
                exit(1);
        }

        for(int i=0; i<currCapacity; i++)
        {
                writeOutChain(out, aTable[i]);
        }
        out.close();
}

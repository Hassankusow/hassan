#include "list.h"

List::List() : head(nullptr), tail(nullptr), size(0){}

List::List(const List& aList) : head(nullptr), tail(nullptr), size(0)
{
        *this = aList;
}

List::~List()
{
        destroy();
}

void List::destroy()
{
        Node * current = head;
        while(current)
        {
                head = current->next;
                delete current;
                current = head;
        }
        size = 0;
}

void List::inputList()
{
    int numSongs;

    cout << "Enter the number of songs: ";
    cin >> numSongs;
    cin.ignore();

    for (int i = 0; i < numSongs; ++i)
    {
        Song newSong;
        newSong.inputSong();
        addSong(newSong);
    }
}

void List::addSong(const Song &aSong)
{
    Node *newNode = new Node(aSong);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void List::editLikes(const char *name, int newLikes)
{
    Node *current = head;
    while (current)
    {
        if (strcmp(current->data->getName(), name) == 0)
        {
            current->data->set_likes(newLikes);
            return;
        }
        current = current->next;
    }

    cout << "Song with name '" << name << "' not found." << endl;
}

void List::displayAllSongs() const
{
    Node *current = head;
    while (current)
    {
        cout << *current->data << endl;
        current = current->next;
    }
}

void List::displaySongsForArtist(const char *artistName) const
{
    Node *current = head;
    while (current)
    {
        if (strcmp(current->data->getName(), artistName) == 0)
        {
            cout << *current->data << endl;
        }
        current = current->next;
    }
}

void List::removeSongsWithFewerLikes(int minLikes)
{
    Node *current = head;
    while (current)
    {
        if (current->data->get_likes() < minLikes)
        {
            Node *temp = current;
            if (current == head)
            {
                head = current->next;
                if (head)
                {
                    head->prev = nullptr;
                }
            }
            else
            {
                current->prev->next = current->next;
                if (current->next)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
            }
            delete temp;
            size--;
        }
        current = current->next;
    }
}

const List &List::operator=(const List &aList)
{
    if (this == &aList)
    {
        return *this;
    }

    destroy();

    Node *current = aList.head;
    while (current)
    {
        addSong(*current->data);
        current = current->next;
    }

    return *this;
}

ostream &operator<<(ostream &out, const List &aList)
{
    List::Node *current = aList.head;
    while (current)
    {
        out << *current->data << endl;
        current = current->next;
    }
    return out;
}

void List::loadFromFile(const char *fileName)
{
    ifstream in;
    Song aSong;
    const int MAX_CHAR = 101;
    char currName[MAX_CHAR];
    char currTitle[MAX_CHAR]; 
    float currSongTime;       
    int currLikes;             

    in.open(fileName);
    if (!in)
    {
        cerr << "Fail to open " << fileName << " for reading!" << endl;
        exit(1);
    }

    in.get(currName, MAX_CHAR, ',');
    while (!in.eof())
    {
        in.get();
        in.get(currTitle, MAX_CHAR, ',');
        in.get(); 
        in >> currSongTime;
        in.ignore(MAX_CHAR, ','); 
        in >> currLikes;
        in.ignore(MAX_CHAR, '\n'); 

        aSong.setName(currName);
        aSong.set_title(currTitle);
        aSong.set_time(currSongTime);
        aSong.set_likes(currLikes);

        addSong(aSong);

        in.get(currName, MAX_CHAR, ',');
    }
    in.close();
}

void List::saveToFile(const char *fileName) const
{
    ofstream out;

    out.open(fileName);
    if (!out)
    {
        cerr << "Fail to open " << fileName << " for writing!" << endl;
        exit(1);
    }

    for (Node *current = head; current; current = current->next)
    {
        out << current->data->getName() << ',' << current->data->get_title() << ',' 
            << current->data->get_time() << ',' << current->data->get_likes() << endl;
    }
    out.close();
}


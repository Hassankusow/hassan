#include "queue.h"

// Constructor to initialize an empty Queue
Queue::Queue() : front(nullptr), back(nullptr), size(0) {}



// copy construcotr 
Queue::Queue(const Queue& aQueue) : front(nullptr), back(nullptr), size(0) {
    *this = aQueue;
}



//destorcutor
Queue::~Queue() {
    destroy();
}



//destory function for destrocutor
void Queue::destroy() {
    Node* current = front;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    front = back = nullptr;
    size = 0;
}



// my eneque function where it adds the size of the list
void Queue::enqueue(const info& ainfo) {
    Node* newNode = new Node(ainfo);
    if (!front) {
        front = back = newNode;
    } else {
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
    }
    back->next = front;
    size++;
}


// the opissde of deqeueue where it subtracts the suze of the list
bool Queue::dequeue(info& ainfo) {
    if (size == 0) {
        return false;
    }

    ainfo = front->data;
    Node* temp = front;
    if (size == 1) {
        front = back = nullptr;
    } else {
        front = front->next;
        back->next = front;
        front->prev = nullptr;
    }
    delete temp;
    size--;
    return true;
}


// this function takes a peek at the list 
bool Queue::peek(info& ainfo) const {
    if (size == 0) {
        return false;
    }
    ainfo = front->data;
    return true;
}



// my recurive function where i display my content 
void Queue::displayR(Node* current, int position) const {

    cout << "Group" << position << ":" << endl;
    cout << "Group Name: " << current->data.get_group() << endl;
    cout << "Number of People: " << current->data.getnumber() << endl;
    cout << "Chair Type: " << current->data.get_chair() << endl;
    cout << "Address: " << current->data.get_adress() << endl;
    cout << endl;

    if (current == back)
        return;

    displayR(current->next, position + 1);
}

// its for my recruvibity function display
void Queue::display() const {
    if (size == 0) {
        cout << "Queue is empty." << endl;
        return;
    }
     displayR(front, 1);
}



//Overloaded assignment operator
Queue& Queue::operator= (const Queue& aQueue) {
    if (this == &aQueue) {
        return *this;
    }
    destroy();

    Node* current = aQueue.front;
    while (current) {
        enqueue(current->data);
        current = current->next;
    }

    return *this;
}



// overloaded << operator to output the contents
std::ostream& operator<< (ostream& out, const Queue& aQueue){
    const Queue::Node *current = aQueue.front;
    while (current)
    {
        out << current->data << endl;
        current = current->next;
    }
    return out;

}



// loading from external file function 
void Queue::loadFromFile(const char* fileName) {
    ifstream in;
    info currinfo;
    const int max_char = 101;
    char currgroup[max_char];
    char currname[max_char];
    char curraddress[max_char];
    char currchair[max_char];
    int currnumber;

    in.open(fileName);
    if (!in) {
        cerr << "Fail to open " << fileName << " for reading!" << endl;
	return;
        
    }
    
    in.get(currgroup, max_char, ',');
    while (!in.eof()) {
        in.get();
        in >> currnumber;
        in.ignore(max_char, ',');
        in.get(currchair, max_char, ',');
        in.get(currname, max_char, ',');
        in.get(curraddress, max_char, '\n');

        currinfo.set_group(currgroup);
        currinfo.set_no(currnumber);
        currinfo.set_chair(currchair);
        currinfo.set_name(currname);
        currinfo.set_adress(curraddress);

        enqueue(currinfo);

        in.get(currgroup, max_char, ',');
    }
    in.close();
}


// save to external file function 
void Queue::savetofile(const char *fileName)const {
    ofstream out;
    out.open(fileName);
    if (!out) {
        cerr << "Fail to open " << fileName << " for writing!" << endl;
        exit(1);
    }

    Node* current = front;
    while (current) {
        out << current->data.get_group() << ',' << current->data.getnumber() << ','
            << current->data.get_chair() << ',' << current->data.getname() << ','
            << current->data.get_adress() << endl;
        current = current->next;

	if (current == front) {
            break;
        }
    }

    out.close();
}

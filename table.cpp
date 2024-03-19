#include "table.h"
Table::Table() : root(nullptr), size(0)
{
}

Table::Table(const Table& aTable) : root(nullptr), size(0)
{
        *this = aTable;
}

Table::~Table()
{
        destroy(root);
}

void Table::destroy(Node *& currRoot)
{
        if(currRoot)
        {
                destroy(currRoot->left);
                destroy(currRoot->right);
                delete currRoot->data;
                delete currRoot;
                currRoot = nullptr;
        }
}


void Table::add(const info& ainfo)
{
        add(this->root, ainfo);
        size++;
}

void Table::add(Node *& currRoot, const info& ainfo)
{
    if (!currRoot)
    {
        currRoot = new Node(ainfo);
    }
    else if (strcmp(ainfo.get_topic(), currRoot->data->get_topic()) < 0)
    {
        add(currRoot->left, ainfo);
    }
    else
    {
        add(currRoot->right, ainfo);
    }
}

bool Table::remove(const char* key, info& ainfo) {
    return remove(root, key, ainfo);
}

bool Table::remove(Node*& currRoot, const char* key, info& ainfo) {
    if (!currRoot) {
        return false;
    }
    int temp = strcmp(key, currRoot->data->get_name());
    if (temp == 0) {
        ainfo = *(currRoot->data);
        deleteNode(currRoot);
        size--;
        return true;
    } else if (temp < 0) {
        return remove(currRoot->left, key, ainfo);
    } else {
        return remove(currRoot->right, key, ainfo);
    }
}


bool Table::remove_topic(const char* topic) {
    return remove_to(root, topic); 
}


bool Table::remove_to(Node*& currRoot, const char* topic) {
    if (!currRoot) {
        return false;
    }
    bool removed = false;
    if (strcmp(topic, currRoot->data->get_topic()) == 0) {
        deleteNode(currRoot); 
        size--; 
        removed = true; 
    }
    
    removed = remove_to(currRoot->left, topic) || remove_to(currRoot->right, topic) || removed;
    return removed; 
}


void Table::deleteTree(Node*& currRoot) {
    if (currRoot) {
        deleteTree(currRoot->left);
        deleteTree(currRoot->right);
        deleteNode(currRoot); 
        currRoot = nullptr; 
    }
}

void Table::deleteNode(Node *& target)
{
       
        if(!target->left && !target->right)
        {
                delete target->data;
                delete target;
                target = nullptr;
        }
        
        else if(!target->right)
        {
                Node * temp = target;
                target = target->left;
                delete temp->data;
                delete temp;
        }
       
        else if(!target->left)
        {
                Node * temp = target;
                target = target->right;
                delete temp->data;
                delete temp;
        }
        
        else
        {
                
                Node * prev = nullptr;
                Node * curr = target->right;    
                if(!curr->left)                                 
                {
                        target->right = curr->right;
                }
                else
                {
                        while(curr->left)
                        {
                                prev = curr;
                                curr = curr->left;                      
                        }
                        prev->left = curr->right;
                }
                delete target->data;
                target->data = curr->data;
                delete curr;
                return;
        }
}
bool Table::retrieve(const char* key, info& ainfo) const {
    return retriev(root, key, ainfo); 
}

bool Table::retriev(Node* currRoot, const char* key, info& ainfo) const{
    if (currRoot == nullptr) {
        return false;
    }

    
    int compareResult = strcmp(key, currRoot->data->get_name());

    if (compareResult == 0) {
        
        ainfo = *(currRoot->data);
        return true;
    } else if (compareResult < 0) {
        
        return retriev(currRoot->left, key, ainfo);
    } else {
        
        return retriev(currRoot->right, key, ainfo);
    }
}

const Table& Table::operator= (const Table& tableSrc)
{
        if(this == &tableSrc)
                return *this;
        if(this->root)
        {
                destroy(this->root);
        }
        size = tableSrc.size;
        copy(tableSrc.root, this->root);
        return *this;
}

void Table::copy(Node * srcRoot, Node *& destRoot)
{
        if(srcRoot)
        {
                destRoot = new Node(*(srcRoot->data));
                copy(srcRoot->left, destRoot->left);
                copy(srcRoot->right, destRoot->right);
        }
        else
        {
                destRoot = nullptr;
        }
}
ostream& operator<< (ostream& out, const Table& srcTable)
{
        out << endl << "Displaying the tree ..." << endl;
        srcTable.display(out, srcTable.root);
        return out;
}


void Table::display(ostream& out, Node * currRoot) const
{
        
        out << endl << "In-order showing the tree ..." << endl;
        displayInorder(out, currRoot);
        
}
void Table::displayInorder(ostream& out, Node * currRoot) const
{
        if(currRoot)
        {
                displayInorder(out, currRoot->left);
                out << *(currRoot->data) << endl;
                displayInorder(out, currRoot->right);
        }
}

int Table::height() const {
    return height(root, 0); 
}

int Table::height(Node* currRoot, int level) const {
    if (currRoot == nullptr) {
        return -1;
    }

    
    cout << "Node: " << currRoot->data->get_name() << " at level " << level << endl;

    
    int leftHeight = height(currRoot->left, level + 1); 
    int rightHeight = height(currRoot->right, level + 1); 

    
    return 1 + max(leftHeight, rightHeight);
}



void Table::loadFromFile(const char * fileName)
{
    ifstream in;
    info currInfo;
    const int MAX_CHAR = 101;
    char currTopic[MAX_CHAR];
    char currName[MAX_CHAR];
    char currReview[MAX_CHAR];
    int currRating;
    info* tempArray;
    int index = 0;
    int numberOfRecords;

    in.open(fileName);
    if (!in)
    {
        cerr << "Fail to open " << fileName << " for reading!" << endl;
        exit(1);
    }
    in >> numberOfRecords;
     if (in.eof()) {
        cout << "File is empty." << endl;
        in.close();
        return;
    }
    in.ignore(MAX_CHAR, '\n');
    tempArray = new info[numberOfRecords];

    while (index < numberOfRecords && in.get(currName, MAX_CHAR, ';'))
    {
        in.ignore(); // Ignore the delimiter

        in.get(currTopic, MAX_CHAR, ';');
        in.ignore(); // Ignore the delimiter

        in.get(currReview, MAX_CHAR, ';');
        in.ignore(); // Ignore the delimiter

        in >> currRating;
        in.ignore(); // Ignore the newline character

        // Set the data for the current info object
        currInfo.set_topic(currTopic);
        currInfo.set_review(currReview);
        currInfo.set_rating(currRating);

        // Store the info object in the array
        tempArray[index++] = currInfo;
    }

    in.close();

    // Load data from the temporary array into the table
    loadFromArray(tempArray, 0, numberOfRecords - 1);

    
    delete[] tempArray;
}

void Table::loadFromArray(info * infoList, int first, int last)
{
        int mid;
        if(first <= last)
        {
                mid = (first + last) / 2;
                add(infoList[mid]);
                loadFromArray(infoList, first, mid-1);
                loadFromArray(infoList, mid+1, last);
        }
}

void Table::saveToFile(const char* fileName) const {
    
    ofstream        out;

    out.open(fileName);
    if (!out) {
        cerr << "Fail to open " << fileName << " for writing!" << endl;
        exit(1);
    }

    out << this->size << endl;
    saveToFile(out, this->root);

    out.close();
}

void Table::saveToFile(ostream& out, Node* currRoot) const {
    if (currRoot) {
        saveToFile(out, currRoot->left);
        out << *(currRoot->data) << endl;
        saveToFile(out, currRoot->right);
    }
}


#include "web.h"
#include "myutil.h"
#include <fstream>

class Table {
public:
    Table();
    Table(const Table& aTable);
    ~Table();

    void add(const info& ainfo);
    bool remove(const char* key, info& ainfo);
    bool remove_topic(const char* topic);
    void insert(const char* key, info& ainfo);
    
    
   
    int getSize() const;
    bool retrieve(const char* key, info& ainfo) const;
    int height() const;
    

    const Table& operator=(const Table& aTable);
    friend ostream& operator<< (ostream& out, const Table& aTable);

    void loadFromFile(const char * fileName);
    void saveToFile(const char * fileName) const;
    
    

private:
    struct Node {
        Node(const info& ainfo) {
            data = new info(ainfo);
            left = right = nullptr;
        };

        info* data;
        Node* left;
        Node* right;
    };

    Node* root;
    int size;

    void add(Node*& currRoot, const info& ainfo);
    void destroy(Node*& currRoot);
    void copy(Node* srcRoot, Node*& destRoot);
    bool remove(Node*& currRoot, const char* key, info& ainfo);
    void deleteNode(Node*& target);
    bool remove_to(Node*& currRoot, const char* topic);
    void deleteTree(Node*& currRoot);
    void display(ostream& out, Node * currRoot) const;
    void displayInorder(ostream& out, Node * currRoot) const;
    bool retriev(Node* currRoot, const char* key, info& ainfo) const;
    int height(Node* currRoot, int level) const;
    void saveToFile(ostream& out, Node * currRoot) const;
    void loadFromArray(info * infoList, int first, int last);
    
};



#include <iostream>
#include <string.h>
#include <fstream>
#include "LINKEDLIST.cpp"
#include "READFILE.cpp"
using namespace std;
class TREE
{
    int freq;
    string info;
    TREE *left;
    TREE *right;
    string type;

public:
    TREE() : info("$"), freq(0), left(NULL), right(NULL), type("leaf") {}
    TREE(int f, string ch) : info(ch), freq(f), left(NULL), right(NULL) {}

    TREE *Huffman_tree_creator(Linkedlist *head)
    {

        while (head != nullptr && head->getNext() != NULL)
        {

            // nodes of linked list type to store lowest freq datas to make node for tree
            Linkedlist *linkedlistnode_first = head->getfirst();
       

            Linkedlist *linkedlistnode_second = head->getfirst();
       
            // nodes of tree type

            TREE *newnode = new TREE(linkedlistnode_first->getFreq() + linkedlistnode_second->getFreq(), (linkedlistnode_first->getInfo() + linkedlistnode_second->getInfo()));
            newnode->type = "root";

            // linking nodes of tree

            newnode->left = linkedlistnode_first->getTreeNode()!=NULL ? linkedlistnode_first->getTreeNode() : new TREE(linkedlistnode_first->getFreq(), linkedlistnode_first->getInfo());
    
            newnode->right = linkedlistnode_second->getTreeNode() != NULL ? linkedlistnode_second->getTreeNode() : new TREE(linkedlistnode_second->getFreq(), linkedlistnode_second->getInfo());

            




            head->add(newnode->info, newnode->freq, newnode);

            head->sort();
            head = head->gethead();
            cout << "Combining nodes: "
                 << linkedlistnode_first->getInfo() << "(" << linkedlistnode_first->getFreq() << ") and "
                 << linkedlistnode_second->getInfo() << "(" << linkedlistnode_second->getFreq() << ")" << endl;

            cout << "New node created with frequency: " << newnode->freq << endl;

            head->dis();
            cout<<newnode->left->info<<"("<<newnode->left->freq<<")<-"<<newnode->info<<"("<<newnode->freq<<")->"<<newnode->right->info<<"("<<newnode->right->freq<<")"<<endl;
            
            cout<<endl;
        }

        return head->getTreeNode();
    }

    void displaytree(TREE *root, string ch)
    {
        if (!root)
        {
            return;
        }

        cout << root->info << "(" << root->freq << ", " << ch << ") -> ";

        displaytree(root->left, ch + "0");
        displaytree(root->right, ch + "1");
    }
};

int main()
{
    Linkedlist l1;
    TREE t1;
    readfromfile(l1);

    Linkedlist *head = l1.gethead();
    // l1.dis();

    TREE *root = t1.Huffman_tree_creator(head);

    cout << endl
         << "THE TREE MADE IS " << endl;
    t1.displaytree(root, "");

    return 0;
}
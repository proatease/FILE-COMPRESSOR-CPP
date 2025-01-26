
#include <iostream>
#include <string.h>
#include <fstream>
#include "LINKEDLIST.cpp"
#include "READFILE.cpp"
using namespace std;
class TREE
{
    int freq;
    char info;
    TREE *left;
    TREE *right;

public:
    TREE() : info('$'), freq(0), left(NULL), right(NULL) {}
    TREE(int f, char ch) : info(ch), freq(f), left(NULL), right(NULL) {}

    TREE *Huffman_tree_creator(Linkedlist *head)
    {
        while (head && head->getNext())
        {

            // nodes of linked list type to store lowest freq datas to make node for tree

            Linkedlist *linkedlistnode_first = new Linkedlist;
            linkedlistnode_first=head->getfirst();


            Linkedlist *linkedlistnode_second = new Linkedlist;
            linkedlistnode_second= head->getfirst();

            // nodes of tree type

            TREE *newnode = new TREE;
            TREE *treenode_left = new TREE;
            TREE *treenode_right = new TREE;

            // this is formed by combinig two least linked list nodes

            newnode->freq = linkedlistnode_first->getFreq() + linkedlistnode_second->getFreq();

            // left leaf of third formed node (named newnode)
            newnode->left = treenode_left;
            treenode_left->freq = linkedlistnode_first->getFreq();
            treenode_left->info = linkedlistnode_first->getInfo();

            // right leaf of third formed node(named newnode)
            newnode->right = treenode_right;
            treenode_right->freq = linkedlistnode_second->getFreq();
            treenode_right->info = linkedlistnode_second->getInfo();

            // arranging dat as of linked list type in new node formed by combinig prev. two nodes

            // making new node of linked list type to add in linked list with new freq.

            Linkedlist *newlinkedlist_formed = new Linkedlist(newnode->info, newnode->freq);
            newlinkedlist_formed->add(newnode->info,newnode->freq);
            head->sort();
            cout << "Combining nodes: "
                 << linkedlistnode_first->getInfo() << "(" << linkedlistnode_first->getFreq() << ") and "
                 << linkedlistnode_second->getInfo() << "(" << linkedlistnode_second->getFreq() << ")" << endl;

            cout << "New node created with frequency: " << newnode->freq << endl;
            /* delete linkedlistnode_first;
            delete linkedlistnode_second;
            delete newlinkedlist_formed; */
            head->dis();
            cout << "hello" << endl;
        }
       
        return new TREE(head->getInfo(), head->getFreq());
    }

    void displaytree(TREE *root, string ch)
    {
        if (!root)
        {
            return;
        }
        if (root->info != '$')
        {
            cout << root->info << "(" << root->freq << ") ->";
        }
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

    

    TREE *root = t1.Huffman_tree_creator(head);

    

    t1.displaytree(root, "");

    return 0;
}
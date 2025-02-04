#include <iostream>
#include <string.h>
#include <unordered_map>
#include <fstream>
#include "LINKEDLIST.cpp"
#include "READFILE.cpp"
#include <bitset>
using namespace std;
unordered_map<string, pair<int, int>> huffmanCodes;
class TREE
{
public:
    int freq;
    string info;
    TREE *left;
    TREE *right;
    string type;

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
            newnode->left = (linkedlistnode_first->getTreeNode() != NULL) ? linkedlistnode_first->getTreeNode() : new TREE(linkedlistnode_first->getFreq(), linkedlistnode_first->getInfo());

            newnode->right = (linkedlistnode_second->getTreeNode() != NULL) ? linkedlistnode_second->getTreeNode() : new TREE(linkedlistnode_second->getFreq(), linkedlistnode_second->getInfo());

            head->add(newnode->info, newnode->freq, newnode);

            head->sort();
            head = head->gethead();
            /*  cout << "Combining nodes: "
                  << linkedlistnode_first->getInfo() << "(" << linkedlistnode_first->getFreq() << ") and "
                  << linkedlistnode_second->getInfo() << "(" << linkedlistnode_second->getFreq() << ")" << endl;

             cout << "New node created with frequency: " << newnode->freq << endl;

             cout<<newnode->left->info<<"("<<newnode->left->freq<<")<-"<<newnode->info<<"("<<newnode->freq<<")->"<<newnode->right->info<<"("<<newnode->right->freq<<")"<<endl;
             head->dis();

             cout<<endl; */
        }

        return head->getTreeNode();
    }

    void displaytree(TREE *root, int code, int length)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            huffmanCodes[root->info] = {code, length};
            int x = length;
            // cout << root->info << " ->  " << bitset<16>(code) << " (Length: " << length << " bits)" << endl;
            cout << root->info << " ->  " << std::bitset<32>(code).to_string().substr(32 - x)
                  << endl;
            return;
        }

        displaytree(root->left, (code << 1), length + 1);
        displaytree(root->right, (code << 1) | 1, length + 1);
    }
};

// tree upto here
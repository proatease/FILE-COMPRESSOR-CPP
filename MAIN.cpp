#include <iostream>
#include "TREE.cpp"
using namespace std;
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

void encode_to_new_file(unordered_map<string, pair<int, int>>& huffmanCodes) {
    ifstream in(filename, ios::binary);
    ofstream out("HUFFMANENCODED.zip", ios::binary);

    if (!in || !out) {
        cerr << "Error opening files!" << endl;
        return;
    }

    unsigned char buffer = 0;
    int bitCount = 0;
    int totalBits = 0;  // Track total valid bits

    char ch;
    while (in.get(ch)) {
        int code = huffmanCodes[string(1, ch)].first;
        int length = huffmanCodes[string(1, ch)].second;
        totalBits += length;  // Count total bits

        for (int i = length - 1; i >= 0; --i) {
            buffer = (buffer << 1) | ((code >> i) & 1);
            bitCount++;

            if (bitCount == 8) {
                out.put(buffer);
                buffer = 0;
                bitCount = 0;
            }
        }
    }

    // If there are leftover bits, pad with zeros and write them
    if (bitCount > 0) {
        buffer <<= (8 - bitCount);
        out.put(buffer);
    }

    in.close();
    out.close();

    // Store the total valid bits as metadata in a separate file
    ofstream meta("HUFFMAN_METADATA.txt");
    meta << totalBits;  
    meta.close();
}

void decode_from_file(TREE* root) {
    ifstream in("HUFFMANENCODED.zip", ios::binary);
    ofstream out("DECODED.txt", ios::binary);
    ifstream meta("HUFFMAN_METADATA.txt");

    if (!in || !out || !meta) {
        cerr << "Error opening files!" << endl;
        return;
    }

    int totalBits;
    meta >> totalBits;  // Read the number of valid bits
    meta.close();

    TREE* current = root;
    unsigned char byte;
    int bitsRead = 0;  // Track how many bits we have read

    while (in.get(reinterpret_cast<char&>(byte)) && bitsRead < totalBits) {
        for (int i = 7; i >= 0 && bitsRead < totalBits; --i) {  
            bool bit = (byte >> i) & 1;
            current = bit ? current->right : current->left;
            bitsRead++;

            if (!current->left && !current->right) {
                out.put(current->info[0]);
                current = root;
            }
        }
    }

    in.close();
    out.close();
}



int main()
{
    Linkedlist l1;
    TREE t1;
    readfromfile(l1);

    Linkedlist *head = l1.gethead();

    TREE *root = t1.Huffman_tree_creator(head);

    cout << endl
         << "THE TREE MADE IS " << endl;
    t1.displaytree(root, 0, 0);
    encode_to_new_file(huffmanCodes);
   decode_from_file(root);
   return 0;
}
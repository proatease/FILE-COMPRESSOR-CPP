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
        ofstream out("HUFFMANENCODED.txt");

        if (!in || !out) {
            cerr << "Error opening files!" << endl;
            return;
        }

        char ch;
        while (in.get(ch)) {
            int code = huffmanCodes[string(1, ch)].first;    // Get binary code
            int length = huffmanCodes[string(1, ch)].second; // Get number of bits

            // Convert the Huffman code to a binary string
            string binaryCode = "";
            for (int i = length - 1; i >= 0; --i) {
                binaryCode += ((code >> i) & 1) ? "1" : "0"; // Append '1' or '0' to the binary string
            }

            // Write the binary code to the output file as text
            out << binaryCode;
        }

        in.close();
        out.close();
    }





void decode_from_file(TREE* root) {
        ifstream in("HUFFMANENCODED.txt", ios::binary);  // Read the encoded file
        ofstream out("DECODED.txt", ios::binary);  // Write the decoded file

        if (!in || !out) {
            cerr << "Error opening files!" << endl;
            return;
        }

        TREE* current = root;  // Start from the root of the Huffman tree
        string encodedBits = "";

        // Read the encoded bits from the file
        char ch;
        while (in.get(ch)) {
            encodedBits += ch;  // Add the character (which will be '1' or '0') to the string
        }

        // Now decode the Huffman string
        for (char bit : encodedBits) {
            current = (bit == '1') ? current->right : current->left;  // Traverse the tree based on the bit

            // If we reach a leaf node, output the character
            if (!current->left && !current->right) {
                out.put(current->info[0]);  // Write the decoded character to the output file
                current = root;  // Reset back to the root of the tree for the next character
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
#include <iostream>
#include "TREE.cpp"
using namespace std;
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <thread> // For sleep_for
#include <chrono>
using namespace std;

void encode_to_new_file(unordered_map<string, pair<int, int>> &huffmanCodes)
{

    // animation part

    int total = 100, delayMs = 10, barWidth = 20; // Width of the progress bar
    int size = 0;
    for (int i = 0; i <= total; i++)
    {
        float progressRatio = float(i) / total;
        cout << "ENCODING FILE  [";
        // Display the progress as "#"
        int pos = barWidth * progressRatio;
        for (int j = 0; j < barWidth; ++j)
        {
            if (j < pos)
            {
                cout << "#"; // Progress
            }
            else
            {
                cout << "-"; // Remaining
            }
        }

        cout << "] " << int(progressRatio * 100) << " %\r";    // Show the percentage progress
        cout.flush();                                          // Immediately update the output
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // Add delay to simulate file reading
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // animation upto here


    ifstream in(filename, ios::binary);
    ofstream out("HUFFMAN_ENCODED.zip", ios::binary);

    if (!in || !out)
    {
        cout << "Error opening files!" << endl;
        return;
    }

    int totalEncodedSizeBytes = 0;
    unsigned char buffer = 0;
    int bitCount = 0;
    int totalBits = 0; // Track total valid bits

    char ch;
    while (in.get(ch))
    {
        int code = huffmanCodes[string(1, ch)].first;
        int length = huffmanCodes[string(1, ch)].second;
        totalBits += length; // Count total bits

        for (int i = length - 1; i >= 0; --i)
        {
            buffer = (buffer << 1) | ((code >> i) & 1);
            bitCount++;

            if (bitCount == 8)
            {
                out.put(buffer);
                buffer = 0;
                bitCount = 0;
                totalEncodedSizeBytes++;
            }
        }
    }

    // If there are leftover bits, pad with zeros and write them
    if (bitCount > 0)
    {
        buffer <<= (8 - bitCount);
        out.put(buffer);
        totalEncodedSizeBytes++;
    }

    in.close();
    out.close();

    // Store the total valid bits as metadata in a separate file
    ofstream meta("HUFFMAN_METADATA.txt");
    meta << totalBits;
    meta.close();
    cout << endl;
    cout << endl;
    cout << "-------- ENCODING COMPLETED ^_^ ---------" << endl;
    cout<<endl;
     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << " ZIP FILE ->( HUFFMAN_ENCODED.zip )<- CREATED " << endl;
    cout<<endl;
     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout<<"SIZE OF ->( HUFFMAN_ENCODED.zip )<-  = "<<totalEncodedSizeBytes<<" BYTES "<<endl;
    cout<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void decode_from_file(TREE *root)
{

    ifstream in("HUFFMAN_ENCODED.zip", ios::binary);
    ofstream out("DECODED.txt", ios::binary);
    ifstream meta("HUFFMAN_METADATA.txt");

    if (!in || !out || !meta)
    {
        cout << "Error opening files!" << endl;
        return;
    }

    else
    {
            // animation part
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    int total = 100, delayMs = 10, barWidth = 20; // Width of the progress bar
    int size = 0;
    for (int i = 0; i <= total; i++)
    {
        float progressRatio = float(i) / total;
        cout << "DECODING FILE  [";
        // Display the progress as "#"
        int pos = barWidth * progressRatio;
        for (int j = 0; j < barWidth; ++j)
        {
            if (j < pos)
            {
                cout << "#"; // Progress
            }
            else
            {
                cout << "-"; // Remaining
            }
        }

        cout << "] " << int(progressRatio * 100) << " %\r";    // Show the percentage progress
        cout.flush();                                          // Immediately update the output
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // Add delay to simulate file reading
    }

    // animation upto here

    

    int totalBits;
    meta >> totalBits; // Read the number of valid bits
    meta.close();

    TREE *current = root;
    unsigned char byte;
    int bitsRead = 0; // Track how many bits we have read

    while (in.get(reinterpret_cast<char &>(byte)) && bitsRead < totalBits)
    {
        for (int i = 7; i >= 0 && bitsRead < totalBits; --i)
        {
            bool bit = (byte >> i) & 1;
            current = bit ? current->right : current->left;
            bitsRead++;

            if (!current->left && !current->right)
            {
                out.put(current->info[0]);
                current = root;
            }
        }
    }

    in.close();
    out.close();
    cout << endl;
    cout << endl;
    cout << "-------- DECODING COMPLETED ^_^ ---------" << endl;
    cout<<endl;
    cout << "DECOMPRESSION OF ->( HUFFMAN_ENCODED.zip )<-   COMPLETED AND ->( DECODED.txt )<- CREATED  " << endl;
    }
    
}

int main()
{
    char opinion;

    Linkedlist l1;
    TREE t1;
    readfromfile(l1);

    Linkedlist *head = l1.gethead();

    TREE *root = t1.Huffman_tree_creator(head);

    cout << endl<< "HUFFMAN CODES : " << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    t1.displaytree(root, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout << endl;
    cout << endl;
    cout << "ENTER  'E' FOR ENCODING ->( " << filename << " )<- / 'X' FOR EXITING THE COMPRESSOR " << endl;
    cin >> opinion;
    if (opinion == 'e' || opinion == 'E')
    {
        encode_to_new_file(huffmanCodes);
        cout << "ENTER  'D' FOR DECODING -> HUFFMAN_ENCODED.zip <- / 'X' FOR ENDING THE COMPRESSOR " << endl;
        cin >> opinion;
        if (opinion == 'D' || opinion == 'd')
        {

            decode_from_file(root);
        }
    }

    return 0;
}
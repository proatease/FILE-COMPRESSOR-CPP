#pragma once

#include <iostream>
#include <fstream>
#include "LINKEDLIST.cpp" //adding linkedlist file to this file
using namespace std;

void readfromfile(Linkedlist &l1)
{
     
    string filename;

    // cout << "Enter the file name: ";
    // cin >> filename;

    ifstream inputFile("readthis.txt");

    if (!inputFile)
    {
        cout << "Error: Could not open the file!" << endl;
        //  return 1;
    }

    char ch;
    cout << "Contents of the file:" << endl;

    // reading the contents of file character by character

    while (inputFile.get(ch))
    {

        cout << ch <<" ";
        // condition if found
        if (l1.search(ch))
        {
            l1.increment(ch);
            l1.sort();
        }
        // adding a node for new character
        else
        {
            l1.add(ch);
        }
    }
    l1.dis();
    inputFile.close();
}

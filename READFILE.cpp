#pragma once

#include <iostream>
#include <fstream>
#include "LINKEDLIST.cpp" //adding linkedlist file to this file
using namespace std;
string filename;

void readfromfile(Linkedlist &l1)
{


    // cout << "Enter the file name: ";
    // cin >> filename;
    filename="readthis.txt";
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cout << "Error: Could not open the file!" << endl;
        //  return ;
    }

    char ch;
    cout << "Contents of the file:" << endl;

    // reading the contents of file stringacter by stringacter

    while (inputFile.get(ch) )
    {
        string str(1, ch); // Convert character to string

        cout << str ;
        // condition if found
        if (l1.search(str))
        {
            l1.increment(str);
        }
        // adding a node for new stringacter
        else
        {
            l1.add(str);
        }
    }
        cout<<endl;
    l1.sort();
    l1.dis();
    inputFile.close();
}

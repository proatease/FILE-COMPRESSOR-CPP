#pragma once
#include <iostream>
#include <fstream>
#include "LINKEDLIST.cpp" //adding linkedlist file to this file
#include <thread>         // For sleep_for
#include <chrono>         // For milliseconds
using namespace std;
string filename;

void readfromfile(Linkedlist &l1)
{
    cout<<endl;
    cout << "Enter name of the file to compress : ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile)
    {
        cout << "Error: Could not open the file!" << endl;
        //  return ;
    }
    else
    {
        // animation starts
        int size = 0;
        int total = 100, delayMs = 10, barWidth = 20; // Width of the progress bar
        cout << endl;
        cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        for (int i = 0; i <= total; i++)
        {
            float progressRatio = float(i) / total;
            cout << "READING FILE [";
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

        // animation ends here

         cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << endl<< "----------  READ FILE SUCCESSFULLY   -----------" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        cout << endl;
        cout << "CONTENTS OF FILE : " << filename << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        char ch;
        // reading the contents of file stringacter by stringacter
        cout << endl;
        while (inputFile.get(ch))
        {
            string str(1, ch); // Convert character to string
            size ++;
            cout << str;
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
        cout << endl;
        cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "SIZE OF ->(" << filename << ")<-  = " << size << " BYTES" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        l1.sort();
        // l1.dis();
        inputFile.close();
        cout << endl;

    }
}

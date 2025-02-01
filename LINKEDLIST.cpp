#pragma once
#include <iostream>
using namespace std;
#include<string.h>
// linked list class making

class Linkedlist
{
    string info;
    int freq;
    Linkedlist *next;
    static Linkedlist *head;

public:
    Linkedlist() : info(""), freq(0), next(NULL) {}
    Linkedlist(string ch, int f) : info(ch), freq(f), next(NULL) {}

    void add(string n, int f = 1)
    {
        Linkedlist *newLinkedlist = new Linkedlist();
        newLinkedlist->next = head;
        head = newLinkedlist;
        newLinkedlist->info = n;
        newLinkedlist->freq = f;
    }
    bool search(string n)
    {

        Linkedlist *temp = head;
        while (temp != NULL)
        {
            if (temp->info == n)
            {
                return true; // Found the stringacter
            }
            temp = temp->next;
        }
        return false; // Not found
    }

    void increment(string n)
    {
        Linkedlist *temp = head;
        while (temp != NULL)
        {
            if (temp->info == n)
            {
                temp->freq++;
                //cout << "Frequency of " << n << " increased to " << temp->freq << endl;
                return; // Exit after incrementing the frequency
            }
            temp = temp->next;
        }
    }

    void sort()
    {
        if (head == NULL || head->next == NULL)
            return ; // No need to sort if the list is empty or has only one element

        Linkedlist *current, *index;
        string tempstring;
        int tempFreq;

        for (current = head; current != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->freq > index->freq)
                {
                    // Swap info values
                    tempstring = current->info;
                    current->info = index->info;
                    index->info = tempstring;

                    // Swap frequency values
                    tempFreq = current->freq;
                    current->freq = index->freq;
                    index->freq = tempFreq;
                }
            }
        }
    }
    void dis()
    {
        Linkedlist *temp = head;
        while (temp != NULL)
        {
            cout << temp->info << " =  " << temp->freq << endl;
            temp = temp->next;
        }
    }
    string getInfo()
    {
        return info;
    }
    int getFreq()
    {
        return freq;
    }
    Linkedlist *getNext()
    {
        return next;
    }
    Linkedlist *getfirst()
    {
        if (!head)
        {
            return NULL;
        }
        Linkedlist *temp = head;
        head = head->next;
        // temp->next = NULL;
        return temp;
    }
    Linkedlist *gethead()
    {
        return head;
    }
    Linkedlist *gethead1()
    {
        return head;
    }
};
Linkedlist *Linkedlist::head = NULL;

// LINKED LIST UPTO HERE

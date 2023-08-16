#include <iostream>
#include <fstream>
#include <algorithm> 
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

class orderedList{
    private:
        unique_ptr<int[]> arr = nullptr;
        int current; // current number of items filled
        int count; // op count
    public:
        orderedList(); // default contructor
        orderedList(int ); // overloaded constructor
        ~orderedList(); // deconstructor

        void add(int ); // add number to back of list
        bool search(int ); // searches query 
        int getCount(); // returns the count of traversals
        int size(); // returns the size of arr
        void print(); // prints MTFList contents
};

#endif
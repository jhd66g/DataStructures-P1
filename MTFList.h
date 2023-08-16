#include <iostream>
#include <fstream>
#include <algorithm> 

using std::ifstream;
using std::cout;
using std::endl;

#ifndef MTFLIST_H
#define MTFLIST_H

// Your Node definition here....
struct Node {
	int data;
	Node *link;
	Node(): data{0}, link{nullptr} {}
	Node(int data, Node *p = nullptr): data{data}, link{p}{}
	~Node(){}
};

class MTFList{
    private:
        Node *head; // head pointer
        int count;
    public:
        MTFList(): head{nullptr}, count {0} {} // constructor
        ~MTFList(); // deconstructor

        void add(int ); // adds new items to MTFlist
        bool search(int ); // searches query 
        int getCount(); // returns the count of traversals
        void print(); // prints MTFList contents
};

#endif
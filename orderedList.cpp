#include "orderedList.h"

// constructors

// default contructor
orderedList::orderedList(): arr{new int[5]}, current{0}, count {0}{} 

// overloaded constructor
orderedList::orderedList(int num): arr{new int[num]}, current{0}, count {0}{}

// deconstructor
orderedList::~orderedList() = default;

// add number to back of list
void orderedList::add(int num){
    arr[current] = num;
    current ++;
    return;
} 

// searches query 
bool orderedList::search(int num){
    int first {0};
    int mid {0};
    int last = size() -1;
    while (first <= last){
        mid = (first + last)/2;
        count ++; // update count
        if (arr[mid] < num){
            first = mid + 1;
        }
        else if (arr[mid] > num){
            last = mid - 1;
        }
        else{
            return true;
        }
    }
    return false;
} 

// returns the count of traversals
int orderedList::getCount(){
    return count;
} 

// returns the size of arr
int orderedList::size(){
    return current;
} 

// prints MTFList contents
void orderedList::print(){
    for (int i = 0; i < size(); i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <chrono>
#include "MTFList.h"
#include "orderedList.h"

using std::list;
using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char* argv[]){
    // set up
    int length; // length of list
    int temp; // temporarily stores int

    // open file and populate lists
    ifstream fstr(argv[1]); // opens file by command line
    fstr >> length; // 1st line of file 
    MTFList MTFList; // creates MTFList
    orderedList orderedList(length); // creates orderedList
    for (int i = 0; i < length; i++){
        fstr >> temp;
        MTFList.add(temp);
        orderedList.add(temp);
    }

    // query set up
    int queries; // query count
    fstr >> queries; // next line is the # of queries
    int queryList [queries]; // array holding queries
    for (int i = 0; i < queries; i ++){
        fstr >> temp;
        queryList[i] = temp;
    }

    // searching and timing 
    auto MTFstart = std::chrono::steady_clock::now(); // start time
    for (int i = 0; i < queries; i++){
        MTFList.search(queryList[i]);
    }
    auto MTFend = std::chrono::steady_clock::now(); // end time 
    auto MTFduration = std::chrono::duration_cast<std::chrono::nanoseconds> (MTFend - MTFstart).count();

    auto Ostart = std::chrono::steady_clock::now(); // start time
    for (int i = 0; i < queries; i++){
        orderedList.search(queryList[i]);
    }
    auto Oend = std::chrono::steady_clock::now(); // end time 
    auto Oduration = std::chrono::duration_cast<std::chrono::nanoseconds> (Oend - Ostart).count();

    // print results 
    cout << "MTFList after queries: ";
    MTFList.print();
    cout << "orderedList after queries: ";
    orderedList.print();
    cout << "MTFList Traversal Count: " << MTFList.getCount() << endl;
    cout << "MTFList Time: " << MTFduration << " nanoseconds" << endl;
    cout << "orderedList Traversal Count: " << orderedList.getCount() << endl;
    cout << "orderedList Time: " << Oduration << " nanoseconds" << endl;
    cout << endl;
    if (MTFduration < Oduration){
        cout << "MTFList is faster for this data." << endl;
    }
    else if (MTFduration > Oduration){
        cout << "orderedList is faster for this data." << endl;
    }
    else{
        cout << "Same duration." << endl;
    }


    return 0;
}
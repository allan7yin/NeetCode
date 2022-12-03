//
//  main.cpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-10-01.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc, const char * argv[]) {
    unordered_set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(3);
    
    cout << *(mySet.find(3));
    // print out the contents of the set
    for (auto p = mySet.begin(); p != mySet.end(); ++p) {
        cout << *p << endl;
    }
}

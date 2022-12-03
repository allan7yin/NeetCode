//
//  Valid_Anagram.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-10-02.
//

#ifndef Valid_Anagram_hpp
#define Valid_Anagram_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}
        
        // one solution it to make a ASCII array and compare from there
        int ascii[126] = {0}; // intializes every array value to 0
        
        for (int i = 0; i < s.size(); i++) {
            ascii[s[i]]++;
        }
        
        // now, ar every character's position, we should have it be eqal to the number of times it occured in the word
        
        for (int i = 0; i < t.size(); i++) {
            ascii[t[i]]--;
        }
        
        // now need to check if everything is equal to 0, which it should be for t to be an anagram of s
        
        bool cond = true;
        for (int i = 0; i < 126; i++) {
            if (ascii[i] != 0) {
                cond = false;
                break;
            }
        }
        
        return cond;
        
    }
};
#endif /* Valid_Anagram_hpp */

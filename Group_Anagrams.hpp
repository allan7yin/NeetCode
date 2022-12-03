//
//  Group_Anagrams.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-10-02.
//

#ifndef Group_Anagrams_hpp
#define Group_Anagrams_hpp

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // use unordered map
        unordered_map<string, vector<string>> m;
        
        // provide a hash function, that will hash a string into a vector
        
        for (int i = 0; i < strs.size(); i++) {
            string key = createKey(strs[i]);
            m[key].emplace_back(strs[i]);
        }
        
        vector<vector<string>> answer;
        for (auto it=m.begin(); it != m.end(); it++) {
            answer.emplace_back(it->second);
        }
        
        return answer;
    }
    
    string createKey(string word) {
        vector<int> count(26);
        for (int i = 0; i < word.size(); i++) {
            count[word[i]-'a']++;
        }
        
        string key="";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a'));
        }
        
        return key;
    }
};

#endif /* Group_Anagrams_hpp */

/*
 some general notes about this question. The keys of a map are unique. So, we want to be able to associate all anagrams with one instance of "them". Hence, we hash them into
 a string that will act as our key for the map
 
 
 The above would hash a word like :"allan" into something like:
 2a0b0c0d0e0f0g0h0i0j0k2l0m1n0p0q0r0s0t0uy0v0w0x0y0z
 
 This will allow us to hash all anagrams under one key
 */

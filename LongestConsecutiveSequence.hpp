//
//  LongestConsecutiveSequence.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-11-25.
//

#ifndef LongestConsecutiveSequence_hpp
#define LongestConsecutiveSequence_hpp

#include <stdio.h>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int length = nums.size();
        
        int longest = 0;
        // now that the set is setup, we can iterate through the vector
        for (auto &n: set) {
            if (set.find(n-1) == set.end()) {
                int index = 1;
                while (set.find(n+index) != set.end()) {
                    // means found it
                    index++;
                }
                
                if (index > longest) { 
                    longest = index;
                }
            }
        }
        
        return longest;
    }
};

#endif /* LongestConsecutiveSequence_hpp */

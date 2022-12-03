//
//  ContainsDuplicatesSol2.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-10-01.
//

#ifndef ContainsDuplicatesSol2_hpp
#define ContainsDuplicatesSol2_hpp

#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                // find returns an iterator to end, which is the element past the end of the
                // container. So, if not found, it will return what s.end() returns
                return true;
            }
            s.insert(nums[i]);
            // if not already in the unordered_set, add it into it
        }
        
        return false;
    }
};

#endif /* ContainsDuplicatesSol2_hpp */

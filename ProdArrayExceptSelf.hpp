//
//  ProdArrayExceptSelf.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-11-21.
//

#ifndef ProdArrayExceptSelf_hpp
#define ProdArrayExceptSelf_hpp

#include <stdio.h>
#include <vector>

using namespace std;    

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // idea is to create two new arrays which keep track of the product before and after the
        // the index's value
        int length = nums.size();
        int new_length = length+2;
        
        vector<int> prefix_vector(length+2, 1);
        vector<int> suffix_vector(length+2, 1);
        vector<int> solution(length, 1);
        
        for (int i = 1; i < new_length - 1; i++) {
            prefix_vector[i] = prefix_vector[i-1] * nums[i-1];
        }
        
        for (int i = new_length-2; i > 1 ; i--) {
            suffix_vector[i] = suffix_vector[i+1] * nums[i-1];
        }
        
        for (int i = 0; i < length; i++) {
            solution[i] = prefix_vector[i] * suffix_vector[i+2];
        }
        
        return solution;
    }
};

// so the algorithm would look something like:
/*
1| 1, 2, 3,  4 | 1
1| 1, 2, 6, 24 | 1
1| 24,24,12, 4 | 1

so, we would get
24, 12, 8, 6
*/

#endif /* ProdArrayExceptSelf_hpp */

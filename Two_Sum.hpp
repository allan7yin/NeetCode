//
//  Two_Sum.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-10-02.
//

#ifndef Two_Sum_hpp
#define Two_Sum_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1;
        int index2;
        
        bool flag = false;
        int difference;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            
            // reaching here, means the current number in the array is a potential candidate
            index1 = i;
            difference = target - nums[i]; // need this number to appear in the rest of the array
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] == difference) {
                    index2 = j;
                    flag = true;
                }
            }
            
            if (flag) {
                break;
            }
        }
        
        vector<int> solution;
        solution.emplace_back(index1);
        solution.emplace_back(index2);
        return solution;
    }
};

#endif /* Two_Sum_hpp */

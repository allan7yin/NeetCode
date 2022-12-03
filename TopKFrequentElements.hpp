//
//  TopKFrequentElements.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-11-20.
//

#ifndef TopKFrequentElements_hpp
#define TopKFrequentElements_hpp

#include <stdio.h>

// link to question: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums;
        int counter = k;
        vector<int> most_frequent;
        int length = nums.size();
        int count = 1;
        map<int, vector<int>> map;
        // again we make a map, in this case, want ordered
        // the key will be a number that represents how many times a number occurs in nums vector
        
        // to make this nlogn time efficiency, we will need to sort the vector first
        
        sort(nums, 0, length-1); // now the array should be properly sorted
        
        for (int i = 0; i < length; i++) {
            if (i == length - 1) break;
            
            if (nums[i] == nums[i+1]) {
                count++;
                if (i == length - 2) {
                    map[count].emplace_back(nums[i]);
                }
            } else {
                map[count].emplace_back(nums[i]);
                count = 1;
                if (i == length - 2) {
                    map[count].emplace_back(nums[i+1]);
                }
            }
        }
        
        for (auto it = map.rbegin(); it != map.rend(); ++it) {
            if (counter == 0) break;
            for (int j = 0; j < (it->second).size(); j++) {
                most_frequent.emplace_back((it->second)[j]);
                counter--;
            }
        }
        
        return most_frequent;
         
    }
    
    
void merge(vector<int> &nums, int begin, int mid, int end) {
    // merge the two sorted vectors into one
    vector<int> left;
    vector<int> right;

    // load the vectors
    for (int i = 0; i < (mid - begin + 1); i++) {
        left.emplace_back(nums[begin + i]);
    }

    for (int i = 0; i < (end - mid); i++) {
        right.emplace_back(nums[mid + i + 1]);
    }

    // now, we load into vector again
    int leftIndex = 0;
    int rightIndex = 0;
    int finalIndex = begin;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] <= right[rightIndex]) {
            nums[finalIndex] = left[leftIndex];
            leftIndex++;
        } else {
            nums[finalIndex] = right[rightIndex];
            rightIndex++;
        }

        finalIndex++;
    }

    // dump remaining elements into final array, will be either the left or the right
    while (leftIndex < left.size()) {
        nums[finalIndex] = left[leftIndex];
        leftIndex++;
        finalIndex++;
    }

    while (rightIndex < right.size()) {
        nums[finalIndex] = right[rightIndex];
        rightIndex++;
        finalIndex++;
    }
}

void sort(vector<int> &nums, int begin, int end) {
    int mid = (begin + end) /2;
    
    if (begin < end) {
        sort(nums, begin, mid);
        sort(nums, mid+1, end);
        merge(nums, begin, mid, end);
    }
}
};

#endif /* TopKFrequentElements_hpp */

//
//  ContainsDuplicatesSol1.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-10-01.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // first sort the array, then we look for duplicates, use merge sort
        
        bool hasDuplicates = false;
        // first sort the array
        mergeSort(nums, 0, nums.size()-1);
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                hasDuplicates = true;
            }
        }
        
        return hasDuplicates;
    }
    
    void mergeSort(vector<int> &nums, int begin, int end) {
        if (begin < end) {
            int middle = (begin + end) / 2;
            mergeSort(nums, begin, middle);
            mergeSort(nums, middle+1, end);
            merge(nums, begin, middle, end);
        }
    }
    
    void merge(vector<int> &nums, int begin, int middle, int end) {
        // merge the two sorted vectors into one
        int l_index = 0;
        int r_index = 0;
        int merged_vector_index = begin;
        
        int r_size = end - middle;
        int l_size = middle - begin + 1;
        
        vector<int> left;
        vector<int> right;
        
        for (int i = 0; i < l_size; i++) {
            left.emplace_back(nums[begin+i]);
        }
        
        for (int i = 0; i < r_size; i++) {
            right.emplace_back(nums[middle + 1 + i]);
        }
        
        while (l_index < l_size && r_index < r_size) {
            if (left[l_index] <= right[r_index]) {
                nums[merged_vector_index] = left[l_index];
                l_index++;
            } else {
                nums[merged_vector_index] = right[r_index];
                r_index++;
            }
            merged_vector_index++;
        }
        
        // now, one of the vectors will still have some numbers left in them, put them in
        
        while (l_index < l_size) {
            nums[merged_vector_index] = left[l_index];
            l_index++;
            merged_vector_index++;
        }
        
        while (r_index < r_size) {
            nums[merged_vector_index] = right[r_index];
            r_index++;
            merged_vector_index++;
        }
    }
};

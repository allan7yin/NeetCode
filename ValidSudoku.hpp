//
//  ValidSudoku.hpp
//  Arrays&Hashing
//
//  Created by Allan Yin on 2022-11-25.
//

#ifndef ValidSudoku_hpp
#define ValidSudoku_hpp

#include <stdio.h>

// THIS IS NOT THE SOLUTION, ONLY THE ATTEMPTED, TOOK TOO LONG
// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row;
        unordered_map<char, int> column;
        unordered_map<char, int> sub_square;
        char nums[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int length = 9;
        
        for (int i = 0; i < 9; i++) {
            // want to initialize the maps so that each integr 1-9 is mapped to 0
            row[nums[i]] = 0;
            column[nums[i]] = 0;
            sub_square[nums[i]] = 0;
        }
        
        // first check every row and in the entire grid
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (board[i][j] == '.' ) continue;
                row[board[i][j]]++;
                if (row[board[i][j]] > 1) {
                    return false;
                }
            }
            
            // reaching here, we want to reset the column map to refresh it
            for (int x = 1; x < 10; x++) {
                row[nums[i]] = 0;
            }
        }
        
        // now we need to test every row in the entire grid
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (board[j][j] == '.' ) continue;
                column[board[j][i]]++;
                if (column[board[j][i]] > 1) {
                    return false;
                }
            }
            
            // reaching here, we want to reset the column map to refresh it
            for (int x = 1; x < 10; x++) {
                column[nums[i]] = 0;
            }
        }
        
        unordered_map<pair<int,int>, unordered_map<char, int>> sol;
        // now, we need to check the small sub squares, first set the map
        for (int i = 0; i < 3; i++) {
            for (int j = 0; i < 3; j++) {
                pair<int, int> two;
                two.first = i;
                two.second = j;
                
                sol[two] = sub_square;
            }
        }
        
        // now that this is set up, we can now go through every point
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (board[i][j] == '.') continue;
                pair<int, int> coordinate;
                coordinate.first = i/3;
                coordinate.second = j/3;
                sol[coordinate][board[i][j]]++;
                
                if (sol[coordinate][board[i][j]] > 1) {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};











#endif /* ValidSudoku_hpp */

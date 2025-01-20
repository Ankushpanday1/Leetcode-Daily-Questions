#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Create a path matrix to track painted cells
        vector<vector<bool>> path(rows, vector<bool>(cols, false));
        
        // Counters for rows and columns
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
        
        // Map to find the position of each number in the matrix
        unordered_map<int, pair<int, int>> positionMap;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                positionMap[mat[i][j]] = {i, j};
            }
        }

        // Iterate through arr and paint cells
        for (int index = 0; index < arr.size(); index++) {
            int number = arr[index];
            if (positionMap.find(number) != positionMap.end()) {
                auto pos = positionMap[number];
                int r = pos.first;
                int c = pos.second;
                
                // Paint the cell
                path[r][c] = true;
                rowCount[r]++;
                colCount[c]++;
                
                // Check if any row or column is completely painted
                if (rowCount[r] == cols || colCount[c] == rows) {
                    return index;
                }
            }
        }
        
        return -1; // If no complete row or column is found
    }
};
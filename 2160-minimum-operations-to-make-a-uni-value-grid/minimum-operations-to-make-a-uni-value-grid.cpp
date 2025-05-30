class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size(), idx = 0, count = 0;
        vector<int> temp(m * n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp[idx++] = grid[i][j];
            }
        }

        sort(temp.begin(), temp.end());

        int mid = (m * n) / 2, val = temp[mid];

        for(int i = 0; i < m * n; i++){
            int t = abs(temp[i] - val);
            if(t % x != 0){
                return -1;
            }

            count += t / x;
        }

        return count;
    }
};
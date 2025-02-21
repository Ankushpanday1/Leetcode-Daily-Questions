class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // support variables
        int mr = mat.size(), mc = mat[0].size(), nx = 0, ny = 0;
        // detecting illegal calls and when the new matrix has the same size
        if (mr * mc != r * c || mr == r && mc == c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        // populating ress
        for (int cy = 0; cy < mr; cy++) {
            for (int cx = 0; cx < mc; cx++) {
                res[ny][nx++] = mat[cy][cx];
                // updating nx and ny when we reached the end of a row
                if (nx == c) nx = 0, ny++;
            }
        }
        return res;
    }
};
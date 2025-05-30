class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), common = 0;
        vector<int> result(n), count(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            if (++count[A[i]] == 2) ++common;
            if (++count[B[i]] == 2) ++common;
            result[i] = common;
        }
        
        return result;
    }
};
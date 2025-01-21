class Solution {
public:
    long long gridGame(vector<vector<int>>& mat) {

        long long n = mat[0].size(),ans = LONG_MAX;
        long long row0 = 0,row1 = 0;

        for(int i = 0;i<n;i++)
        { 
            row0+=mat[0][i];
            row1+=mat[1][i]; 
        }
        row0+=mat[1][n-1];
        row1-=mat[1][n-1];

        long long score = 0,sum0 = 0,sum1 = 0;
        
        for(int i = 0;i<n;i++)
        {
            long long c1 = sum1;
            long long c2 = row0-sum0-mat[1][n-1]-mat[0][i];
            long long score = max(c1,c2);
            ans = min(ans,score);
            sum0+=mat[0][i];
            sum1+=mat[1][i];
        }
        return ans;   
    }
};
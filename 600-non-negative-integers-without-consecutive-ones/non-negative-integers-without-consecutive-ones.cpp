class Solution {
public:
    int dp[2][2][33] ;

    int f(int i, int prev, int constraint, string &s)
    {
        int n = s.size();
        if(i >= n)
            return 1 ;

        if(dp[prev][constraint][i] != -1)
            return dp[prev][constraint][i] ;

        int answer = 0 ;
        int ub = constraint ? s[i] - '0' : 1 ;

        for(int x = 0; x <= ub; x++)
        {
            if(prev == 1)
            {
                if(x == 0)
                    answer += f(i+1, x, (constraint && (x == ub)), s);
            }
            else
            {
                answer += f(i+1, x, (constraint && (x == ub)), s);
            }
        }
        return dp[prev][constraint][i] = answer ;
    }


    int findIntegers(int n) {
        bitset<32> b(n);
        string st = b.to_string();
        int sz = log2(n)+1;
        string s;

        for(int i = 32 - sz; i < 32; i++)
        {
            s.push_back(st[i]);
        }
        
        memset(dp, -1, sizeof dp);
        int ans = f(0, 0, 1, s) ;
        return ans ;
    }
};
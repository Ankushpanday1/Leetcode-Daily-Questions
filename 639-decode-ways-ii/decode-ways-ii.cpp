//Solution by Ankush Panday




#define ll long long
#define vl vector<ll>

class Solution {
public:

    ll mod = 1e9 + 7;

    ll solveMem(string &s, int i, vl &dp) {
        int n = s.length();
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        ll cnt = solveMem(s, i+1, dp);
        if(s[i] == '*')
            cnt = (cnt * 9) % mod;

        // here the logic is how many ways are there 
        // we can take i and i+1 index at a time

        if(i+1<n)   {
            // ( 1* ) => we can place any value after 1 so multiple with 9
            if(s[i] == '1' && s[i+1] == '*')    {
                cnt = (cnt + 9*solveMem(s, i+2, dp)%mod)%mod;
            }
            // here ( 1_ )  we can take 2 digit at a time
            else if(s[i] == '1' && s[i+1] != '*')    {
                cnt = (cnt + solveMem(s, i+2, dp)%mod)%mod;
            }
            // ( 2* ) => we can place 1...6 total 6 value
            else if(s[i] == '2' && s[i+1] == '*')    {
                cnt = (cnt + 6*solveMem(s, i+2, dp)%mod)%mod;
            }
            // ( 2_ ) => we can place 1...6 
            // so if s[i+1] <= 6 we can take 2 digit at a time
            else if(s[i] == '2' && s[i+1] != '*')    {
                if(s[i+1] <= '6')
                    cnt = (cnt + solveMem(s, i+2, dp)%mod)%mod;
            }
            // if both s[i] and s[i+1] is *
            // we can place 1* or 2* here
            // for 1* multiply with 9
            // for 2* multiple with 6
            else if(s[i] == '*' && s[i+1] == '*')    {
                cnt = (cnt + 9*solveMem(s, i+2, dp)%mod)%mod;
                cnt = (cnt + 6*solveMem(s, i+2, dp)%mod)%mod;
            }
            // here s[i+1] != * so we can place 1 or 2 
            // for 1 : s[i+1] is anything
            // for 2 : s[i+1] <= '6'
            else if(s[i] == '*' && s[i+1] != '*')    {
                cnt = (cnt + solveMem(s, i+2, dp)%mod)%mod;
                if(s[i+1] <= '6')
                    cnt = (cnt + solveMem(s, i+2, dp)%mod)%mod;
            }
        }

        return dp[i] = cnt % mod;
    }

    int numDecodings(string s) {
        // return solve(s, 0);
        vl dp(s.length()+1, -1);
        return solveMem(s, 0, dp);
    }
};
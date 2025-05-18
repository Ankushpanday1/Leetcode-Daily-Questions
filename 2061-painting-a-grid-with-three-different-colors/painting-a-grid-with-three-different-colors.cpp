typedef long long  ll;
class Solution {
    ll mod = 1e9+7;
    void generate_mask(int m,int msk,vector<int> &masks,int &pre_msk,int pre_col)
    {
        if(m==0)
        {
            masks.push_back(msk);
            return;
        }
        for(int i=1;i<=3;i++)
            if(pre_col!=i && ((pre_msk>>((m-1)*2))&3)!=i)
                generate_mask(m-1,msk|(i<<(m-1)*2),masks,pre_msk,i);
    }
    int func(int &m,int&n,int idx,int msk,vector<vector<int>> &dp,unordered_map<int,vector<int>> &msk_map)
    {
        if(idx==n)
            return 1;
        if(dp[idx][msk]!=-1)
            return dp[idx][msk];
        if(msk_map.find(msk)==msk_map.end())
             generate_mask(m,0,msk_map[msk],msk,0);
        ll ans = 0;
        for(auto cur_msk : msk_map[msk])
        {
            ans += func(m,n,idx+1,cur_msk,dp,msk_map)*1LL;
            ans %= mod;
        }
        return dp[idx][msk] = ans;
    }
public:
    int colorTheGrid(int m, int n) 
    {
        // red = 01  |  green = 10  | blue = 11
        vector<vector<int>> dp(n,vector<int>(1<<(2*m),-1));
        unordered_map<int,vector<int>> msk_map;
        return (int)func(m,n,0,0,dp,msk_map);
    }
};
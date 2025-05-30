class Solution {
public:
    long long mod = 1e9+7;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) 
    {
        map<int,map<int,vector<long long>>> mp;
        for(int i=0; i<26; i++)
        {
            vector<long long> v(26,0);
            for(int j=1; j<=nums[i]; j++)
                v[(i+j)%26]++;
            mp[1][i] = v;
        }
        for(int m=2; m<=t; m*=2)
        {
            for(int i=0; i<26; i++)
            {
                vector<long long> v(26,0), pre = mp[m/2][i];
                for(int j=0; j<26; j++)
                {
                    auto prex = mp[m/2][j];
                    for(int k=0; k<26; k++)
                    {
                        v[k] += (pre[j]%mod*prex[k]%mod);
                        v[k] %= mod;
                    }
                }
                mp[m][i] = v;
            }
        }
        vector<long long> c(26,0);
        for(char ch:s)
            c[ch-'a']++;
        int maxi = (1<<30);
        while(t)
        {
            if(t >= maxi)
            {
                vector<long long> v(26,0);
                for(int i=0; i<26; i++)
                {
                    vector<long long> pre = mp[maxi][i];
                    for(int j=0; j<26; j++)
                    {
                        v[j] += (c[i]%mod*pre[j]%mod);
                        v[j] %= mod;
                    }
                }
                c = v;
                t -= maxi;
            }
            maxi /= 2;
        }
        long long res = 0;
        for(int i=0; i<26; i++)
        {
            res += c[i];
            res %= mod;
        }
        return res;
    }
};
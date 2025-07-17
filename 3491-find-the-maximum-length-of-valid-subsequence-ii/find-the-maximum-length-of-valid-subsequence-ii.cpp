class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<vector<int>> dp(k , vector<int>(k , 0)) ;
        int ans = 0 ;
        for(int j = 0 ; j < n ; j++){
            int t  = nums[j]%k ; 
            for(int i = 0 ; i < k ; i++){
                if(i == t){
                    dp[i][i] ++ ;
                    ans = max(ans , dp[i][i]) ; 
                }else{
                    if(dp[i][t]%2 == 0) dp[i][t]++ , ans = max(ans , dp[i][t]);
                    if(dp[t][i]%2 != 0) dp[t][i]++ , ans = max(ans , dp[t][i]);
                }
            }
        }
        return ans ;        
    }
};
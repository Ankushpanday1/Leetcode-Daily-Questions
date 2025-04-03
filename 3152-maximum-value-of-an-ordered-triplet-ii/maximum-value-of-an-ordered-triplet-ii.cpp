class Solution {
public:
const int mod=1e9+7;
    long long maximumTripletValue(vector<int>& nums) {
        int i,n=nums.size();
        vector<long long> prefix(n,0),suffix(n,0);

        prefix[0]=nums[0],suffix[n-1]=nums[n-1];

        for(i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],1LL*nums[i]);
        }

        for(i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],1LL*nums[i]);
        }
long long ans=0;
        for(i=1;i<n-1;i++){
            long long curr=(prefix[i-1]-nums[i])*suffix[i+1];
            // curr%=mod;
            ans=max(ans,curr);
        }

        return ans<0?0:ans;
    }
};
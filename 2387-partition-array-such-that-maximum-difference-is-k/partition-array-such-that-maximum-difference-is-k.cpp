class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        
        int ans=0;
        int i=0,temp=nums[0]+k;
        while(i<nums.size()){
            auto it=upper_bound(nums.begin(),nums.end(),temp);
            i=it-nums.begin();
            ans++;
            if(it==nums.end())return ans;
            temp=nums[i]+k;
            
        }
        
        return ans;
    }
};
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i = 0;
        int ml = 1;
        int j = 1;
        for(j;j<nums.size();j++){
            if(nums[j]<=nums[j-1]){
                ml = max(ml,j-i);
                i= j;
            }
        }
        if(nums[j-1]>nums[i])
            ml = max(ml,j-i);
        return ml;
    }
};
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin()+1, nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        return ans;
    }
};
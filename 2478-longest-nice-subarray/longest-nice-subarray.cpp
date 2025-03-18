//Written by Mr Ankush Jiiii

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0;
        int ans = 1;
        int i = 0, j = 0;
        while(j < nums.size()){
            while(mask & nums[j]) mask = (mask ^ nums[i++]);
            ans = max(ans, j - i + 1);
            mask |= nums[j];
            j++;
        }
        return ans;
    }
};
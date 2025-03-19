class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] = nums[i + 1] ? 0 : 1;
                nums[i + 2] = nums[i + 2] ? 0 : 1;
                ++res;
            }
        }

        return nums[n - 1] && nums[n - 2] ? res : -1;
    }
};
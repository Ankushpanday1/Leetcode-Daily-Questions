class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (k == 0)
            return set<int>(nums.begin(), nums.end()).size();

        sort(nums.begin(), nums.end());

        int distinctNums = 0;
        int target_num = nums[0] - k;
        for (int i = 0; i < nums.size(); i++) {
            // If it falls within the range, set nums[i] to it and increment it by 1
            if ((nums[i] - k) <= target_num && target_num <= (nums[i] + k)) {
                nums[i] = target_num;
                target_num++;
                distinctNums++;
            } 
            // If it falls below the range, first update it to the lowest number in the range 
            else if (target_num <= nums[i] - k) {
                target_num = nums[i] - k;
                nums[i] = target_num;
                target_num++;
                distinctNums++;
            }
        }

        return distinctNums;
    }
};
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxDiff = -1;
        for (int num : nums) {
            if (num <= minNum) {
                minNum = num;
            } else {
                maxDiff = max(maxDiff, num - minNum);
            }
        }
        return maxDiff;
    }
};
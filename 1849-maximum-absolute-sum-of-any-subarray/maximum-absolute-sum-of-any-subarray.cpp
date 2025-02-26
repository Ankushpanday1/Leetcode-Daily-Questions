class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum1 = 0, prefixSum2 = 0, maxSum = 0, minSum = 0;

        for(int num : nums){
            prefixSum1 += num;
            prefixSum2 += num;

            maxSum = max(maxSum, prefixSum1);
            minSum = min(minSum, prefixSum2);

            if(prefixSum1 < 0){
                prefixSum1 = 0;
            }

            if(prefixSum2 > 0){
                prefixSum2 = 0;
            }
        }

        return max(maxSum, abs(minSum));
    }
};
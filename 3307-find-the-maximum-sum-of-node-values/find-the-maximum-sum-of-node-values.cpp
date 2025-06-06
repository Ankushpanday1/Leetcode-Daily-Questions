#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long bestSum = 0;
        int cnt = 0;

        // Compute the best possible sum and count the number of nodes where XORing increases the value
        for (int num : nums) {
            bestSum += max(num, num ^ k);
            if ((num ^ k) > num) {
                cnt++;
            }
        }

        // If cnt is odd, we need to adjust the sum
        if (cnt % 2 != 0) {
            int minDifference = INT_MAX;
            for (int num : nums) {
                minDifference = min(minDifference, abs(num - (num ^ k)));
            }
            bestSum -= minDifference;
        }

        return bestSum;
    }
};
class Solution {
public:
    int findLHS(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: Initialize pointers and variables
        int l = 0, r = 1, MaxLen = 0;
        
        // Step 3: Traverse the array using the two-pointer approach
        while (l < nums.size()) {
            while (r < nums.size() && abs(nums[r] - nums[l]) <= 1) {
                if (abs(nums[r] - nums[l]) == 1) {
                    MaxLen = max(MaxLen, r - l + 1); // Update the maximum length
                }
                r++; // Expand the window
            }
            l++; // Move the left pointer to explore new windows
        }
        
        // Step 4: Return the result
        return MaxLen;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int jb = -1, jmin = -1, jmax = -1;
        long result = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK) jb = i;
            if(nums[i] == minK) jmin = i;
            if(nums[i] == maxK) jmax = i;
            result += max(0, min(jmin, jmax)-jb);
        }
        return result;
    }
};
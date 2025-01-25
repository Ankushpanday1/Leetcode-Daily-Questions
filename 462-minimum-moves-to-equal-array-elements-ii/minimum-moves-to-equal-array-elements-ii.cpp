class Solution {
public:
    int minMoves2(vector<int>& nums) {
      int n=nums.size();
       // sort the array 
      sort(nums.begin(),nums.end());
       // take the middle element of the array, and try to make all elements equal to middle element
        int mid=nums[n/2];
        int ans=0;
        for(int i=0;i<n;i++)
        {
           // take absolute difference of all numbers from mid element 
            ans+=abs(nums[i]-mid);
        }
        return ans;
    }
};
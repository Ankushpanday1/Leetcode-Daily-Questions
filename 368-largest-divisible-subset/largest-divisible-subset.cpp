class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans;
 
    vector<int> sizeEndsAt(n, 1);
 
    vector<int> prevIndex(n, -1);
    int maxSize = 0;  
    int index = -1;   

    ranges::sort(nums);

  
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j)
        if (nums[i] % nums[j] == 0 && sizeEndsAt[i] < sizeEndsAt[j] + 1) {
          sizeEndsAt[i] = sizeEndsAt[j] + 1;
          prevIndex[i] = j;
        }
   
      if (maxSize < sizeEndsAt[i]) {
        maxSize = sizeEndsAt[i];
        index = i;  
      }
    }

    while (index != -1) {
      ans.push_back(nums[index]);
      index = prevIndex[index];
    }

    return ans;
  }
};
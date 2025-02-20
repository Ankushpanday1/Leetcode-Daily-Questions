class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m; int temp = 0, count = 0; 
        m[0] = 1; 
        for(int i=0; i<nums.size(); i++){
            temp += nums[i]; 
            if(m.find(temp-k) != m.end()) count += m[temp-k]; 
            m[temp]++; 
        }
        return count; 

    }
};
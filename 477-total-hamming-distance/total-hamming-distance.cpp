class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int j=0;j<32;j++){
            int one = 0, z = 0;
            for(int i=0;i<n;i++){
                int bit = (nums[i] >> j) & 1;
                if(bit == 1)one++;
                
                else z++;
            }
            ans += one * z;
        }   

        return ans;
    }
};
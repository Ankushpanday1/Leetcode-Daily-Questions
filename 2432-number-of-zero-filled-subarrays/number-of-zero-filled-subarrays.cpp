class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ct = 0;
        long long int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                ct++;
                if(i == nums.size()-1){
                    ans += ct*(ct+1)/2;
                }
            } 
            else{
                ans += ct*(ct+1)/2;
                ct = 0;
            }
        }
        return ans;
    }
};
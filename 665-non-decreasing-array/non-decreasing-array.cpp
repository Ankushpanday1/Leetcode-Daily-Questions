class Solution {
public:
bool checkPossibility(vector<int>& nums) {
    vector<int> v(nums);
    for(int i=0; i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            if(i-1<0 || nums[i-1]<=nums[i+1]) v[i]=v[i+1];
            else v[i+1]=v[i];
            break;
        }
    }
    for(int i=0; i<nums.size()-1;i++){
        if(v[i]>v[i+1]){
            return false;
        }
    }
    return true;
}
};
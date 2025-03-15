//Solution by Panday jiii

class Solution {
public:
    bool checkCapability(int x, vector<int>& nums, int k){
        int count=0,prevInd=-2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=x && (i-prevInd)>1){
                count++;
                prevInd=i;
            }
            if(count==k)
                break;
        }
        if(count==k)
            return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int ll=1,ul=1e9,mid,ans;
        while(ll<=ul){
            mid=ll+(ul-ll)/2;
            if(checkCapability(mid,nums,k)){
                ans=mid;
                ul=mid-1;
            }
            else
                ll=mid+1;
        }
        return ans;
    }
};
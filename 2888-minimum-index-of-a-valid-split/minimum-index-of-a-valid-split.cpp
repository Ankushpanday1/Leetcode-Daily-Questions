class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mp1; // left subArray
        unordered_map<int,int>mp2; // right subArray

        for(auto &i:nums) mp2[i]++;

        for(int i=0;i<n;i++){
            int num=nums[i];

            mp1[num]++;
            mp2[num]--;

            int n1=i+1,n2=n-i-1;

            if(mp1[num]>n1/2 && mp2[num]>n2/2) return i;
        }
        return -1;
    }
};
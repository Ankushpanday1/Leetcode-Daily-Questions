class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> use(n,0);
        int m=queries.size();
        for(int i=0;i<m;i++){
            use[queries[i][0]]+=(-1);
            if((queries[i][1]+1)<n){
                use[queries[i][1]+1]+=1;
            }
        }
        int sub=0;
        for(int i=0;i<n;i++){
            sub+=use[i];
            if((nums[i]+sub)>0){
                return false;
            }
        }
        return true;
    }
};
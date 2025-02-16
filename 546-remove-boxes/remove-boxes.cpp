int dp[101][101][101];
class Solution {
public:
    int rec(int l,int r,int cnt,vector<int>& boxes){
        if(l>r)     return 0;
        if(dp[l][r][cnt]!=-1)
            return dp[l][r][cnt];
        int ans=(cnt+1)*(cnt+1) +rec(l+1,r,0,boxes);
        for(int m=l+1;m<=r;m++){
            if(boxes[m]==boxes[l]){
                ans=max(ans,rec(l+1,m-1,0,boxes)+rec(m,r,cnt+1,boxes));
            }
        }
        return dp[l][r][cnt]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        return rec(0,boxes.size()-1,0,boxes);
    }
};
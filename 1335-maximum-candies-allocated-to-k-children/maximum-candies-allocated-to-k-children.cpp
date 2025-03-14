class Solution {
public:
    bool isPossible(vector<int>& candies, long long mid, long long k){
        long long count=0;
        for(int i=0; i<candies.size(); i++){
            int x=candies[i];
            count+=(x/mid);
        }
        if(count>=k){
            return true;
        }
        else{ 
            return false;
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int s=1;
        long long e, sum=0;
        long long ans=0;

        for(int i=0; i<candies.size();i++){
            sum+=candies[i];
        }
        e=sum;
        if(sum==k){
            return 1;
        }
        else if(sum<k){
            return 0;
        }
        else{
        long long mid=s+(e-s)/2;

        while(s<=e){
            if(isPossible(candies,mid,k)){
                ans = max(ans,mid);
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
        }
    }
};
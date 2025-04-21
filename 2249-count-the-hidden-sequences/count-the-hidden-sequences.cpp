class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        int init=lower;
        int last=lower;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            
            if((last+differences[i])>upper)
            return 0;
             if((last+differences[i])<lower)
            {
                int x=lower-(last+differences[i]);
                init+=x;
                last=last+x;
               if(last>upper)return 0;
            }
            last=last+differences[i];
        }
        for(int i=0;i<n;i++)
        {
            ans=min(ans,(upper-init+1)); 
            init+=differences[i];
        }
        ans=min(ans,(upper-init+1)); 
        return ans;

    }
};
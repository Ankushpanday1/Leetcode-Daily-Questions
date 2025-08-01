class Solution {
public:

vector<long long> f(vector<int>& nums)
{
    int sz=nums.size();
        int n=sz/3;
        long long sum=0;
        multiset<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
            sum+=nums[i];
        }
        vector<long long> psum;
        psum.push_back(sum);
        for(int i=n;i<(sz-n);i++)
        {
            auto it=st.end();
            it--;
            int val=*it;
            if(nums[i]<val)
            {
                sum-=val;
                sum+=nums[i];
                st.erase(it);
                st.insert(nums[i]);
            }
            psum.push_back(sum);
        }

     return psum;

}

vector<long long> f1(vector<int>& nums)
{
    int sz=nums.size();
        int n=sz/3;
        long long sum=0;
        multiset<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
            sum+=nums[i];
        }
        vector<long long> psum;
        psum.push_back(sum);
        for(int i=n;i<(sz-n);i++)
        {
            auto it=st.begin();
            int val=*it;
            if(nums[i]>val)
            {
                sum-=val;
                sum+=nums[i];
                st.erase(it);
                st.insert(nums[i]);
            }
            psum.push_back(sum);
        }

     return psum;

}
    long long minimumDifference(vector<int>& nums) {

        vector<long long > psum=f(nums);
        reverse (nums.begin(),nums.end());
        vector<long long> ssum =f1(nums);
        reverse (ssum.begin(),ssum.end());
        long long ans=LLONG_MAX;
        for(int i=0;i<psum.size();i++)
        {
            ans=min(ans,psum[i]-ssum[i]);
        }
        return ans;

        
        
    }
};
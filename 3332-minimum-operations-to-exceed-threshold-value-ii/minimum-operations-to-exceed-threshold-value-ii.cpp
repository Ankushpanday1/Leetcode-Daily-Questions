class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> minh;
        long long lessthank = 0;
        for(auto it:nums){
            if(it<k) lessthank++;
            minh.push(it);
        }
        int ans = 0;
        while(minh.size()>1 && lessthank>0){
            long long x = minh.top();
            minh.pop();
            if(x<k) lessthank--;
            long long y = minh.top();
            minh.pop();
            if(y<k) lessthank--;
            long long z = min(x, y) * 2 + max(x, y);
            minh.push(z);
            if(z<k) lessthank++;
            ans++;
        }
        return ans;
    }
};
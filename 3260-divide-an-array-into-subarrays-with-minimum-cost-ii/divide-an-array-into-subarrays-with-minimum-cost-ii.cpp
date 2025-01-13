#define ll long long int
class Solution {
private:
multiset<int> l, r;
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll n = nums.size();
        // Make the first Window for which the elementsthere exists the nums[0] (ofcourse) and the lowest k-1 elemnts of the window of the size dist+1
        k--;
        ll curr = nums[0];
        for(int i=1; i<=dist+1; i++){
            curr += nums[i];
            l.insert(nums[i]);
        }
        // Now my curr can only have k elements, this means apart from the first element(k-- hs been done for it), there must be only k elements in my set l
        while(l.size() > k){
            curr -= *l.rbegin();
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }

        ll ans = curr;
        // Now I have ans for the first window stored in ans
        // Now my aim is to find for other windows,
        // right now my l multiset contians the k elements for the first window and the r is having the possible elements
        // which can come on need

        // Now check for other windows
        for(int i=dist+2; i<n; i++){
            // if you find the last element in l, this means in new window it should not be there thus delete it
            if(l.find(nums[i-dist-1]) != l.end()){
                curr -= nums[i-dist-1];
                l.erase(l.find(nums[i-dist-1]));
            }
            // else means it is in r, not in curr so no deletion but erase it from r as it is no longer a buffer
            else{
                r.erase(r.find(nums[i-dist-1]));
            }

            // Now update for the new index nums[i] which has come
            if(nums[i] < *l.rbegin()){
                // this means it has to be a part of l and curr
                curr += nums[i];
                l.insert(nums[i]);
            }
                // this means the newly added number is not good enough to be added in that new window so put it in buffer
            else{
                r.insert(nums[i]);
            }

            // Balance the l if it does not k elements any more
            while(l.size() < k){
                // if there are less elements then simply take the extra minimum element from r and put it in l while updating the curr 
                l.insert(*r.begin());
                curr += *r.begin();
                r.erase(r.find(*r.begin()));
            }
            while(l.size() > k){
                // if there are more element in l then simplt take the maximum element from l which are extra and pur it in r while updating the curr
                r.insert(*l.rbegin());
                curr -= *l.rbegin();
                l.erase(l.find(*l.rbegin()));
            }

            ans = min(ans, curr); 
        }
        return ans;
    }
};
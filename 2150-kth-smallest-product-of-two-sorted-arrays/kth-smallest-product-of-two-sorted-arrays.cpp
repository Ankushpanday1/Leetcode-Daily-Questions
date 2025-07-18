class Solution {
public:
    bool isPossible(vector<int>& nums1, vector<int>& nums2, long long k,
                    long long x) {
            
            int n1 = nums1.size();
            int n2 = nums2.size();
            long long count = 0;

            for(int i = 0; i<n1; i++){
                if(nums1[i] < 0){
                    long long rem = ceil((double)x/nums1[i]);
                    int ind = lower_bound(nums2.begin(), nums2.end() , rem) -nums2.begin();
                    count += (n2-ind);
                }
                else if( nums1[i] > 0) {
                    long long rem = floor((double)x/nums1[i]);
                    int ind = upper_bound(nums2.begin(), nums2.end(), rem) - nums2.begin();
                    count += ind;
                }
                else {
                    if(x>=0) count += n2;
                }
                if(count >= k) return true;
            }
            return count >=k;

    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long s = -1e10;
        long long n = nums1.size();
        long long m = nums2.size();
        long long e = 1e10;

        long long ans = 0;

        while (s <= e) {
            long long mid = s + (e - s) / 2;

            if (isPossible(nums1, nums2, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }

        return ans;
    }
};
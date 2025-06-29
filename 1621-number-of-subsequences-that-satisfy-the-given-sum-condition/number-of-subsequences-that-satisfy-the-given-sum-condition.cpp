class Solution {
public:

    int numSubseq(vector<int>& nums, int target) {
        int mod = (int)(1e9 + 7);
        sort(nums.begin(), nums.end());
        int answer = 0;
        int n = nums.size();
        int power_2[n + 1];
        power_2[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            power_2[i] = (power_2[i - 1] * 2) % mod;
        }
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            int need = target - num;
            auto itr = upper_bound(nums.begin(), nums.end(), need);
            auto j = itr - nums.begin();
            j--;
            // cout<<i<<" "<<j<<endl;
            int diff = j - i;
            if(diff < 0)continue;
            answer = (answer + power_2[diff]) % mod;
        }
        return answer;
    }
};
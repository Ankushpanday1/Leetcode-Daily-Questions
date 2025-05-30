class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> count;
        count[0] = 1;
        long long res = 0;
        int pref = 0;

        for (int num : nums) {
            if (num % modulo == k)
                pref++;

            int rem = pref % modulo;   
            int need = (pref - k + modulo) % modulo;
            res += count[need];
            count[rem]++;
        }

        return res;
    }
};
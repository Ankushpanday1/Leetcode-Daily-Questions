class Solution {
public: 
    typedef long long ll;
    const int MOD = 1e9 + 7;
    
    // Precompute smallest prime factors for numbers up to n using a modified Sieve
    vector<int> smallestPrimeFactor(int n) {
        vector<int> SPF(n+1, 0);
        for(int i = 2; i <= n; i++) {
            if(SPF[i] > 0) continue;  // already marked
            
            SPF[i] = i;  // i is prime, so SPF[i] is i
            
            if(1LL * i * i > n) continue;  // no need to mark multiples if i*i > n
            
            for(int j = i * i; j <= n; j += i) {
                if(SPF[j] == 0) {
                    SPF[j] = i;  // mark the smallest prime factor for j
                }
            }
        }
        return SPF;
    }

    // Compute the "prime score": count of distinct prime factors of x
    int findPrimeScore(int x, vector<int>& SPF) {
        if(x == 1) return 0;
        int score = 0;
        while(x > 1) {
            int spf = SPF[x];
            score++;  // count this distinct prime factor
            while(x % spf == 0) { // remove all occurrences of this prime factor
                x /= spf;
            }
        }
        return score;
    }

    // Fast modular exponentiation: computes (a^b) mod MOD
    ll modExpo(ll a, ll b) {
        ll res = 1;
        while(b > 0) {
            if(b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    // Compute next greater element indices based on primeScore
    // For each index, finds the next index where primeScore is greater
    vector<int> nextGreaterElement(vector<int>& primeScore) {
        int n = primeScore.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && primeScore[st.top()] <= primeScore[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    // Compute previous greater or equal element indices based on primeScore
    // For each index, finds the previous index where primeScore is greater or equal
    vector<int> prevGreaterOrEqualElement(vector<int>& primeScore) {
        int n = primeScore.size();
        vector<int> pgee(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && primeScore[st.top()] < primeScore[i]) {
                st.pop();
            }
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        // Precompute SPF for factorization
        vector<int> SPF = smallestPrimeFactor(100001);

        // Compute prime scores for each number in nums
        vector<int> primeScore(n);
        for(int i = 0; i < n; i++) {
            primeScore[i] = findPrimeScore(nums[i], SPF);
        }

        // Compute next and previous dominant indices using monotonic stacks
        vector<int> nge = nextGreaterElement(primeScore);
        vector<int> pgee = prevGreaterOrEqualElement(primeScore);

        // Calculate contribution of each element: number of subarrays where it is dominant
        vector<pair<int, ll>> ele_contribution;
        for(int i = 0; i < n; i++) {
            ll contribution = 1LL * (nge[i] - i) * (i - pgee[i]); // valid subarrays count
            ele_contribution.push_back({nums[i], contribution});
        }

        // Sort elements by value in descending order
        sort(ele_contribution.begin(), ele_contribution.end(), greater<pair<int, ll>>());

        ll score = 1;
        ll used = 0;
        // Greedily use contributions from the highest value elements to maximize the score
        for(auto &p : ele_contribution) {
            if(used >= k) break;
            int x = p.first;
            ll contribuition = p.second;
            ll take = min(k - used, contribuition);
            used += take;
            score = (score * modExpo(x, take)) % MOD;
        }
        return score;
    }
};
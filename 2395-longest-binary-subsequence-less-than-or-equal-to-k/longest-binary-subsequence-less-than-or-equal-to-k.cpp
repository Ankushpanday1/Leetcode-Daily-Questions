class Solution {
public:
    int f(int len, string& s, int& k) {
        long long curr = 0;
        int taken = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(taken == len) break;

            if(s[i] == '0') {
                taken++;
            }else {
                if(taken >= 35) continue; 
                if(curr + (1LL << taken) <= k) {
                    curr += (1LL << taken);
                    taken++;
                }
            }
        }
        return taken >= len;
    }
    
    int longestSubsequence(string s, int k) {
        int l=0, r=s.size()+1;
        while(r-l>1) {
            int m = l+(r-l)/2;
            if(f(m, s, k)) l=m;
            else r=m;
        }
        return l;
    }
};
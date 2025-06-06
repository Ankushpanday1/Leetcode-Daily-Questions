class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> min_suf(n);
        min_suf[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i)
            min_suf[i] = s[i] < min_suf[i + 1] ? s[i] : min_suf[i + 1];
        string t;
        t.reserve(n);
        string p;
        p.reserve(n);
        int i = 0;
        while (i < n) {
            while (!t.empty() && t.back() <= min_suf[i]) {
                p.push_back(t.back());
                t.pop_back();
            }
            t.push_back(s[i]);
            ++i;
        }
        while (!t.empty()) {
            p.push_back(t.back());
            t.pop_back();
        }
        return p;
    }
};
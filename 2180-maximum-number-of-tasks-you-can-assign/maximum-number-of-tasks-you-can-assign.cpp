class Solution {
public:
    int maxTaskAssign(vector<int>& t, vector<int>& w, int pills, int strength) {
        int n = t.size();
        int m = w.size();
        sort(t.begin(), t.end());
        sort(w.begin(), w.end());
        auto valid = [&](int val) {
            int npill = pills;
            deque<int> d;
            int sti = 0;
            for (int i = m- val; i < m; i++) {
                while (sti < val && t[sti] <= w[i] + strength) {
                    d.push_back(t[sti]);
                    sti++;
                }
                if (!d.size()) return false;
                if (d.front() <= w[i]) {
                    d.pop_front();
                } else if (npill > 0) {
                    npill--;
                    d.pop_back();
                } else {
                    return false;
                }
            }
            return true;
        };
        int l = 0, r = min(m, n);
        int ans = 0;
        while (l<=r) {
            int mid = (l+r)/2;
            if (valid(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
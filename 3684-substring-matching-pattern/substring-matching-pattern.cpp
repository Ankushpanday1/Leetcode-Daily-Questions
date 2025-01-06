class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int breakpt = -1;
        for (int i = 0; i < m; i++) {
            if (p[i] == '*'){
                breakpt = i;
                break;
            }
        }

        string pre = p.substr(0, breakpt);
        string suff = p.substr(breakpt + 1);
        int i = s.find(pre);
        int j = s.rfind(suff);
        return i != -1 && j != -1 && i + pre.size() <= j;
    }
};
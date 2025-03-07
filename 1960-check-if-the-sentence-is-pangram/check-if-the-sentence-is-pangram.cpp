class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool>a(26, false);
        int cnt = 0;
        for(char ch : s)
        {
            if(!a[ch - 'a'])
            {
                a[ch - 'a'] = true;
                cnt++;
            }
        }
        return cnt == 26;
    }
};
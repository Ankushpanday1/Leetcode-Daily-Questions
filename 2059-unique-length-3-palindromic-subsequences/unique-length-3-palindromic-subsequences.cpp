class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> mp;
        int ans = 0;

        for(int i = 0; i < s.length(); i++) {
            mp[s[i]].push_back(i);
        }

        for(auto &pair: mp) {
            int size = pair.second.size();
            if(size > 1) {
                int l = pair.second[0], r = pair.second[size -1];
                if(r - l > 1) {
                    vector<bool> vis(26, false);
                    for(int j = l + 1; j < r; j++) {
                        if(vis[s[j] - 'a']) continue;
                        ans++;
                        vis[s[j] - 'a'] = true;
                    }
                }
            }
        }

        return ans++;
    }
};
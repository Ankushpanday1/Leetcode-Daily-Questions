class Solution {
public:
    string solve(string word, int n, int i, int nf) {
        string ans = "";
        if (i >= nf - 1) {
            while (i < n)
                ans += word[i++];
        } else {
            int len = n - (nf - 1);
            while (i < n && len--)
                ans += word[i++];
        }
        return ans;
    }

    string answerString(string word, int numFriends) {

        int n = word.size();

        if(numFriends == 1)
            return word;
        
        char maxc = 'a';

        for (auto x : word)
            maxc = max(x, maxc);


        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (word[i] == maxc)
                tmp.push_back(i);
        }

        string maxs = "";
        for (int i = 0; i < tmp.size(); i++) {
            string curr = solve(word, n, tmp[i], numFriends);
            // cout << curr << endl;
            maxs = max(maxs, curr);
        }

        return maxs;
    }
};
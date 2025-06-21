class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size(), mini = INT_MAX;
        unordered_map<char, int> mp;
        for(auto it : word)
            mp[it]++;
        vector<int> vec;
        for(auto it : mp)
            vec.push_back(it.second);
        sort(vec.begin(), vec.end());
        int m = vec.size(), prefix = 0;
        for(int i = 0 ; i < m ; i++){
            int j = m - 1, tmp = 0;
            while(vec[j] - vec[i] > k)
                tmp += (vec[j--] - vec[i] - k);
            mini = min(mini, prefix + tmp);
            if(!tmp)
                break;
            prefix += vec[i];
        }
        return mini;
    }
};
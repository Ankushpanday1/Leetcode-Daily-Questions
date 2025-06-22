class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>v;
        int x=s.size()%k;
        if(x!=0) for(int i=0;i<k-x;i++)s+=fill;
        for(int i=0;i<s.size();i+=k) v.push_back(s.substr(i,k));
        return v;
    }
};
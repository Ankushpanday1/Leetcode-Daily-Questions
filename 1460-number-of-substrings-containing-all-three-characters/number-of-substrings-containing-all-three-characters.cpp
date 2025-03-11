class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;int j=0;
        map<char,int>m;
        int ans=0;
        while(i<s.length()&&j<s.length()){
           m[s[j]]++;
           label:
            if(m['a']>=1&&m['b']>=1&&m['c']>=1)
            {
                ans+=(s.length()-j);
                m[s[i]]--;
                i++;
                goto label;
            }
            j++;
        }
        return ans;

    }
};
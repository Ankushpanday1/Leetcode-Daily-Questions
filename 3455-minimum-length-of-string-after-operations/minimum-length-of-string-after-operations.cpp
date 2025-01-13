class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int del=0;
        for(auto it:mp){
            if(it.second%2==0){
                del+=it.second-2;
            }
            else{
                del+=it.second-1;
            }
        }
        return s.length()-del;
    }
};
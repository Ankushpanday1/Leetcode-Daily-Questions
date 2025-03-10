class Solution {
public:
    long long countOfSubstrings(string w, int k) {
        long long ans=0;
        int n=w.length();
        int vow[n];
        int c=0;
        unordered_map<char,int>m;
        for(int i=n-1;i>=0;i--){
            vow[i]=c;
            if(w[i]=='a' || w[i]=='e' || w[i]=='i' || w[i]=='o' || w[i]=='u'){
                c++;
            }
            else{
                c=0;
            }
        }
        int in=0;
        int r=0;
        for(int j=0;j<n;j++){
                if(w[j]=='a'){
                    m['a']++;
                }
                else if(w[j]=='e'){
                    m['e']++;
                }
                else if(w[j]=='i'){
                    m['i']++;
                }
                else if(w[j]=='o'){
                    m['o']++;
                }
                else if(w[j]=='u'){
                    m['u']++;
                }
                else{
                    r++;
                }
                
                while(r>k){
                    int pq=int(w[in]);
                    if(pq==97 || pq==101 || pq==105 || pq==111 || pq==117){
                        m[w[in]]--;
                    }
                    else{
                        r--;
                    }
                    in++;
                }
                while(r==k && m['a']>0 && m['e']>0 && m['i']>0 && m['o']>0 && m['u']>0){
                    
                    ans=ans+1+vow[j];
                    int pq=int(w[in]);
                    if(pq==97 || pq==101 || pq==105 || pq==111 || pq==117){
                        m[w[in]]--;
                    }
                    else{
                        r--;
                    }
                    in++;
                    
                }
                if(in>=n){
                    break;
                }
        }
        return ans;
    }
};
class Solution {
public:
    bool rbsearch(string pat,string txt){
        //vector<int>v;
        int m = pat.length();
        int n = txt.length();
        int h=1;
        int q = 1e8;
        int d = 7;
        for(int i=0;i<m-1;i++) h=(h*d)%q;
        int p = 0;
        int t=0;
        for(int i=0;i<m;i++){
            p = (p*d + pat[i])%q;
            t = (t*d + txt[i])%q;
        }

        for(int i=0;i<=n-m;i++){
            if(p==t){
                bool flag = true;
                for(int j=0;j<m;j++){
                    if(pat[j]!=txt[i+j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
            if(i<n-m){
                t = ((d*1ll*(t- h*1ll*txt[i]))+txt[i+m])%q;
                if(t<0) t+=q; 
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int ans = 1;
        string dup = a;
        while(a.size()<b.size()){
            a+=dup;
            ans++;
        }
        if(a==b) return ans;
        if(rbsearch(b,a)) return ans;
        if(rbsearch(b,a+dup)) return ans+1;
        return -1;
    }
};
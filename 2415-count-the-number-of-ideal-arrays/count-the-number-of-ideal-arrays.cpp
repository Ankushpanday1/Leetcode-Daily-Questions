class Solution {
private:
    const long long MAX=1000000007;
    vector<long long> pr;//prime
    vector<vector<long long> > cc;// C(n+i-1,i)
public:
    int idealArrays(int n, int maxValue) {
        int i,j;
        long long result=0;
        cc.push_back({1});
        for (i=1;i<=maxValue;i++) {
            vector<int> dv;
            long long ti=i;
            for (j=0;j<pr.size()&&pr[j]<=ti&&pr[j]*pr[j]<=i;j++) {
                if (ti%pr[j]==0) {
                    int di=dv.size();
                    dv.push_back(0);
                    while (ti%pr[j]==0&&ti>1) {
                        dv[di]++;
                        ti/=pr[j];
                    }
                }
            }
            if (dv.size()==0&&i!=1) {
                pr.push_back(i);//append prime
            }
            if (ti!=1) {
                dv.push_back(1);//append remained item
            }
            result=(calc(n,dv)+result)%MAX;
        }
        return (int)(result%MAX);
    }
    long long calc(int n,vector<int> &dv) {
        long long res=1;
        for (int i=0;i<dv.size();i++) {
            res=(res*cm(n,dv[i]))%MAX;
        }
        return res;
    }
    long long cm(int n, int m) {//make permutation chart
        if (cc.size()>m) return cc[m][0];
        else {
            for (int i=cc.size();i<=m;i++) {
                vector<long long> ctmp;
                int j;
                for (j=0;j<cc[i-1].size();j++) ctmp.push_back(cc[i-1][j]*(n+i-1));
                for (j=ctmp.size()-1;j>=0;j--) {
                    if (j>0) ctmp[j-1]+=ctmp[j]%i*MAX;
                    ctmp[j]/=i;
                }
                j=0;
                while (j<ctmp.size()) {
                    if (j==ctmp.size()-1) {
                        if (ctmp[j]>=MAX) ctmp.push_back(ctmp[j]/MAX);
                    }
                    else ctmp[j+1]+=ctmp[j]/MAX;
                    ctmp[j]%=MAX;
                    j++;
                }
                cc.push_back(ctmp);
            }
            return cc[m][0];
        }
    }
};
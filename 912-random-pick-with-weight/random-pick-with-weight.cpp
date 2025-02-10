class Solution {
public:
    vector<int> P;
    int n;
    Solution(vector<int>& w) {
        n=w.size();
        P.resize(n);
        P[0]=w[0];
        for (int i=1;i<n;i++) P[i]=w[i]+P[i-1];
    }

    int search(int start, int end, int p) {
        int mid=(start+end)/2;
        if (P[mid]<p) return search(mid+1, end, p);
        else if (start==mid) return mid;
        return search(start, mid, p);
    }
    
    int pickIndex() {
        int p=rand()%P[n-1]+1;
        return search(0, n-1, p);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
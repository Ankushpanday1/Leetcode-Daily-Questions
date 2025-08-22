class Solution {
public:
    
    vector<double> getAll(double a,double b)
    {
        vector<double> res;
        
        res.push_back(a+b);
        res.push_back(a-b);
        res.push_back(a*b);
        
        if(b!=0.0)
            res.push_back(a/b);
        return res;
    }
    
    bool recur(vector<double> a)
    {    
        int size = a.size();
     
        if(size==1)
            return abs(24-a[0])<0.001;
        
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(i!=j)
                {
                    vector<double> t;
                    for(int k=0;k<size;k++)
                    {
                        if(k!=i && k!=j)
                        {
                            t.push_back(a[k]);
                        }
                    }
                    vector<double> comb = getAll(a[i],a[j]);
                    
                    for(auto &x : comb)
                    {
                        t.push_back(x);
                        if(recur(t))
                            return true;
                        t.pop_back();
                    }
                }
            }
        }
        
        return false;
    }
    
    bool solve(vector<int> &cards)
    {
        int size = cards.size();
        vector<double> a(size);
        
        for(int i=0;i<size;i++)
        {
            a[i]=cards[i];
        }
        
        return recur(a);
    }
    
    bool judgePoint24(vector<int>& cards) {
        return solve(cards);
    }
};
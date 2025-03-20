class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>> g(n);
        for(auto x: edges){
            g[x[0]].push_back(make_pair(x[1],x[2]));
            g[x[1]].push_back(make_pair(x[0],x[2]));
        }
        vector<int> comp(n);
        vector<int> answers(2*n);
        vector<bool> vis(n, false);
        queue<int> q;
        int id = 0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                int ans = -1;
                set<pair<int,int>> viss;
                while(!q.empty()){
                    int tp = q.front();
                    comp[tp]=id;
                    q.pop();
                    for(auto x: g[tp]){
                        if(viss.count(x)==0){
                            vis[x.first]=true;
                            if(ans==-1){
                                ans=x.second;
                            } else {
                                ans&=x.second;
                            }
                            q.push(x.first);
                            viss.insert(x);
                        }
                    }
                }
                answers[id]=ans;
                ++id;   
            }
        }
        vector<int> ret;
        for(auto x: query){
            if(x[0]==x[1]){
                ret.push_back(0);
            }
            else if(comp[x[0]]==comp[x[1]]){
                ret.push_back(answers[comp[x[0]]]);
            } else {
                ret.push_back(-1);
            }
        }
        return ret;
    }
};
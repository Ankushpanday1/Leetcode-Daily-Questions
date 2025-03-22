class Solution {
public:

int findp(int node,vector<int>&rank,vector<int>&prnt){
    if(prnt[node] == node){
        return node;
    }

    return prnt[node] = findp(prnt[node],rank,prnt);
}
void uni(int u,int v,vector<int>&rank,vector<int>&prnt){
    int p_u = findp(u,rank,prnt);
    int p_v = findp(v,rank,prnt);

    if(p_u != p_v){
        if(rank[p_u]<rank[p_v]){
            prnt[p_u] = p_v;
            rank[p_v]++;

        }
        else{
            prnt[p_v] = p_u;
            rank[p_u]++;
        }
    }
}

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>rank(n,0);
        vector<int>prnt(n,0);
        for(int i =0;i<n;i++){
            prnt[i] = i;
        }
       unordered_map<int,vector<int> >adj;
       for(auto it:edges){
        adj[it[0]].push_back(it[1]);
          adj[it[1]].push_back(it[0]);
       }

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            if(findp(u,rank,prnt) != findp(v,rank,prnt)){
                uni(u,v,rank,prnt);
            }
        }

        unordered_map<int,vector<int> >mp;
        for(int i =0;i<n;i++){
            int p1 = findp(i,rank,prnt);
            mp[p1].push_back(i);
        }
        int ans =0;

        for(auto it:mp){
            int val = it.first;
            int total = it.second.size();
            int chk = 1;
            for(int i=0;i<it.second.size();i++){
                if(adj[it.second[i]].size() != total-1){
               chk = 0;
                }
            }
            if(chk ==1){
                ans++;
            }
           
        }
        return ans;

    }
};
class Solution {
public:
    unordered_map<int,vector<int>> adj;
    set<pair<int,int>> loop_edges;
    void dfs(int node,int parent_node,bool &cycle,vector<bool> &visited,vector<bool> &path_visited,vector<int> &parent)
    {
        visited[node]=true;
        path_visited[node]=true;
        parent[node]=parent_node;
        for(auto adj_node:adj[node])
        {
            if(!visited[adj_node]) 
            {
                dfs(adj_node,node,cycle,visited,path_visited,parent);
                if(cycle) return;
            }
            else 
            {
                if(path_visited[adj_node])
                {
                    cycle=true;
                    int curr=node;
                    loop_edges.insert({node,adj_node});
                    while(curr!=adj_node)
                    {
                        loop_edges.insert({parent[curr],curr});
                        curr=parent[curr];
                    }
                    return;
                }
            }
        }
        path_visited[node]=false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        vector<int> indegree(n+1,0);
        int node=-1;
        for(auto itr:edges)
        {
            int u=itr[0];
            int v=itr[1];
            adj[u].push_back(v);
            indegree[v]++;
            if(indegree[v]==2) node=v;
        }
        bool cycle=false;
        vector<bool> visited(n+1,false);
        vector<bool> path_visited(n+1,false);
        vector<int> parent(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i]) dfs(i,-1,cycle,visited,path_visited,parent);
            if(cycle) break;
        }
        // for(auto itr:loop_edges) cout<<itr.first<<"->"<<itr.second<<endl;
        if(cycle && node!=-1)
        {
            for(auto itr:loop_edges)
            {
                if(itr.second==node) return {itr.first,itr.second};
            }
        }
        else if(cycle)
        {
            for(int i=n-1;i>=0;i--) 
            {
                if(loop_edges.find({edges[i][0],edges[i][1]})!=loop_edges.end()) return {edges[i][0],edges[i][1]};
            }
        }
        else 
        {
            for(int i=n-1;i>=0;i--)
            {
                if(edges[i][1]==node) return {edges[i][0],edges[i][1]};
            }
        }
        return {};
    }
};
// Starting from the basics
// In a tree no loop can exsist,each node has exactly 1 parent except root
// Hence root has indegree=0 and rest should have degree=1
// Firstly find the node with indegree=2 obviously one its inward edge is redundant
// If cycle exsist and indegree=2 then the edges part of loop is ans
// Incase of no cycle but indegree=2 then check the edges directed towards that node and came later
// Else the root is part of cycle hence no node has indegree=2
// So in that case just remove the last occuring edge which is part of the loop
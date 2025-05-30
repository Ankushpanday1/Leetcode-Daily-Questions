class Solution {
public:

    int bfs (int root, vector<vector<int>>& adj, int k) {

      queue<int> q;
      q.push(root);
      vector<bool> vis(1001, false);
      int level = 0, res = 1;
      while (!q.empty() && level < k) {
        level++;
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
          int node = q.front();
          q.pop();
          vis[node] = true;
          for (auto nbr : adj[node]) {
            if (vis[nbr] == false)
              res++, q.push(nbr);
          }
        }
      }
      return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
      ios::sync_with_stdio(false);
      cin.tie(0); cout.tie(0);
      vector<vector<int>> adj1(edges1.size() + 1), adj2(edges2.size() + 1);
      for (int i = 0; i < edges1.size(); i++) {
        adj1[edges1[i][0]].push_back(edges1[i][1]);
        adj1[edges1[i][1]].push_back(edges1[i][0]);
      }
      for (int i = 0; i < edges2.size(); i++) {
        adj2[edges2[i][0]].push_back(edges2[i][1]);
        adj2[edges2[i][1]].push_back(edges2[i][0]);
      }
      int mx = 0;
      for (int i = 0; i < adj2.size(); i++) {
        mx = max(mx, bfs(i, adj2, k - 1));
      }
      vector<int> res(edges1.size() + 1, 0);
      for (int i = 0; i < adj1.size(); i++) {
        if (k == 0)
          res[i] = 1;
        else
          res[i] = (mx + bfs(i, adj1, k));
      }
      return res;

    }
};
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Step 1: Construct the adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Check if the graph is bipartite
        if (!isBipartite(adj, n)) {
            return -1;
        }

        // Step 3: Find the maximum BFS depth for each node
        vector<int> degreeBFS(n + 1);
        for (int i = 1; i <= n; ++i) {
            degreeBFS[i] = bfsDepth(adj, i);
        }

        // Step 4: Process connected components
        vector<int> visited(n + 1, 0);
        int totalGroups = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                totalGroups += dfs(adj, visited, degreeBFS, i);
            }
        }

        return totalGroups;
    }

private:
    int dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& degreeBFS, int node) {
        visited[node] = 1;
        int maxDepth = degreeBFS[node];
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                maxDepth = max(maxDepth, dfs(adj, visited, degreeBFS, neighbor));
            }
        }
        return maxDepth;
    }

    int bfsDepth(vector<vector<int>>& adj, int node) {
        queue<pair<int, int>> q;
        q.push({node, 1});
        vector<int> visited(adj.size(), 0);
        visited[node] = 1;
        int lastDepth = 1;
        while (!q.empty()) {
            auto [cur, depth] = q.front();
            q.pop();
            lastDepth = depth;
            for (int neighbor : adj[cur]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        return lastDepth;
    }

    bool isBipartite(vector<vector<int>>& adj, int n) {
        vector<int> color(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0 && !bfsCheckBipartite(adj, color, i)) {
                return false;
            }
        }
        return true;
    }

    bool bfsCheckBipartite(vector<vector<int>>& adj, vector<int>& color, int node) {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int curColor = (color[cur] == 1) ? 2 : 1;
            for (int neighbor : adj[cur]) {
                if (color[neighbor] == 0) {
                    color[neighbor] = curColor;
                    q.push(neighbor);
                } else if (color[neighbor] != curColor) {
                    return false;
                }
            }
        }
        return true;
    }
};
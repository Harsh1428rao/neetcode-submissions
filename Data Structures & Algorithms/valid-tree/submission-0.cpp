class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (!dfs(adj, vis, 0, -1)) return false;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) return false;
        }

        return true;
    }

    bool dfs(vector<vector<int>> &adj, vector<bool>& vis, int node, int parent){
        vis[node] = true;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(!dfs(adj, vis, it, node)) return false;
            }
            else if(it != parent) return false;
        }

        return true;
    }
};

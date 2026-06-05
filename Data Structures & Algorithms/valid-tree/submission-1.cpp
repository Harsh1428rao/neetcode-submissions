class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        if(!solve(0, -1, adj, vis))
            return false;

        for(int i = 0; i < n; i++){
            if(!vis[i])
                return false;
        }

        return true;
    }

    bool solve(int node, int parent,
               vector<vector<int>>& adj,
               vector<int>& vis){

        vis[node] = 1;

        for(auto nd : adj[node]){

            if(!vis[nd]){

                if(!solve(nd, node, adj, vis))
                    return false;

            }
            else if(nd != parent){
                return false;
            }
        }

        return true;
    }
};
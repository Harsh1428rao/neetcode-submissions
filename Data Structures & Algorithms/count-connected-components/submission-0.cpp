class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        vector<int> vis(n,false);

        int cnt = 0;

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                cnt++;
            }
        }


        return cnt;
    }

    void dfs(vector<vector<int>>& adj, vector<int> &vis, int node){
        vis[node] = true;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }

        return ;
    }
};

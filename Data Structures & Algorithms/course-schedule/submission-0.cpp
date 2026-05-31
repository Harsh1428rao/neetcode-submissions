class Solution {
public:
    bool canFinish(int numC, vector<vector<int>>& preReq) {
        vector<int> indeg(numC, 0);

        vector<vector<int>> adj(numC);

        for(auto it : preReq){
            int u = it[0], v = it[1];

            adj[v].push_back(u);
            indeg[u]++;
        }
        int cnt = 0;
        queue<int> q;

        for(int i = 0; i < numC; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int node = q.front();

            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }

        if(cnt == numC) return true;

        return false;

    }
};

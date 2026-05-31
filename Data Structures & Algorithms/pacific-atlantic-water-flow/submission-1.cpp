class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int pac = 0, atl = 0;
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if(dfs(heights, i, j, pac, atl, n, m, visited)){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    bool dfs(vector<vector<int>>& heg, int row, int col, int &pac, int &atl, int n , int m, vector<vector<bool>>& visited){
        visited[row][col] = true;
        if(row == n - 1 || col == m - 1) atl++;
        if(row == 0 || col == 0) pac++;

        if(atl >= 1 && pac >= 1) return true;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow < n && nrow >= 0 && ncol >= 0 && ncol < m && !visited[nrow][ncol] && heg[row][col] >= heg[nrow][ncol]){
                if(dfs(heg, nrow, ncol, pac, atl, n ,m, visited)){
                    return true;
                }
            }
        }

        return  false;
    }
};
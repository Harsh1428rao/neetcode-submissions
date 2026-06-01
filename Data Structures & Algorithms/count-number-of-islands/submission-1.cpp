class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for(int i = 0; i < n; i++){
            for(int j= 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, vis, i , j, n , m);
                    cnt++;
                }
            }
        }

        return cnt;

    }

    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis, int row, int col, int n, int m){
        vis[row][col] = true;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(grid, vis, nrow, ncol, n, m);
            }

        }

    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxA = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int cnt = 1;
                    solve(i, j ,n ,m, grid, vis, cnt);
                    maxA = max(maxA, cnt);
                }
            }
        }

        return maxA;
    }

    void solve(int row, int col, int n, int m, vector<vector<int>>&grid, vector<vector<bool>>&vis, int &cnt){
        vis[row][col]= true;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                cnt++;
                solve(nrow, ncol, n , m ,grid, vis, cnt);
            }
        }
    }

};

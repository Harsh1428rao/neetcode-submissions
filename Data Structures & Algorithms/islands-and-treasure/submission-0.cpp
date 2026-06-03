class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= n || ncol >= m || nrow < 0 || ncol < 0 || grid[nrow][ncol] != INT_MAX){
                    continue;
                }

                grid[nrow][ncol] = grid[row][col] + 1;
                q.push({nrow, ncol});
            }
        }
    }
};

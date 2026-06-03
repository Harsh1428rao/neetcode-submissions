class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;

        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 2)
                    q.push({{i,j},0});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        int ans = 0;

        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            q.pop();

            ans = max(ans, time);

            for(int i = 0; i < 4; i++){

                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1){

                    grid[nrow][ncol] = 2;
                    fresh--;

                    q.push({{nrow,ncol}, time + 1});
                }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};
class Solution {
public:
    
    void dfs(int row, int col, vector<vector<char>>& board, int n, int m) {

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {

            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O') {

                board[nrow][ncol] = 'I';
                dfs(nrow, ncol, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // Left and Right Boundary
        for (int i = 0; i < n; i++) {

            if (board[i][0] == 'O') {
                board[i][0] = 'I';
                dfs(i, 0, board, n, m);
            }

            if (board[i][m - 1] == 'O') {
                board[i][m - 1] = 'I';
                dfs(i, m - 1, board, n, m);
            }
        }

        // Top and Bottom Boundary
        for (int j = 0; j < m; j++) {

            if (board[0][j] == 'O') {
                board[0][j] = 'I';
                dfs(0, j, board, n, m);
            }

            if (board[n - 1][j] == 'O') {
                board[n - 1][j] = 'I';
                dfs(n - 1, j, board, n, m);
            }
        }

        // Convert remaining O -> X
        // Convert I -> O
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == 'I')
                    board[i][j] = 'O';
            }
        }
    }
};
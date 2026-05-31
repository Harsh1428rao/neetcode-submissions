class Solution {
public:
    bool exist(vector<vector<char>>& board, string word){
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt  = 0;
                if(board[i][j] == word[0]){
                    if(solve(board, i, j, word, cnt + 1, n, m)){  // FIX 1
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool solve(vector<vector<char>>& board, int row, int col, string word, int cnt, int n, int m){
        if(cnt == word.length()) return true;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        char ch = board[row][col];
        board[row][col] = '.';  // mark visited

        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
               board[nrow][ncol] != '.' && board[nrow][ncol] == word[cnt]){

                if(solve(board, nrow, ncol, word, cnt + 1, n, m)){  // FIX 2
                    board[row][col] = ch;  // restore before returning
                    return true;
                }
            }
        }

        board[row][col] = ch;  // backtrack
        return false;
    }
};

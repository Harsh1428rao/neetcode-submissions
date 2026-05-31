class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(0,0, text1, text2, dp);
    }

    int solve(int i, int j, string &text1, string text2, vector<vector<int>>& dp){
        if(i == text1.length() || j == text2.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int len = 0;
        if(text1[i] == text2[j]){
            len = solve(i + 1, j + 1, text1, text2, dp) + 1;
        }
        else{
            len = max(solve(i, j + 1, text1, text2, dp), solve(i + 1, j, text1, text2, dp));
        }

        return dp[i][j] = len;
    }
};

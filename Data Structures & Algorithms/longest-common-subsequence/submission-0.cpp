class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        
        int n = str1.length();

        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return solve(n - 1, m - 1, str1, str2, dp);
        
    }


    int solve(int idx1, int idx2, string s1, string s2, vector<vector<int>>& dp){

        if(idx1 < 0 || idx2 < 0) return 0;

        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }


        if(s1[idx1] == s2[idx2]){
            return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, s1, s2, dp);
        }

        return dp[idx1][idx2] = max(solve(idx1 - 1, idx2, s1, s2, dp), solve(idx1, idx2 - 1, s1, s2, dp));
    
    }
};

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return fcom(n,dp);
        
    }

    int fcom(int n, vector<int> &dp){
        if(dp[n] != -1) return dp[n];
        if( n == 0) return 1;
        if(n < 0) return 0;

        int take = fcom(n - 1, dp);
        int ntake = fcom(n - 2, dp);
        

        return dp[n] = take + ntake;
    }
};

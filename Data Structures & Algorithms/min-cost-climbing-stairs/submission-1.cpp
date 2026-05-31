class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int>dp1(n + 1, -1);
        vector<int>dp2(n + 1, -1);

        return min(solve(n - 1, cost, dp1) , solve(n - 2, cost, dp2));
    }
    int solve(int n , vector<int>&cost, vector<int>&dp){
        if(n < 0) return 0;
        if(n == 0 || n == 1) return cost[n];
        if(dp[n] != -1) return dp[n];
        
        int step1 = solve(n - 1, cost, dp) + cost[n];
        int step2 = solve(n - 2, cost, dp) + cost[n];

        return dp[n] = min(step1, step2);
    }
};

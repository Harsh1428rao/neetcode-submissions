class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        return solve(n - 1, nums, dp);
    }
    int solve(int n, vector<int>&nums, vector<int>&dp){
        if(n < 0) return 0;
        if(n == 0) return nums[n];

        if(dp[n] != -1) return dp[n];
        int take = solve(n - 2, nums, dp) + nums[n];
        int ntake = solve(n - 1, nums, dp);

        return dp[n] = max(take , ntake);

    }
};

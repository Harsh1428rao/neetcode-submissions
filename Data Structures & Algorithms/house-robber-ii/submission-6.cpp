class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        return max(solve(0, n - 2, nums, dp1), solve(1, n - 1, nums, dp2));
    }

    int solve(int idx, int last, vector<int>& nums, vector<int>&dp){

        if(idx == last) return nums[idx];
        if(idx > last) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = solve(idx + 2, last, nums, dp) + nums[idx];
        int ntake = solve(idx + 1, last, nums, dp);

        return dp[idx] = max(take , ntake);
    }
};



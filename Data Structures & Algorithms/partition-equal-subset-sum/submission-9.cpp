class Solution {
public:

    bool solve(int idx, vector<int>& nums,
               int target,
               vector<vector<int>>& dp){

        if(target == 0)
            return true;

        if(idx == nums.size() || target < 0)
            return false;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool take =
            solve(idx + 1, nums,
                  target - nums[idx], dp);

        bool ntake =
            solve(idx + 1, nums,
                  target, dp);

        return dp[idx][target] = take || ntake;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums)
            sum += x;

        if(sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(0, nums, target, dp);
    }
};
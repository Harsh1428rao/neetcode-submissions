class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0]; 

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(fcom(nums, n - 2, 0, dp1), fcom(nums, n - 1, 1, dp2));
    }

    int fcom(vector<int>& nums, int idx, int start, vector<int>& dp){
        if(idx < start) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + fcom(nums, idx - 2, start, dp);
        int ntake = fcom(nums, idx - 1, start, dp);

        return dp[idx] = max(take, ntake);
    }
};
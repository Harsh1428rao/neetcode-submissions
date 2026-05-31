class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, -1, n);
    }

    int solve(vector<int>& nums, int idx, int prev, int n){
        if(idx == n) return 0;

        int len = solve(nums, idx + 1, prev, n);

        if (prev == -1 || nums[idx] > nums[prev]) {
            len = max(len, 1 + solve(nums, idx + 1, idx, n));
        }

        return len;

    }
};

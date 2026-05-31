class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        fcom(0, ans, nums, res, 0, target);

        return ans;
    }

    void fcom(int idx, vector<vector<int>>&ans, vector<int>& nums, vector<int>& res, int sum, int target){
        if(sum == target) {
            ans.push_back(res);
            return;
        }
        if(sum > target || idx >= nums.size()) 
            return;
        
        // if(sum + nums[idx] <= target){
            res.push_back(nums[idx]);
            fcom(idx, ans, nums, res, sum + nums[idx], target);
            res.pop_back();
        // }

        fcom(idx + 1, ans, nums, res, sum , target);
    }
};

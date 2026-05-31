class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> res;

        fcom(ans, res, nums, 0, 0);

        return ans;


    }

    void fcom(vector<vector<int>>& ans, vector<int>&res, vector<int>&nums,int idx, int target){
        
        if(res.size() == 3){
            if(target == 0){
                ans.push_back(res);
                return ;
            }
            else{
                return ;
            }
        }
        if (idx >= nums.size()) return;

        res.push_back(nums[idx]);
        fcom(ans, res, nums, idx + 1, target + nums[idx]);
        res.pop_back();

        while(idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) idx++;
        fcom(ans, res, nums, idx + 1, target);
    }
};

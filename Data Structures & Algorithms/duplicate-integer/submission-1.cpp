class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == nums[i - 1]) cnt++;
        }

        if(!cnt) return false;

        return true;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        #if 0
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(i != j){
                    if(nums[i] + nums[j] == target){
                        ans.push_back(i);
                        ans.push_back(j);
                    }
                }
            }
        }
        #endif

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mp.count(diff) && mp[diff] != i){
                return {i, mp[diff]};
            }
        }
        
        return {};

    }
};

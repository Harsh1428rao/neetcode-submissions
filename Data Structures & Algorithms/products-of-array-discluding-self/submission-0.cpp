class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        int prod;

        for(int i = 0; i < nums.size(); i++){
            prod = 1;
            for(int j = 0; j < nums.size(); j++){
                if(i != j){
                    prod = prod * nums[j];
                }
            }

            ans.push_back(prod);
        }

        return ans;
    }
};

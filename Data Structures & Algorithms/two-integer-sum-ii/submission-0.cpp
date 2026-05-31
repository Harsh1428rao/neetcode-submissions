class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        // vector<pair<int,int>> res;

        for(int i = 0; i < num.size(); i++){
            for(int j = i + 1; j < num.size(); j++){
                if(num[i] + num[j] == target){
                    return {i+1, j+1};
                }
            }
        }
        
    }
};

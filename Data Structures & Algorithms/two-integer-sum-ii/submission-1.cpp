class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        // vector<pair<int,int>> res;

       int left = 0;
       int right = num.size() - 1;

       while(left < right){
        if(num[left] + num[right] == target){
            return {left+1, right+1};
        }
        else if(num[left] + num[right] < target){
            left++;
        }
        else{
            right--;
        }
       }

    }
};

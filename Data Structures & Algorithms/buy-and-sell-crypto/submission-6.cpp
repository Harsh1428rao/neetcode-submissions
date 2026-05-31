class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int n = prices.size();
        int ans = 0;
        while(right < n){
            if(prices[right] > prices[left]){
                ans = max(ans, prices[right] - prices[left]);
            }
            else{
             left = right;   
            }
            right++;
        }

        return ans;
    }
};

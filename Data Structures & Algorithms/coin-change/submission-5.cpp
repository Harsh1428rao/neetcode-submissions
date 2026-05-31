class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int res = INT_MAX;
        vector<int> current;
        solve(coins, amount, 0, coins.size() - 1, current, res);
        return (res == INT_MAX) ? -1 : res;
        
    }

    void solve(vector<int>& coins, int amt, int sum, int idx, vector<int>& ans, int &res){
        if(sum == amt){
            int ss = ans.size();
            if(ss < res) res = ss;
            return ;
        } 
        if(idx < 0 || sum > amt) return ;

             
        if (ans.size() >= res) return;
        ans.push_back(coins[idx]);
        solve(coins, amt, sum + coins[idx], idx, ans, res);
        ans.pop_back();
        solve(coins, amt, sum, idx - 1, ans, res);


    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(coins.size() == 1) {
//             if(coins[0] < amount && coins[0] != 1) return -1;
//         }
    
//         vector<int> ans; 
//         int res = INT_MAX;
//         int n = coins.size();
//         solve(coins, amount, 0, n - 1, ans, res);
//         if(res == INT_MAX) return -1;
//         return res;
        
//     }

//     void solve(vector<int>& coins, int amt, int sum, int idx, vector<int>& ans, int &res){
//         if(sum == amt){
//             int ss = ans.size();
//             if(ss < res) res = ss;
//             return ;
//         } 
//         if(idx < 0 || sum > amt) return ;

//         ans.push_back(coins[idx]);
//         solve(coins, amt, sum + coins[idx], idx, ans, res);
//         ans.pop_back();
//         solve(coins, amt, sum, idx - 1, ans, res);


//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        long res = solve(coins, n - 1, amount);
        return (res >= INT_MAX) ? -1 : (int)res;
    }

    long solve(vector<int>& coins, int idx, int amt) {
        if (amt == 0) return 0;
        if (amt < 0 || idx < 0) return INT_MAX;

        long take = 1 + solve(coins, idx, amt - coins[idx]);
        long ntake = solve(coins, idx - 1, amt);

        return min(take, ntake);
    }
};




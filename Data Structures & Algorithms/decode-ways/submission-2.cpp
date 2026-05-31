class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        n = s.size();

        dp.assign(n+1, -1);
        res = 0;
        return fun(s, 0);
        // return res;
    }
private:
    int res, n;
    vector<int> dp;
    int fun(string& s, int i){
        if(i >= n){
            // ++res;
            return 1;
        }
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int tmp1 = 0;
        if(i + 1 < n){
            int tmp = ((s[i] - '0') * 10) + (s[i+1] - '0');
            if(tmp <= 26){
                tmp1 += fun(s, i+2);
            }
        }

        tmp1 += fun(s, i+1);

        return dp[i] = tmp1;
    }
};

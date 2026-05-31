class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }

    int solve(int idx, string &s, vector<int>& dp) {
        if (idx == s.length()) return 1;
        if (s[idx] == '0') return 0;
        if (dp[idx] != -1) return dp[idx];

        int res = solve(idx + 1, s, dp);

        if (idx + 1 < s.length()) {
            // Optimization: manually check instead of stoi/substr for speed
            int twodigit = (s[idx] - '0') * 10 + (s[idx + 1] - '0');

            if (twodigit >= 10 && twodigit <= 26) {
                res += solve(idx + 2, s, dp); // Corrected += here
            }
        }

        return dp[idx] = res;
    }
};
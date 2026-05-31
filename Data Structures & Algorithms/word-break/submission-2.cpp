class Solution {
public:

    bool solve(int idx, unordered_set<string>& word,
               string &s, vector<int>& dp) {

        if(idx == s.length())
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        string temp = "";

        for(int i = idx; i < s.length(); i++) {

            temp += s[i];

            if(word.count(temp)) {

                if(solve(i + 1, word, s, dp))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> word(wordDict.begin(), wordDict.end());

        vector<int> dp(s.length(), -1);

        return solve(0, word, s, dp);
    }
};
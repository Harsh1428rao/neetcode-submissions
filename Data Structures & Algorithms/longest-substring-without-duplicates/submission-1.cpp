class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int n = s.length();
        int len = 0;

        for(int right = 0; right < n; right++){
            while(mp.count(s[right]) > 0){
                mp.erase(s[left]);
                left++;
            }

            mp[s[right]]++;
            len = max(len, right - left + 1);
        }

        return len;
    }
};

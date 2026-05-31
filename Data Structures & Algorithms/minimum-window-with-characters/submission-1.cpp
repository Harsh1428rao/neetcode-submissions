class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int n = s.length();
        int m = t.length();
        int len = INT_MAX;
        int cnt = 0;
        int start = 0;

        for(int i = 0; i < t.size(); i++){
            mp[t[i]]++;
        }
        int left = 0;
        int right = 0;

        while(right < n){
            if(mp.find(s[right]) != mp.end() && mp[s[right]] > 0){
                cnt++;
            }
            mp[s[right]]--;
            right++;

            while(cnt == m){
                int currlen = (right - left);
                if(len > currlen){
                    len = currlen;
                    start = left;
                }
                if(mp.find(s[left]) != mp.end()){
                    mp[s[left]]++;
                    if(mp[s[left]] > 0) cnt--;
                }
                left++;
            }
        }
        if(len == INT_MAX) return "";
        return s.substr(start,len);
    }
};

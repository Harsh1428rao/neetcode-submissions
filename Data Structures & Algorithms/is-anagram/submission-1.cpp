class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int s1 = s.length();
        int s2 = t.length();
        int l = max(s1,s2);

        for(int i = l - 1;  i >= 0; i--){
            if(s[i] != t[i]) return false;
        }

        return true;

    }
};

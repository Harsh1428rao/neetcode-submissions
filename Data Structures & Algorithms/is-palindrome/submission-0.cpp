class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' ' && isalnum(s[i])){
                ss+= tolower(s[i]);
            }
        }
        string str = ss;

        reverse(str.begin(), str.end());

        if(str == ss){
            return true;
        }

        return false;
    }
};

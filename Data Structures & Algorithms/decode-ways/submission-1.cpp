class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        n = s.size();

        res = 0;
        fun(s, 0);
        return res;
    }
private:
    int res, n;
    void fun(string& s, int i){
        if(i >= n){
            ++res;
            return;
        }
        if(s[i] == '0') return;

        if(i + 1 < n){
            int tmp = ((s[i] - '0') * 10) + (s[i+1] - '0');
            if(tmp <= 26){
                fun(s, i+2);
            }
        }

        fun(s, i+1);
    }
};

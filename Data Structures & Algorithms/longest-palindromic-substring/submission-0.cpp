class Solution {
public:
    string longestPalindrome(string s) {

    int cnt = 0;
    string res ;
    int n = s.length();
    for(int i = 0 ; i < n; i++){
        for(int j = i ; j < n; j++){
        string str = s.substr(i , j - i + 1);
        string strr = str;
        reverse(strr.begin(), strr.end());

            if(strr == str){
                if(j - i + 1 > cnt){
                    cnt = j - i + 1;
                    res = str;
                }
            }    
        }
    }

       return res; 
    }
};

class Solution {
public:

    string encode(vector<string>& strs) {
        string str;
        for(int i = 0; i < strs.size(); i++){
            str = str + strs[i] + '.';
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> str;
        string st = "";
        for(int i = 0; i < s.length(); i++){

            if(s[i] == '.'){
                str.push_back(st);
                st = "";
                continue;
            }

            st = st + s[i];
            
        }
        return str;
    }
};

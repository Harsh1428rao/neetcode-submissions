class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // unordered_map<char, int> count;

        // for(char ch : s2){
        //     count[ch]++;
        // }

        // int n = s1.length();
        // int cnt = 0;

        // for(int i = 0; i < n; i++){
        //     if(count[s1[i]] == 1){
        //         cnt++;
        //     }
        // }

        // if(cnt == n) return true;

        // return false;

        sort(s1.begin(), s1.end());

        for(int i = 0; i < s2.size(); i++){
            for(int j = i; j < s2.size(); j++){
                string subtr = s2.substr(i, j - i + 1);
                sort(subtr.begin(), subtr.end());

                if(subtr == s1) return true;
            }
        }

        return false;
    }
};

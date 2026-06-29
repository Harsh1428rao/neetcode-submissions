class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n  = heights.size();
        int maxv = INT_MIN;


        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int bar = min(heights[i],heights[j]);
                maxv = max(maxv, bar*(j - i));
            }
        }

        return maxv;
    }
};

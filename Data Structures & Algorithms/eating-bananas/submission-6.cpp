// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {

//         int n = piles.size();
//         int minSpeed = INT_MAX;

//         for(int i = 0; i < n; i++) {
//             int rate = piles[i];
//             int hr = 0;

//             for(int j = 0; j < n; j++) {
//                 hr += ceil((double)piles[j] / rate);
//             }

//             if(hr <= h) {
//                 minSpeed = min(minSpeed, rate);
//             }
//         }

//         return minSpeed == INT_MAX ? -1 : minSpeed;
//     }
// };

// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int speed = 1;

//         while(true){
//             long long totaltime = 0;
//             for(int pile : piles){
//                 totaltime += ceil((double)pile/speed);
//             }

//             if(totaltime <= h){
//                 return speed;
//             }

//             speed++;
//         }
//     }
// };

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = l + (r - l) / 2;

            long long time = 0;

            for (int pile : piles) {
                time += ceil((double)pile /k);
            }

            if (time <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};

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



class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;

        while(true){
            long long totaltime = 0;
            for(int pile : piles){
                totaltime += ceil((double)pile/speed);
            }

            if(totaltime <= h){
                return speed;
            }

            speed++;
        }
    }
};
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
        while (true) {
            long long totalTime = 0;
            for (int pile : piles) {
                totalTime += (pile + speed - 1) / speed;
            }

            if (totalTime <= h) {
                return speed;
            }
            speed++;
        }
    }
};
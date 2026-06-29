class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        // Don't modify vector while iterating over it
        for (int i = 0; i < n; i++) {
            gas.push_back(gas[i]);
        }

        for (int i = 0; i < n; i++) {
            cost.push_back(cost[i]);
        }

        int m = gas.size();

        for (int i = 0; i < n; i++) {
            int totalcost = gas[i] - cost[i];

            if (totalcost < 0) continue;

            bool possible = true;

            // increment j, not i
            for (int j = i + 1; j < i + n; j++) {
                totalcost = totalcost - cost[j] + gas[j];

                if (totalcost < 0) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                return i;
            }
        }

        return -1;
    }
};
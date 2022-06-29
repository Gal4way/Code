#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        for (int i = 0; i < gas.size(); i++)
        {
            int sum = 0;
            int n = i;
            sum += gas[n] - cost[n];
            if (sum < 0) continue;
            n++;
            if (n == gas.size()) n = 0;
            while (n != i)
            {
                sum += gas[n] - cost[n];
                if (sum < 0) break;
                n++;
                if (n == gas.size()) n = 0;
            }
            if (sum >= 0) return i;
        }
        return -1;
    }
};
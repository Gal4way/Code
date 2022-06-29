#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        if (abs(target) > sum) return 0; // 此时没有方案
        if ((sum + target) % 2 != 0) return 0;

        
        int w = (sum + target) / 2;
        int n = nums.size();
        vector<int>& nw = nums;

        vector<int> dp (1001, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = w; j >= nw[i]; j--)
            {
                dp[j] += dp[j - nw[i]];
            }
        }
        return dp[w];

    }
};
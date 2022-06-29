#include <vector>
#include <algorithm>
using namespace std;
// 关键在于将石头分为两个质量最接近的组，然后大的减小的就ok
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = 0;
        for (int i : stones)
        {
            sum += i;
        }
        int tar = sum / 2;
        
        vector<int> dp(15001, 0);
        int n = stones.size();
        vector<int>& nw = stones;
        vector<int>& nv = stones;
        for (int i = 0; i < n; i++)
        {
            for (int j = tar; j >= nw[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nw[i]] + nv[i]);
            }
        }
        int smaller = dp[tar];
        int bigger = sum - dp[tar];
        int result = bigger - smaller;
        return result;
    }
};
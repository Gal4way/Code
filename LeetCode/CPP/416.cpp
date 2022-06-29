// 回溯
// 动态规划
// 滑动窗口  不可行，滑动窗口要求目标值一定要并列在一起，能在一个窗口中体现出来才可以
// 将能不能装满的问题转化为了价值最大的问题，因为价值最大的情况就是刚好装满的情况
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum % 2 != 0) return false;
        int tar = sum / 2;

        vector<int> dp(10001, 0);
        for (int j = tar; j >= nums[0]; j--)
        {
            dp[j] = nums[0];
        }

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = tar; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[tar] == tar) return true;
        return false;
    }
};
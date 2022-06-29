// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

// 注意： 答案中不可以包含重复的三元组。

// 示例：

// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
            if (nums[i] > 0) break;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r++;
                if (l == r) break;
                if (nums[l] + nums[r] + nums[i] == 0) 
                {
                    result.push_back({l, r, i});
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] + nums[i] > 0) r--;
                else l++;
            }
        }
        return result;
    }
};
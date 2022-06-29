#include <vector>
using namespace std;   
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return {-1, -1};
        int l = searchLeft(nums, target);
        int r = searchRight(nums, target);
        if (l <= r) return {l, r};
        return {-1, -1};
    }
    int searchLeft(vector<int>& nums, int target)
    {
        int i = 0;
        int j = nums.size();
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target) 
            {
                j = mid;
            }     
            else
            {
                i = mid + 1;
            }
        }
        return i;
    }

    int searchRight(vector<int>& nums, int target)
    {
        int i = 0;
        int j = nums.size();
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] > target) 
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i - 1;
    }
};
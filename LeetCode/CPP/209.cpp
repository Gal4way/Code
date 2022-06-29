#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int l = 0;
        int r = 0;
        int length = 100000 + 10;
        int sum = 0;

        for (; r < nums.size(); r++)
        {
            sum += nums[r];
            while (sum >= target)
            {
                if (length > r - l + 1) length = r - l + 1;
                sum -= nums[l];
                l++;
            }
        }
        return length == 100000 + 10 ? 0 : length;
    }
};




        // int l = 0;
        // int r = 0;
        // int length = 0;
        // int sum = 0;
        // int result = 0;
        // while (r < nums.size())
        // {
        //     if (sum < target)
        //     {
        //         sum += nums[r];
        //         length++;
        //         r++;
        //         continue;
        //     }
        //     if (result > length) result = length; 

        //     while (sum >= target)
        //     {
        //         sum -= nums[l];
        //         length--;
        //         l++;
        //     }
        //     if (result > length + 1) result = length + 1;
        // }
        // return result;
// // 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

// // 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

// // 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include <iostream>
#include <vector>
using namespace std;

// // class Solution 
// // {
// // public:
// //     static int removeElement(vector<int>& nums, int val) 
// //     {
// //         if (!nums.size()) return 0;
        
// //         int i = 0;
// //         for (i; i < nums.size();)
// //         {
// //             static int j = nums.size() - 1;

// //             if (nums[i] != val) 
// //             {
// //                 i++;
// //                 continue;
// //             }

// //             if (i < j)
// //             {
// //                 while (i < j && nums[j] == val) j--;
// //                 int temp = nums[i];
// //                 nums[i] = nums[j];
// //                 nums[j] = temp;
// //                 i++;
// //                 j--;
// //             }
            
// //             if (i >= j) break;
// //         }
// //         return nums[i] == val ? i : i + 1;
// //     }
// // };

// // int main()
// // {
// //     vector<int> v1 = {3,2,2,3};
// //     int length = Solution::removeElement(v1, 3);
// //     for (int i = 0; i < length; i++)
// //     {
// //         cout<<v1[i]<<endl;
// //     }
// // }


// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution 
// {
// public:
//     static int RemoveElement(vector<int>& nums, int val) 
//     {
//         int slowPt = 0;
//         int fastPt = 0;
//         while (fastPt < nums.size())
//         {
//             if (slowPt == fastPt && nums[fastPt] != val)
//             {
//                 slowPt++;
//                 fastPt++;
//                 continue;
//             }
//             else if (nums[fastPt] == val)
//             {
//                 fastPt++;
//                 continue;
//             }
//             else
//             {
//                 nums[slowPt] = nums[fastPt];
//                 slowPt++;
//                 fastPt++;
//             }
//         }
//         return slowPt;
//     }
// };

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if (nums.size() == 0) return 0;
        int l = 0;
        int r = nums.size() - 1;    
        while (l < r)
        {
            while (l < r && nums[l] != val) l++;
            while (l < r && nums[r] == val) r--;
            if (l < r)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        if (nums[l] == val) return l;
        else return l + 1;
    }
};
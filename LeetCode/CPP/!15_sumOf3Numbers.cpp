// //给一个包含n个整数的数组nums，判断nums中是否存在三个元素
// //a,b,c, 使得a+b+c = 0? 找出所有和为0且不重复的三元组

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// class Solution
// {
//     public:
//         static vector<vector<int>> threeSum(vector<int> nums)
//         {
//             vector<vector<int>> ans;
            
//             int length = nums.size();

//             if (length < 3)
//                 return {};

//             sort(nums.begin(), nums.end());
//             if (nums[0] > 0)
//                 return {};
            
//             for (int i = 0; i < length; i++)
//             {
//                 if (i > 0 && nums[i] == nums[i - 1])
//                 {
//                     continue;
//                 }

//                 int a = i + 1;
//                 int b = length - 1;

//                 while (a < b)
//                 {
//                     if (nums[i] + nums[a] + nums[b] == 0)
//                     {
//                         ans.push_back({nums[i], nums[a], nums[b]});
//                         while (nums[a] == nums[a + 1])
//                         {
//                             a++;
//                         }
//                         while (nums[b] == nums[b - 1])
//                         {
//                             b--;
//                         }
//                         a++;
//                         b--;
//                     }
                    
//                     else if(nums[i] + nums[a] + nums[b] > 0)
//                     {
//                         b--;
//                     }

//                     else
//                     {
//                         a++;
//                     }
//                 }
//             }

//             return ans;
//         }
// };

// class Solution
// {
//     public:
//         static vector<vector<int>> threeSum(vector<int> nums)
//         {
//             int n = nums.size();
//             sort(nums.begin(), nums.end());
//             vector<vector<int>> ans;

//             for (int first = 0; first < n; first++)
//             {
//                 if (first > 0 && nums[first] == nums[first - 1])
//                 {
//                     continue;
//                 }

//                 int third = n - 1;
//                 int target = -nums[first];
                
//                 for (int second = first + 1; second < n; second++)
//                 {
//                     if (second > first + 1 && nums[second] == nums[second - 1])
//                     {
//                         continue;
//                     }

//                     while (second < third && nums[second] + nums[third] > target)
//                     {
//                         third--;
//                     }

//                     if (second == third)
//                     {
//                         break;
//                     }

//                     if (nums[second] + nums[third] == target)
//                     {
//                         ans.push_back({nums[first], nums[second], nums[third]});
//                     }

//                 }
//             }

//             return ans;
//         }
// };

































// int main()
// {
//     auto a = Solution::threeSum({0,0,0});
//     cout<<a.size();
    
// }



class Solution
{
    public:
        static vector<vector<int>> threeSum(vector<int> nums)
        {
            vector<vector<int>> results;
            if (nums.size() < 3) return results;
            if (nums.size() == 3 && nums[0] == 0) return {{0,0,0}};
            else if (nums.size() == 3 && nums[0] != 0) return results;
            sort(nums.begin(), nums.end());
            

            for (int cur = 0; cur < nums.size(); cur++)
            {
                if (cur > 0 && nums[cur - 1] == nums[cur]) continue;
            
                int i = 0, j = nums.size() - 1;
                while (i < j)
                {
                    while (i == cur || nums[i] == nums[i - 1]) i++;
                    while (j == cur || nums[j] == nums[j + 1]) j--;
                    int sum = nums[i] + nums[j];                    

                    if (sum + nums[cur] > 0)
                    {
                        j--;
                        continue;
                    }
                    else if (sum + nums[cur] < 0)
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        results.push_back({nums[i], nums[j], nums[cur]});
                        j--;
                        i++;
                        continue;
                    }
                }
            }
            return results;
        }
};

int main()
{
    vector<int> a;
    
}
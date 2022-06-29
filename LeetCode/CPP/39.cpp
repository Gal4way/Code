//path用来保存读取到的目标组合

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 正常回溯步骤
// class Solution
// {
// private:
//     vector<vector<int>> result;
//     vector<int> path;
//     void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
//     {
//         if (sum > target) return;
//         if (sum == target)
//         {
//             result.push_back(path);
//             return;
//         }

//         for (int i = startIndex; i < candidates.size(); i++)
//         {
//             sum += candidates[i];
//             path.push_back(candidates[i]);
//             backtracking(candidates, target, sum, i);
//             sum -= candidates[i];
//             path.pop_back();
//         }
//     }

// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target)
//     {
//         result.clear();
//         path.clear();
//         backtracking(candidates, target, 0, 0);
//         return result;
//     }
// };


// 剪枝版（排序，根据相邻数据大小比较删去多余比较步骤）
class Solution
{
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

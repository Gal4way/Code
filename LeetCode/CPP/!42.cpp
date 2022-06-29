//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//双指针 快慢指针
#include <iostream>
#include <vector>
using namespace std;

int secondMax(vector<int>& nums)
{
    int max = 1;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[max] < nums[i])
        {
            max = i;
        }
    }
    return max;
}

int edge(vector<int>& height)
{
    if (height.size() <= 2)
    {
        return 0;    
    }

    int big = secondMax(height);

    int inside = 0;
    for (int i = 1; i < big; i++)
    {
        inside += height[i];
    }
    int left = (big - 1) * height[big] - inside; 
    
    vector<int> right(height.begin() + big, height.end());
    return left + edge(right);
}



class Solution
{
public:
    static int trap(vector<int>& height)
    {
        int sum = 0;
        int i = 0, j = 0;
        while (i <= j && j < height.size())
        {
            j++;
            if (j >= height.size())
            {
                break;
            }

            if (height[i] <= height[j])
            {
                i = j;
                continue;
            }

            int inside = 0;

            while (height[i] > height[j])
            {
                inside += height[j];
                j++;
                if (j >= height.size())
                {
                    break;
                }
            }

            if (j >= height.size())
            {
                vector<int> edgeNums(height.begin() + i, height.end());
                sum += edge(edgeNums);
                return sum;
            }

            sum += (j - i - 1) * height[i] - inside;
            i = j;
        }
        return sum;
    }
};

int main()
{
    vector<int> height = {0};
    cout<<Solution::trap(height)<<endl;
}


//单调栈
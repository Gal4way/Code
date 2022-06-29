#include <algorithm>
#include <iostream>
using namespace std;
int DP01backpack1dim(int w, int n, int nw[], int nv[]) // n 从 物品 0 开始比较好一点
{
    int dp[w + 1] = {};
    for (int i = 0; i < w + 1; i++)
    {
        dp[i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = w; j >= nw[i - 1]; j--)
        {
            dp[j] = max(dp[j], dp[j - nw[i - 1]] + nv[i - 1]);
        }
    }
    
    return dp[w];
}

int main()
{
    int nw [3] = {1, 2, 3};
    int nv [3] = {3, 4, 5};
    cout<<DP01backpack1dim(5, 3, nw, nv)<<endl;
}
#include <iostream>
#include <vector>
using namespace std;


int DP01Backpack(int w, int n, vector<int> nw, vector<int> nv)
{
    vector<vector<int>> DP(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (nw[i - 1] > j)
            {
                DP[i][j] = DP[i - 1][j];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - nw[i - 1]] + nv[i - 1]);
            }
        }
    }
    return DP[n][w];
}

int main()
{
    cout<<DP01Backpack(5, 3, {1, 2, 3}, {2, 3, 4})<<endl;
}
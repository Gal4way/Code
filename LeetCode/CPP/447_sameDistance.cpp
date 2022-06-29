//三元组统计

//给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。
//回旋镖 是由点 (i, j, k) 表示的元组 ，
//其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
// 返回平面上所有回旋镖的数量。

//sb 暴力 循环 解法
// #include <math.h>
// #include <vector>
// #include <iostream>
// using namespace std;

// class Solution
// {
// public:
//     static int numberOfBoomerangs(vector<vector<int>> & points)
//     {
//         int pop = 0;
//         int numbers = 0;
//         for (vector<vector<int>>::iterator i1 = points.begin(); i1 < points.end(); i1++)
//         {
//             vector<vector<int>>::iterator copyI1 = i1;
//             copyI1++;
//             for (vector<vector<int>>::iterator i2 = copyI1; i2 < points.end(); i2++)
//             {
//                 vector<vector<int>>::iterator copyI2 = i2;
//                 copyI2++;
//                 int dis1 = ((*i1)[0] - (*i2)[0])*((*i1)[0] - (*i2)[0]) + ((*i1)[1] - (*i2)[1])*((*i1)[1] - (*i2)[1]);
//                 for (vector<vector<int>>::iterator i3 = copyI2; i3 < points.end(); i3++)
//                 {
//                     int dis2 = ((*i1)[0] - (*i3)[0])*((*i1)[0] - (*i3)[0]) + ((*i1)[1] - (*i3)[1])*((*i1)[1] - (*i3)[1]);
//                     int dis3 = ((*i2)[0] - (*i3)[0])*((*i2)[0] - (*i3)[0]) + ((*i2)[1] - (*i3)[1])*((*i2)[1] - (*i3)[1]);
//                     if (dis2 == dis1 || dis3 == dis1 || dis2 == dis3)
//                     {
//                         numbers += 2;
//                         if (dis2 && dis1 && dis3 == dis1 && dis2 == dis3)
//                         {
//                             numbers += 4;
//                         }
//                     }
//                     pop++;
//                 }
//             }
//         }
//         cout<<pop<<endl;
//         return numbers;
//     };
// };
// int main()
// {
//     vector<vector<int>> points = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
//     cout<<Solution::numberOfBoomerangs(points)<<endl;
// }

// 哈希表

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    static int numberOfBoomerangs(vector<vector<int>> &points) {
        int ans = 0;
        map<int, int> cnt;
        for (auto&& x : points) {
            cnt.clear();
            for (auto&& y : points) {
                int n = cnt[(x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])]++;
                cout<<n<<endl;
                ans += 2 * n;
            }
        }
        return ans;
    }
};

int main()
{
    // vector<vector<int>> points = {{0,0},{1,0},{-1,0}};
    // cout<<Solution::numberOfBoomerangs(points)<<endl;
    map<int, int> cnt;
    cout<<++cnt[0]<<endl;
}
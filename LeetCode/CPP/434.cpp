//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
//请注意，你可以假定字符串里不包括任何不可打印的字符。
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    static int countSegments(string s)
    {
        int sum = 0;

        s.append(" ");
        for (char a: s)
        {
            static char lastOne = ' ';
            if (lastOne == ' ' && a != ' ' || lastOne != ' ' && a == ' ')
            {
                sum++;
            }
            lastOne = a;
        }
        return sum/2;
    }
};
int main()
{
    string a = " 345 613 2123 ";
    cout<<Solution::countSegments(a)<<endl;
}



// 神循环
// class Solution {
//     public int countSegments(String s) {
//         int n = s.length();
//         int ans = 0;
//         for (int i = 0; i < n; ) {
//             if (s.charAt(i) == ' ' && i++ >= 0) continue;
//             while (i < n && s.charAt(i) != ' ') i++;
//             ans++;
//         }
//         return ans;
//     }
// }

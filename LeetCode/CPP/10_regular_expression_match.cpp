// 动态规划
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    static bool isMatch(string s, string p)
    {
        int sLen = s.length();
        int pLen = p.length();

        bool dp [sLen + 1][pLen + 1];

        //初始化
        dp[0][0] = true;
        for (int i = 1; i <= sLen; i++)
        {
            dp[i][0] = false;
        }
        for (int j = 1; j <= pLen; j++)
        {
            dp[0][j] = false;
        }
        for (int j = 2; j <= pLen; j+=2)
        {
            if (p[j - 1] == '*' && dp[0][j - 2])
            {
                dp[0][j] = true;
            }
        }

        //判断
        for (int i = 1; i <= sLen; i++)
        {
            for (int j = 1; j<= pLen; j++ )
            {
                if (p[j - 1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }

                else if (p[j - 1] == '*')
                {   
                    if (p[j - 2] == '.')
                    {
                        dp[i][j] = false;
                        for (int t = 0; t <= i; t++)
                        {
                            if (dp[t][j - 2] == true)
                            {       
                                dp[i][j] = true;
                                break;
                            }
                        }
                        continue;
                    }
                    dp[i][j] = (dp[i - 1][j] && (s[i - 1] == p[j - 2])) || (dp[i][j-2]);
                }

                else
                {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }

        return dp[sLen][pLen];
    }
};

int main()
{
    string s = "cabbbbcbcacbab";
    string p = ".*b.*a.*";
    cout<<(Solution::isMatch(s, p) ? "true" : "false")<<endl;
}
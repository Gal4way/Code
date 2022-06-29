// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

// 示例 1： 输入：s = "We are happy."
// 输出："We%20are%20happy."

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        int count = 0;
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') count++;
        }
        int sNewSize = sOldSize + count * 2;
        s.resize(sNewSize);
        for (int i = sOldSize - 1, j = sNewSize - 1; i != j; )
        {
            if (s[i] == ' ')
            {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j = j - 3;
                i--;
                continue;
            }
            s[j] = s[i];
            i--;
            j--;
            continue;
        }
        return s;
    }
};
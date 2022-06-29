// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 
//的字符串 s 判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }

        unordered_map<char,char> pairs = {
            {'(',')'},
            {'[',']'},
            {'{','}'}
        };

        stack<char> stk;
        for (char ch: s)
        {
            if (pairs.count(ch))
            {
                stk.push(ch);
            }

            else
            {
                if (stk.empty() || pairs[stk.top()] != ch)  //关键 可能没有top stack 就报错了
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        return stk.empty();  // 关键 可能出现(((( ))) 的情况
    }
};
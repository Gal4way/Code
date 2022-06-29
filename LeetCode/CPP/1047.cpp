#include <string>
#include <stack>
#include <algorithm>
using namespace std;
// class Solution
// {
// public:
//     string removeDuplicates(string S)
//     {
//         stack<char> st;
//         for (char s : S)
//         {
//             if (st.empty() || s != st.top())
//             {
//                 st.push(s);
//             }
//             else
//             {
//                 st.pop();
//             }
//         }
//         string result = "";
//         while (!st.empty())
//         {
//             result += st.top();
//             st.pop();
//         }
//         reverse(result.begin(), result.end());
//         return result;
//     }    
// };

class Solution
{
public:
    string removeDuplicates(string S)
    {
        string result;
        for (char s: S)
        {
            if (!result.empty() && result.back() == s)
            {
                result.pop_back();
            }
            else 
            {
                result.push_back(s);
            }
        }
        return result;
    }
};


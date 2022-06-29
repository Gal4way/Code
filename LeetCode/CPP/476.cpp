//给你一个 正 整数 num ，输出它的补数。补数是对该数的二进制表示取反。
#include <iostream>
using namespace std;

class Solution
{
public:
    static int findComplement(int num)
    {
        int a = 1;
        a <<= 30;

        while (! (num & a))
        {
            num |= a;
            a >>= 1;
        }

        return ~(num | (1 << 31));
    }
};

int main()
{
    int num = 5;
    cout<<Solution::findComplement(num)<<endl;
}
// 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
// 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead
// 操作返回 -1 )

#include <stack>
using namespace std;
class CQueue 
{
private:
    stack<int> input;
    stack<int> output;
public:
    CQueue() {}

    void appendTail(int value)
    {
        input.push(value);
    }

    int deleteHead() 
    {
        if (input.empty() && output.empty())
        {
            return -1;
        }

        else if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int out = output.top();
        output.pop();
        return out;
    }
};


#include <iostream>

int main()
{
    char a [10];
    char b [10];

    std::cin>>a;
    std::cin>>b;

    std::cout<<a<<b<<std::endl;
}











// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    static int singleNumber(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        int answer = 0;
        while (it < nums.end())
        {
            answer ^= (*it);
            it++;
        }
        return answer;

    }
};

int main()
{
    vector<int> example = {1,1,2,2,3,3,4,4,5,5,6,6,7};
    cout<<Solution::singleNumber(example);
}
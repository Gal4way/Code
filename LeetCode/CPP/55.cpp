#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {   
        int cov = 0;
        int i = 0;
        if (nums.size() == 1) return true;
        while (i <= cov && cov < nums.size() - 1)
        {
            if (i + nums[i] > cov) cov = i + nums[i];
            i++;
        }
        if (cov >= nums.size() - 1) return true;
        return false;
    }
};
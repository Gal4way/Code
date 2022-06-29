#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    static int removeElement(vector<int>& nums, int val) 
    {

        int i = 0, j = nums.size() - 1;

        while (i <= j)
        {
            while (i < nums.size() && nums[i] != val)
            {
                i++; 
            }
            while (j > -1 && nums[j] == val)
            {
                j--;
            }
            if(i < j) swap(nums[i], nums[j]);
        }
        return i;
    }
};


#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    static int removeElement(vector<int>& nums, int val) 
    {
        int slowPt = 0;
        int fastPt = 0;
        while (fastPt < nums.size())
        {
            if (slowPt == fastPt && nums[fastPt] != val)
            {
                slowPt++;
                fastPt++;
                continue;
            }
            else if (nums[fastPt] == val)
            {
                fastPt++;
                continue;
            }
            else
            {
                nums[slowPt] = nums[fastPt];
                slowPt++;
                fastPt++;
            }
        }
        return slowPt;
    }
};
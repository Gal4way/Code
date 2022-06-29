#include <iostream>
using namespace std;
int removeCharacter(int nums[], int value)
{
    int valueNums = 0;
    int length = sizeof(nums)/sizeof(int);
    for (int i = 0; i < length; i++)
    {
        while (nums[length - 1 - valueNums] == value)
        {
            valueNums ++;
        }
        if (nums[i] == value)
        {
        
            int temp;
            temp = nums[length - 1 - valueNums];
            nums[length - 1 - valueNums] = nums[i];
            nums[i] = temp;
        }
    }
    return length - valueNums;
}


int main()
{
    int nums[7] = {1,2,3,4,5,6,7};
    int value = 2;
    remove


}
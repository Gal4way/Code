#include <iostream>

using namespace std;

void insertSort(int *nums, int length)
{
    for (int i = 1; i < length - 1; i++)
    {
        int change = nums[i];
        int before = nums[i - 1];
        while (before > change)
        {
            int temp = nums[i - 1];
            nums[i - 1] = nums[i];
            nums[i] = temp;
            change = nums[i - 1];
            before = nums[i - 2];
        }
    }
}

int select(int *nums, int length)
{
    int* middles;
    int i = 0;
    while (5 + 5 * i <= length)
    {
        insertSort(nums + 5 * i, 5);
        middles[i] = nums[2 + 5 * i];
        i++;
    }
    insertSort(nums + 5 * i, length - 5 * i);
    middles[i] = nums[5 * i + (length - 5 * i) / 2];

    if (i > 1)
    {
        int middle = select(middles, i + 1);
        return middle;
    }

    return middles[i];
}

int partition(int *nums, int length, int middle)
{
    int i = 0;
    int j = length - 1;
    while (i != j)
    {
        while (nums[i] < middle)
        {
            i++;
        }
        
        while (nums[j] > middle)
        {
            j--;
        }

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    nums[i] = middle;
    return i;
}

int find(int *nums, int p ,int q, int i)
{
    int middle = select(nums + p, q - p);
    int toBeConfirmed = partition(nums + p, q - p, middle);
    if (toBeConfirmed == i)
    {
        return nums[toBeConfirmed];
    }
    else if (toBeConfirmed < i)
    {
        return find(nums, p + toBeConfirmed, q, i - toBeConfirmed);
    }
    else if (toBeConfirmed > i)
    {
        return find(nums, p, p + toBeConfirmed, i);
    }
}

int main()
{
    int a [10] = {1,3,4,5,6,2,7,8,9,10};
    cout<<find(a,0,9,3)<<endl;
    return 0;
}
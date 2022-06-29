#include <vector>
#include <random>
#include <time.h>
using namespace std;

// class Solution
// {
// public:
//     void sort(vector<int>& nums, int left, int right)
//     {
//         if (left > right) return;
//         int L = left;
//         int R = right;
//         int flag = (left + right) / 2;
//         swap(nums[flag], nums[left]);
//         int base = nums[left];
//         while (L < R)
//         {
//             while (base <= nums[R] && L < R)
//             {
//                 R--;
//             }
//             while (base >= nums[L] && L < R)
//             {
//                 L++;
//             }
//             if (L < R)
//             {
//                swap(nums[R], nums[L]); 
//             }
//         }

//         nums[left] = nums[L];
//         nums[L] = base;
//         sort(nums, left, L - 1);
//         sort(nums, L + 1, right);
//     }

//     vector<int> sortArray(vector<int>& nums)
//     {
//         int left = 0;
//         int right = nums.size() - 1;
//         sort(nums, left, right);
//         return nums;
//     }
// };




// int Paritition(int A[], int low, int high)
// {
//     int pivot = A[low];
//     while (low < high)
//     {
//         while (low < high && A[high] >= pivot)
//         {
//             --high;
//         }
//         A[low] = A[high];
//         while (low < high && A[low] <= pivot)
//         {
//             ++low;
//         }
//         A[high] = A[low];
//     }
//     A[low] = pivot;
//     return low;
// }

// void QuickSort(int A[], int low, int high)
// {
//     if (low < high)
//     {
//         int pivot = Paritition(A, low, high);
//         QuickSort(A, low, pivot - 1);
//         QuickSort(A, pivot + 1, high);
//     }
// }


// void Quicksort(vector<int> arr, int start, int end)
// {
//     int pvot = start;
//     int left = start;
//     int right = end;

//     if (arr.empty() || arr.size() < 2) return;
//     if (left > right) return;

//     while (left < right)
//     {
//         while ( (left < right) && (arr[right] >= arr[pvot])) right--;
//         while ( (left < right) && (arr[left] <= arr[pvot])) left++;
//         if (left < right)
//         {
//             int tmp = arr[right];
//             arr[right] = arr[left];
//             arr[left] = tmp;
//         }
//         else
//         {
//             int tmp = arr[right];
//             arr[right] = arr[pvot];
//             arr[pvot] = tmp;
//         }
//     }
//     Quicksort(arr, start, left - 1);
//     Quicksort(arr, right + 1, end);
// }

class Solution
{
    int partition(vector<int>& nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = 1; j <= r - 1; ++j)
        {
            if (nums[j] <= pivot)
            {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r)
    {
        int i = rand() % (r - l + 1) + 1;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r)
    {
        if (l < r)
        {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums)
    {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
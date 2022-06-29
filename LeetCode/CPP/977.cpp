#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& A)
    {
        int i = 0;
        int j = A.size() - 1;
        vector<int> result (A.size(), 0);
        int k = result.size() - 1;
        for (int i = 0; i < A.size(); i++)
        {
            A[i] = A[i] * A[i];
        }

        while (i <= j)
        {
            if (A[i] < A[j])
            {
                result[k] = A[j];
                j--;
                k--;
            }
            else
            {
                result[k] = A[i];
                i++;
                k--;
            }
        }
        return result;
    };
};
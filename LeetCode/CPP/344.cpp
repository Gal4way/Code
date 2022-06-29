#include <vector>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        auto front = s.begin();
        auto end = s.end();
        end--;
        while (front < end)
        {
            char tmp = *front;
            *front = *end;
            *end = tmp;
            front++;
            end--;
        }
    }
};
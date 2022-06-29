#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int left = 0;
        int right = 10;
        vector<string> answer;
        unordered_map<string ,int> record;

        while (right <= s.size())
        {
            record[s.substr(left, right - left)]++;
            left++;
            right++;
        }

        for (auto a: record)
        {
            if (a.second > 1)
            {
                answer.push_back(a.first);
            }
        }

        return answer;
    }
};
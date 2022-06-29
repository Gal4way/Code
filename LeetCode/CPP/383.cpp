#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) 
//     {
//         unordered_map<char, int> nums;
//         for (char i : magazine)
//         {
//             nums[i]++;
//         }

//         for (char i : ransomNote)
//         {
//             if (nums[i] == 0) return false;
//             nums[i]--;
//         }
//         return true;
//     }
// };

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int record[26] = {0};
        for (int i = 0; i < magazine.length(); i++)
        {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++)
        {
            record[ransomNote[j]-'a']--;
            if (record[ransomNote[j]-'a'] < 0) return false;
        }
        return true;
    }
};
#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
    unordered_map<int, int> map1 = {{1,1},{2,2}};
    unordered_map<int, int>::value_type value1 = {3, 3};
    map1.insert(value1);
    map1[7] = 0;
    map1[5] = 5;

    for (unordered_map<int, int>::iterator i = map1.begin(); i != map1.end(); i++)
    {
        cout<<i->first<<"   "<<i->second<<endl;
    }
}
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<string> myset;

    cout<<myset.size()<<endl;

    myset.insert("1");
    myset.insert("2");
    cout<<myset.size()<<endl;
    
    for (auto iter = myset.begin(); iter != myset.end(); ++iter)
    {
        cout<<*iter<<endl;
    }
    return 0;

}
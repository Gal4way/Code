#include <cstring>
#include <iostream>
using namespace std;

void test1(char* a)
{
    a[3] = '4';
}


int main()
{
    char testString [5]= "123";
    test1(testString);
    cout << testString << endl;

}
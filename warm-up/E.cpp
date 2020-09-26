

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int a = 0, b = 0;
    cout << "Enter a" << endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;

    int i = 0;
    int result = b & ((a-b) >> 31)   |   a & (~(a-b) >> 31); // если a-b отриц то (a-b)>>31 =111111. иначе (a-b)>>31=0000000

    cout<<result;
    return 0;
}
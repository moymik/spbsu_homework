#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x = 0;
    cout << "Enter x";
    cin >> x;
/*
 * a + b = x
 * b = x - a
 * (x - a) * a = x
 * x * a - a^2 = x
 * a^2 -x*a -x = 0
 * d = x^2 + 4x
 * a = (x +-sqrt d) /2
 *
 */
    double a1, b1, a2, b2;
    double d = x*x + 4*x;
    a1 = (x + sqrt(d))/2;
    b1 = x-a1;
    a2 = (x - sqrt(d))/2;
    b2 = x-a2;
    if(a1 != a2 && b1 != b2) {
    cout<< "a1 =" << a1 << "b1 ="<< b1;
    cout<< "a2 =" << a1 << "b2 ="<< b1;
    }
    else  cout<< "a =" << a1 << "b ="<< b1;
}
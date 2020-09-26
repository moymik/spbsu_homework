#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int main()
{
    int x = 0;
    cout << "Enter x : ";
    cin >> x;

    bool isXPrime = false;
    if (x % 2 != 0) {
        isXPrime = true;
        int border = pow(float(x), 0.5) + 1;
        set <int> primes{2};
        for (int i = 3; i < border && isXPrime; ++i) {
            bool isPrime = true;
            for (set <int> :: iterator it = primes.begin(); isPrime && it != primes.end(); ++it) {
                if (i % *it == 0)
                    isPrime = false;
            }
            if (isPrime) {
                if (x % i == 0)
                    isXPrime = false;
                primes.insert(i);
            }
        }
    }

    if (isXPrime)
        cout << "1";
    else {
        if (x % 2 == 0)
            cout << "2";
        else
            cout << "3";
    }
}

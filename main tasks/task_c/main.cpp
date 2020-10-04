#include <iostream>
#include <string.h>

using namespace std;

int countPartitions(int n, int k) {
    if (k > n) return countPartitions(n, n);
    if (k == 0 && n == 0) return 1;
    if (n != 0 && k == 0) return 0;
    return countPartitions(n - k, k) + countPartitions(n, k - 1);
};

int main() {
    int n = 0, k = 0;
    cout << "Input n:" << endl;
    cin >> n;
    cout << "Input k:" << endl;
    cin >> k;
    cout << "Number of partitions = " << countPartitions(n,k);
}

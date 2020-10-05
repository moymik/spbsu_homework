#include <iostream>
#include <string.h>

using namespace std;
/*
 * P(n,k)=
 * {
 * P(n, k-1) + P(n - k, k)     (k <= n)
 * P(n, n)  (k>n)
 * 0    (n != 0, k = 0)
 * 1    (n = 0, k = 0)
 * }
 */
unsigned long long countPartitions(int n, int k) {
    unsigned long long **counters = new unsigned long long *[n + 1];
    for (int i = 0; i < n + 1; ++i)
        counters[i] = new unsigned long long[k + 1];
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            counters[i][j] = 0;
        }
    }

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            if (j == 0) {
                if (i == 0) {
                    counters[i][j] = 1;
                }
            } else {
                if (j > i) {
                    counters[i][j] = counters[i][i];
                } else {
                    counters[i][j] = counters[i - j][j] + counters[i][j - 1];
                }
            }
        }
    }
    unsigned long long result;
    result = counters[n][k];
    for (int i = 0; i < n + 1; ++i)
        delete[] counters[i];
    delete[] counters;
    return result;
};

int main() {
    int n = 0, k = 0;
    cout << "Input n:" << endl;
    cin >> n;
    cout << "Input k:" << endl;
    cin >> k;


    cout << "Number of partitions = " << countPartitions(n, k);
}

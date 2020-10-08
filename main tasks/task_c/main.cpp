#include <iostream>
#include <ctime>

using namespace std;


int countPartitionsIterative(int n, int k)
{
    unsigned long long** partitionsCounters = new unsigned long long*[n + 1];
    for (int i = 0; i < n + 1; ++i)
        partitionsCounters[i] = new unsigned long long[k + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {

            if (i == 0 && j == 0) {
                partitionsCounters[i][j] = 1;
            } else if (j == 0) {
                partitionsCounters[i][j] = 0;
            } else if (j > i) {
                partitionsCounters[i][j] = partitionsCounters[i][i];
            } else {
                partitionsCounters[i][j] = partitionsCounters[i][j - 1] + partitionsCounters[i - j][j];
            }
        }
    }
    unsigned long long counter = partitionsCounters[n][k];

    for (int i = 0; i < n; ++i)
        delete[] partitionsCounters[i];
    delete[] partitionsCounters;

    return counter;
}

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
    unsigned long long startTime = clock();
    cout << "Number of partitions(recursive) = " << countPartitions(n,k);
    unsigned long long endTime = clock();
    cout << endl << "Time: " << endTime - startTime << endl;

    startTime = clock();
    cout << "Number of partitions(iterative) = " << countPartitionsIterative(n, k);
    endTime = clock();
    cout << endl << "Time: " << endTime - startTime << endl;
}

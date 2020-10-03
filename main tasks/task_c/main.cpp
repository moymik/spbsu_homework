#include <iostream>
#include <string.h>

using namespace std;


int main() {
    int n = 0, k = 0;
    cout << "Input n:" << endl;
    cin >> n;
    cout << "Input k:" << endl;
    cin >> k;
    int *partitionsCounters = new int[n + 1];
    memset(partitionsCounters, 0, sizeof(int) * (n + 1));


    partitionsCounters[0] = partitionsCounters[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        for (int j = 1; j < k && i - j > 0 && j <= i - j; ++j) {
            partitionsCounters[i] += partitionsCounters[i - j];
        }
        ++partitionsCounters[i];
    }
    for(int i = 0; i < n + 1; i++)
        cout <<" " << partitionsCounters[i];

}

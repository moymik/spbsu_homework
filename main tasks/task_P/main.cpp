#include <iostream>

using namespace std;

int main() {
    int x = 1;
    unsigned char *b = (unsigned char *) &x;
    if (b[0] == 1) cout << "Little endian";//если первый байт равен 1
    else {
        if (b[3] == 1)cout << "Big endian";//если последний байт равен 1
        else cout << "Mixed endian";
    }
    return 0;
}
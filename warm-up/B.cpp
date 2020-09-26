#include <iostream>
using namespace std;
int main()
{
    int size = 0;

    cout << "Enter array size";
    cin >> size;

    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "enter a[" << i << "]";
        cin >> array[i];
    }

    int result=0;

    for (int i = 0; i < size; i++)
    {
        if(result < array[i]) result = array[i];
    }

    cout <<"result: " << result;

    return 0;
}

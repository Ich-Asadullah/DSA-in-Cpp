#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
            break;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {3, 2, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int val = linearSearch(arr, size, 5);
    cout << "Key found at index: " << val << endl;
}
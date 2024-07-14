#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int val = binarySearch(arr, size, 11);
    cout << "Key found at index: " << val << endl;
}
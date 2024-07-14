#include <iostream>
using namespace std;
// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to implement insertion sort
void insertionSort(int arr[], int n)
{
    for (int i = 1  ; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than ,
        // to one position ahead of their current  position
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
        // printArray(arr, n);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}

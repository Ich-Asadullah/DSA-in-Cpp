#include <iostream>
using namespace std;

class MinHeap {
private:
    int *heapArray;
    int capacity;
    int size;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index > 0 && heapArray[parent(index)] > heapArray[index]) {
            swap(heapArray[parent(index)], heapArray[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int minIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heapArray[left] < heapArray[minIndex])
            minIndex = left;
        if (right < size && heapArray[right] < heapArray[minIndex])
            minIndex = right;

        if (minIndex != index) {
            swap(heapArray[minIndex], heapArray[index]);
            heapifyDown(minIndex);
        }
    }

public:
    MinHeap(int capacity) : capacity(capacity), size(0) {
        heapArray = new int[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        heapArray[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    int extractMin() {
        if (size == 0) {
            cerr << "Heap is empty!" << endl;
            return -1;
        }

        int min = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifyDown(0);

        return min;
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Min Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap(10);

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(14);
    minHeap.insert(50);
    minHeap.insert(17);
    minHeap.insert(40);

    minHeap.display();

    int max = minHeap.extractMin();
    if (max != -1) {
        cout << "Extracted min value: " << max << endl;
        minHeap.display();
    }

    return 0;
}
